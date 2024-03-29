/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

/*!
    \since 4.3
    \class QDirIterator
    \brief The QDirIterator class provides an iterator for directory entrylists.

    You can use QDirIterator to navigate entries of a directory one at a time.
    It is similar to QDir::entryList() and QDir::entryInfoList(), but because
    it lists entries one at a time instead of all at once, it scales better
    and is more suitable for large directories. It also supports listing
    directory contents recursively, and following symbolic links. Unlike
    QDir::entryList(), QDirIterator does not support sorting.

    The QDirIterator constructor takes a QDir or a directory as
    argument. After construction, the iterator is located before the first
    directory entry. Here's how to iterate over all the entries sequentially:

    \snippet doc/src/snippets/code/src_corelib_io_qdiriterator.cpp 0

    The next() function returns the path to the next directory entry and
    advances the iterator. You can also call filePath() to get the current
    file path without advancing the iterator.  The fileName() function returns
    only the name of the file, similar to how QDir::entryList() works. You can
    also call fileInfo() to get a QFileInfo for the current entry.

    Unlike Qt's container iterators, QDirIterator is uni-directional (i.e.,
    you cannot iterate directories in reverse order) and does not allow random
    access.

    QDirIterator works with all supported file engines, and is implemented
    using QAbstractFileEngineIterator.

    \sa QDir, QDir::entryList(), QAbstractFileEngineIterator
*/

/*! \enum QDirIterator::IteratorFlag

    This enum describes flags that you can combine to configure the behavior
    of QDirIterator.

    \value NoIteratorFlags The default value, representing no flags. The
    iterator will return entries for the assigned path.

    \value Subdirectories List entries inside all subdirectories as well.

    \value FollowSymlinks When combined with Subdirectories, this flag
    enables iterating through all subdirectories of the assigned path,
    following all symbolic links. Symbolic link loops (e.g., "link" => "." or
    "link" => "..") are automatically detected and ignored.
*/

#include "qdiriterator.h"

#include "qabstractfileengine.h"

#include <QtCore/qset.h>
#include <QtCore/qstack.h>
#include <QtCore/qvariant.h>

QT_BEGIN_NAMESPACE

class QDirIteratorPrivateIteratorStack : public QStack<QAbstractFileEngineIterator *>
{
public:
    ~QDirIteratorPrivateIteratorStack();
};

QDirIteratorPrivateIteratorStack::~QDirIteratorPrivateIteratorStack()
{
    qDeleteAll(*this);
}


class QDirIteratorPrivate
{
public:
    QDirIteratorPrivate(const QString &path, const QStringList &nameFilters,
                        QDir::Filters filters, QDirIterator::IteratorFlags flags);
    ~QDirIteratorPrivate();

    void advance();

    void pushDirectory(const QFileInfo &fileInfo);
    void checkAndPushDirectory(const QFileInfo &);
    bool matchesFilters(const QString &fileName, const QFileInfo &fi) const;

    QScopedPointer<QAbstractFileEngine> engine;

    const QString path;
    const QStringList nameFilters;
    const QDir::Filters filters;
    const QDirIterator::IteratorFlags iteratorFlags;

#ifndef QT_NO_REGEXP
    QVector<QRegExp> nameRegExps;
#endif

    QDirIteratorPrivateIteratorStack fileEngineIterators;
    QFileInfo currentFileInfo;
    QFileInfo nextFileInfo;

    // Loop protection
    QSet<QString> visitedLinks;

    QDirIterator *q;
};

/*!
    \internal
*/
QDirIteratorPrivate::QDirIteratorPrivate(const QString &path, const QStringList &nameFilters,
                                         QDir::Filters filters, QDirIterator::IteratorFlags flags)
    : engine(QAbstractFileEngine::create(path))
      , path(path)
      , nameFilters(nameFilters.contains(QLatin1String("*")) ? QStringList() : nameFilters)
      , filters(QDir::NoFilter == filters ? QDir::AllEntries : filters)
      , iteratorFlags(flags)
{
#ifndef QT_NO_REGEXP
    nameRegExps.reserve(nameFilters.size());
    for (int i = 0; i < nameFilters.size(); ++i)
        nameRegExps.append(
            QRegExp(nameFilters.at(i),
                    (filters & QDir::CaseSensitive) ? Qt::CaseSensitive : Qt::CaseInsensitive,
                    QRegExp::Wildcard));
#endif

    // Populate fields for hasNext() and next()
    pushDirectory(QFileInfo(path));
    advance();
}

/*!
    \internal
*/
QDirIteratorPrivate::~QDirIteratorPrivate()
{
}

/*!
    \internal
*/
void QDirIteratorPrivate::pushDirectory(const QFileInfo &fileInfo)
{
    QString path = fileInfo.filePath();

#ifdef Q_OS_WIN
    if (fileInfo.isSymLink())
        path = fileInfo.canonicalFilePath();
#endif

    if (iteratorFlags & QDirIterator::FollowSymlinks)
        visitedLinks << fileInfo.canonicalFilePath();

    if (engine) {
        engine->setFileName(path);
        QAbstractFileEngineIterator *it = engine->beginEntryList(filters, nameFilters);
        if (it) {
            it->setPath(path);
            fileEngineIterators << it;
        } else {
            // No iterator; no entry list.
        }
    }
}

/*!
    \internal
*/
void QDirIteratorPrivate::advance()
{
    while (!fileEngineIterators.isEmpty()) {

        // Find the next valid iterator that matches the filters.
        while (fileEngineIterators.top()->hasNext()) {
            QAbstractFileEngineIterator *it = fileEngineIterators.top();
            it->next();

            const QFileInfo info = it->currentFileInfo();
            checkAndPushDirectory(it->currentFileInfo());

            if (matchesFilters(it->currentFileName(), info)) {
                currentFileInfo = nextFileInfo;
                nextFileInfo = info;

                //We found a matching entry.
                return;
            }
        }

        delete fileEngineIterators.pop();
    }

    currentFileInfo = nextFileInfo;
    nextFileInfo = QFileInfo();
}

/*!
    \internal
 */
void QDirIteratorPrivate::checkAndPushDirectory(const QFileInfo &fileInfo)
{
    // If we're doing flat iteration, we're done.
    if (!(iteratorFlags & QDirIterator::Subdirectories))
        return;

    // Never follow non-directory entries
    if (!fileInfo.isDir())
        return;

    // Follow symlinks only when asked
    if (!(iteratorFlags & QDirIterator::FollowSymlinks) && fileInfo.isSymLink())
        return;

    // Never follow . and ..
    QString fileName = fileInfo.fileName();
    if (QLatin1String(".") == fileName || QLatin1String("..") == fileName)
        return;

    // No hidden directories unless requested
    if (!(filters & QDir::AllDirs) && !(filters & QDir::Hidden) && fileInfo.isHidden())
        return;

    // Stop link loops
    if (visitedLinks.contains(fileInfo.canonicalFilePath()))
        return;

    pushDirectory(fileInfo);
}

/*!
    \internal

    This convenience function implements the iterator's filtering logics and
    applies then to the current directory entry.

    It returns true if the current entry matches the filters (i.e., the
    current entry will be returned as part of the directory iteration);
    otherwise, false is returned.
*/
bool QDirIteratorPrivate::matchesFilters(const QString &fileName, const QFileInfo &fi) const
{
    Q_ASSERT(!fileName.isEmpty());

    // filter . and ..?
    const int fileNameSize = fileName.size();
    const bool dotOrDotDot = fileName[0] == QLatin1Char('.')
                             && ((fileNameSize == 1)
                                 ||(fileNameSize == 2 && fileName[1] == QLatin1Char('.')));
    if ((filters & QDir::NoDotAndDotDot) && dotOrDotDot)
        return false;

    // name filter
#ifndef QT_NO_REGEXP
    // Pass all entries through name filters, except dirs if the AllDirs
    if (!nameFilters.isEmpty() && !((filters & QDir::AllDirs) && fi.isDir())) {
        bool matched = false;
        for (QVector<QRegExp>::const_iterator iter = nameRegExps.constBegin(),
                                              end = nameRegExps.constEnd();
                iter != end; ++iter) {

            if (iter->exactMatch(fileName)) {
                matched = true;
                break;
            }
        }
        if (!matched)
            return false;
    }
#endif

    // filter hidden
    const bool includeHidden = (filters & QDir::Hidden);
    if (!includeHidden && !dotOrDotDot && fi.isHidden())
        return false;

    // filter system files
    const bool includeSystem = (filters & QDir::System);
    if (!includeSystem && ((!fi.isFile() && !fi.isDir() && !fi.isSymLink())
                    || (!fi.exists() && fi.isSymLink())))
        return false;

    // skip directories
    const bool skipDirs = !(filters & (QDir::Dirs | QDir::AllDirs));
    if (skipDirs && fi.isDir()) {
        if (!((includeHidden && !dotOrDotDot && fi.isHidden())
              || (includeSystem && !fi.exists() && fi.isSymLink())))
            return false;
    }

    // skip files
    const bool skipFiles    = !(filters & QDir::Files);
    const bool skipSymlinks = (filters & QDir::NoSymLinks);
    if ((skipFiles && (fi.isFile() || !fi.exists())) || (skipSymlinks && fi.isSymLink())) {
        if (!((includeHidden && !dotOrDotDot && fi.isHidden())
            || (includeSystem && !fi.exists() && fi.isSymLink())))
            return false;
    }

    // filter permissions
    const bool filterPermissions = ((filters & QDir::PermissionMask)
                                    && (filters & QDir::PermissionMask) != QDir::PermissionMask);
    const bool doWritable = !filterPermissions || (filters & QDir::Writable);
    const bool doExecutable = !filterPermissions || (filters & QDir::Executable);
    const bool doReadable = !filterPermissions || (filters & QDir::Readable);
    if (filterPermissions
        && ((doReadable && !fi.isReadable())
            || (doWritable && !fi.isWritable())
            || (doExecutable && !fi.isExecutable()))) {
        return false;
    }

    return true;
}

/*!
    Constructs a QDirIterator that can iterate over \a dir's entrylist, using
    \a dir's name filters and regular filters. You can pass options via \a
    flags to decide how the directory should be iterated.

    By default, \a flags is NoIteratorFlags, which provides the same behavior
    as in QDir::entryList().

    The sorting in \a dir is ignored.

    \note To list symlinks that point to non existing files, QDir::System must be
     passed to the flags.

    \sa hasNext(), next(), IteratorFlags
*/
QDirIterator::QDirIterator(const QDir &dir, IteratorFlags flags)
    : d(new QDirIteratorPrivate(dir.path(), dir.nameFilters(), dir.filter(), flags))
{
    d->q = this;
}

/*!
    Constructs a QDirIterator that can iterate over \a path, with no name
    filtering and \a filters for entry filtering. You can pass options via \a
    flags to decide how the directory should be iterated.

    By default, \a filters is QDir::NoFilter, and \a flags is NoIteratorFlags,
    which provides the same behavior as in QDir::entryList().

    \note To list symlinks that point to non existing files, QDir::System must be
     passed to the flags.

    \warning This constructor expects \a flags to be left at its default value. Use
             the constructors that do not take the \a filters argument instead.

    \sa hasNext(), next(), IteratorFlags
*/
QDirIterator::QDirIterator(const QString &path, QDir::Filters filters, IteratorFlags flags)
    : d(new QDirIteratorPrivate(path, QStringList(), filters, flags))
{
    d->q = this;
}

/*!
    Constructs a QDirIterator that can iterate over \a path. You can pass
    options via \a flags to decide how the directory should be iterated.

    By default, \a flags is NoIteratorFlags, which provides the same behavior
    as in QDir::entryList().

    \note To list symlinks that point to non existing files, QDir::System must be
     passed to the flags.

    \sa hasNext(), next(), IteratorFlags
*/
QDirIterator::QDirIterator(const QString &path, IteratorFlags flags)
    : d(new QDirIteratorPrivate(path, QStringList(), QDir::NoFilter, flags))
{
    d->q = this;
}

/*!
    Constructs a QDirIterator that can iterate over \a path, using \a
    nameFilters and \a filters. You can pass options via \a flags to decide
    how the directory should be iterated.

    By default, \a flags is NoIteratorFlags, which provides the same behavior
    as QDir::entryList().

    \note To list symlinks that point to non existing files, QDir::System must be
     passed to the flags.

    \warning This constructor expects \c flags to be left at its default value. Use the
             constructors that do not take the \a filters argument instead.

    \sa hasNext(), next(), IteratorFlags
*/
QDirIterator::QDirIterator(const QString &path, const QStringList &nameFilters,
                           QDir::Filters filters, IteratorFlags flags)
    : d(new QDirIteratorPrivate(path, nameFilters, filters, flags))
{
    d->q = this;
}

/*!
    Destroys the QDirIterator.
*/
QDirIterator::~QDirIterator()
{
}

/*!
    Advances the iterator to the next entry, and returns the file path of this
    new entry. If hasNext() returns false, this function does nothing, and
    returns a null QString.

    You can call fileName() or filePath() to get the current entry file name
    or path, or fileInfo() to get a QFileInfo for the current entry.

    \sa hasNext(), fileName(), filePath(), fileInfo()
*/
QString QDirIterator::next()
{
    d->advance();
    return filePath();
}

/*!
    Returns true if there is at least one more entry in the directory;
    otherwise, false is returned.

    \sa next(), fileName(), filePath(), fileInfo()
*/
bool QDirIterator::hasNext() const
{
    return !d->fileEngineIterators.isEmpty();
}

/*!
    Returns the file name for the current directory entry, without the path
    prepended.

    This function is convenient when iterating a single directory. When using
    the QDirIterator::Subdirectories flag, you can use filePath() to get the
    full path.

    \sa filePath(), fileInfo()
*/
QString QDirIterator::fileName() const
{
    return d->currentFileInfo.fileName();
}

/*!
    Returns the full file path for the current directory entry.

    \sa fileInfo(), fileName()
*/
QString QDirIterator::filePath() const
{
    return d->currentFileInfo.filePath();
}

/*!
    Returns a QFileInfo for the current directory entry.

    \sa filePath(), fileName()
*/
QFileInfo QDirIterator::fileInfo() const
{
    return d->currentFileInfo;
}

/*!
    Returns the base directory of the iterator.
*/
QString QDirIterator::path() const
{
    return d->path;
}

QT_END_NAMESPACE
