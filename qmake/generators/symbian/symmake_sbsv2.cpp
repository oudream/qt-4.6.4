/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the qmake application of the Qt Toolkit.
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

#include "symmake_sbsv2.h"
#include "initprojectdeploy_symbian.h"

#include <qstring.h>
#include <qstringlist.h>
#include <qdir.h>
#include <qdatetime.h>
#include <qdebug.h>

// Included from tools/shared
#include <symbian/epocroot.h>

SymbianSbsv2MakefileGenerator::SymbianSbsv2MakefileGenerator() : SymbianMakefileGenerator() { }
SymbianSbsv2MakefileGenerator::~SymbianSbsv2MakefileGenerator() { }

#define FLM_DEST_DIR "epoc32/tools/makefile_templates/qt"
#define FLM_SOURCE_DIR "/mkspecs/symbian-sbsv2/flm/qt"

// Copies Qt FLMs to correct location under epocroot.
// This is not done by configure as it is possible to change epocroot after configure.
void SymbianSbsv2MakefileGenerator::exportFlm()
{
    static bool flmExportDone = false;

    if (!flmExportDone) {
        QDir sourceDir = QDir(QLibraryInfo::location(QLibraryInfo::PrefixPath) + FLM_SOURCE_DIR);
        QFileInfoList sourceInfos = sourceDir.entryInfoList(QDir::Files);

        QDir destDir(epocRoot() + FLM_DEST_DIR);
        if (!destDir.exists()) {
            if (destDir.mkpath(destDir.absolutePath()))
                generatedDirs << destDir.absolutePath();
        }

        foreach(QFileInfo item, sourceInfos) {
            QFileInfo destInfo = QFileInfo(destDir.absolutePath() + "/" + item.fileName());
            if (!destInfo.exists() || destInfo.lastModified() != item.lastModified()) {
                if (destInfo.exists())
                    QFile::remove(destInfo.absoluteFilePath());
                if (QFile::copy(item.absoluteFilePath(), destInfo.absoluteFilePath()))
                    generatedFiles << destInfo.absoluteFilePath();
                else
                    fprintf(stderr, "Error: Could not copy '%s' -> '%s'\n",
                            qPrintable(item.absoluteFilePath()),
                            qPrintable(destInfo.absoluteFilePath()));
            }
        }
        flmExportDone = true;
    }
}

void SymbianSbsv2MakefileGenerator::writeSbsDeploymentList(const DeploymentList& depList, QTextStream& t)
{
    for (int i = 0; i < depList.size(); ++i) {
        t << "START EXTENSION qt/qmake_emulator_deployment" << endl;
        QString fromItem = depList.at(i).from;
        QString toItem = depList.at(i).to;
        fromItem.replace("\\", "/");
        toItem.replace("\\", "/");
#if defined(Q_OS_WIN)
        toItem.prepend(QDir::current().absolutePath().left(2)); // add drive
#endif
        t << "OPTION DEPLOY_SOURCE " << fromItem << endl;
        t << "OPTION DEPLOY_TARGET " << toItem << endl;
        t << "END" << endl;
    }
}

void SymbianSbsv2MakefileGenerator::writeMkFile(const QString& wrapperFileName, bool deploymentOnly)
{
    // Can't use extension makefile with sbsv2
    Q_UNUSED(wrapperFileName);
    Q_UNUSED(deploymentOnly);
}

void SymbianSbsv2MakefileGenerator::writeWrapperMakefile(QFile& wrapperFile, bool isPrimaryMakefile)
{
    QStringList allPlatforms;
    foreach(QString platform, project->values("SYMBIAN_PLATFORMS")) {
        allPlatforms << platform.toLower();
    }

    QStringList debugPlatforms = allPlatforms;
    QStringList releasePlatforms = allPlatforms;
    releasePlatforms.removeAll("winscw"); // No release for emulator

    QString testClause;
    if (project->isActiveConfig(SYMBIAN_TEST_CONFIG))
        testClause = QLatin1String(".test");
    else
        testClause = QLatin1String("");

    QTextStream t(&wrapperFile);

    t << "# ==============================================================================" << endl;
    t << "# Generated by qmake (" << qmake_version() << ") (Qt " << QT_VERSION_STR << ") on: ";
    t << QDateTime::currentDateTime().toString() << endl;
    t << "# This file is generated by qmake and should not be modified by the" << endl;
    t << "# user." << endl;
    t << "#  Name        : " << wrapperFile.fileName() << endl;
    t << "#  Description : Wrapper Makefile for calling Symbian build tools" << endl;
    t << "#" << endl;
    t << "# ==============================================================================" << "\n" << endl;
    t << endl;
    t << "MAKEFILE          = " << wrapperFile.fileName() << endl;
    t << "QMAKE             = " << Option::fixPathToTargetOS(var("QMAKE_QMAKE")) << endl;
    t << "DEL_FILE          = " << var("QMAKE_DEL_FILE") << endl;
    t << "DEL_DIR           = " << var("QMAKE_DEL_DIR") << endl;
    t << "CHK_DIR_EXISTS    = " << var("QMAKE_CHK_DIR_EXISTS") << endl;
    t << "MKDIR             = " << var("QMAKE_MKDIR") << endl;
    t << "MOVE              = " << var("QMAKE_MOVE") << endl;
    t << "DEBUG_PLATFORMS   = " << debugPlatforms.join(" ") << endl;
    t << "RELEASE_PLATFORMS = " << releasePlatforms.join(" ") << endl;
    t << "MAKE              = make" << endl;
    t << "SBS               = sbs" << endl;
    t << endl;
    t << "DEFINES" << '\t' << " = "
        << varGlue("PRL_EXPORT_DEFINES","-D"," -D"," ")
        << varGlue("QMAKE_COMPILER_DEFINES", "-D", "-D", " ")
        << varGlue("DEFINES","-D"," -D","") << endl;

    t << "INCPATH" << '\t' << " = ";

    for (QMap<QString, QStringList>::iterator it = systeminclude.begin(); it != systeminclude.end(); ++it) {
        QStringList values = it.value();
        for (int i = 0; i < values.size(); ++i) {
            t << " -I\"" << values.at(i) << "\" ";
        }
    }
    t << endl;
    t << "first: default" << endl;
    if (debugPlatforms.contains("winscw"))
        t << "default: debug-winscw";
    else if (debugPlatforms.contains("armv5"))
        t << "default: debug-armv5";
    else if (debugPlatforms.size())
        t << "default: debug-" << debugPlatforms.first();
    else
        t << "default: all";

    t << endl;
    if (!isPrimaryMakefile) {
        t << "all:" << endl;
    } else {
        t << "all: debug release" << endl;
        t << endl;
        t << "qmake:" << endl;
        t << "\t$(QMAKE) -spec symbian-sbsv2 -o \"" << fileInfo(Option::output.fileName()).fileName()
          << "\" \"" << project->projectFile() << "\"" << endl;
        t << endl;
        t << BLD_INF_FILENAME ":" << endl;
        t << "\t$(QMAKE)" << endl;
        t << endl;

        QString winscw("winscw");
        t << "debug: " << BLD_INF_FILENAME << endl;
        t << "\t$(SBS)";
        foreach(QString item, debugPlatforms) {
            if(QString::compare(item, winscw) == 0)
                t << " -c " << item << "_udeb.mwccinc" << testClause;
            else
                t << " -c " << item << "_udeb" << testClause;
        }
        t << endl;
        t << "release: " << BLD_INF_FILENAME << endl;
        t << "\t$(SBS)";
        foreach(QString item, releasePlatforms) {
            if(QString::compare(item, winscw) == 0)
                t << " -c " << item << "_urel.mwccinc" << testClause;
            else
                t << " -c " << item << "_urel" << testClause;
        }
        t << endl;

        // For more specific builds, targets are in this form: build-platform, e.g. release-armv5
        foreach(QString item, debugPlatforms) {
            t << "debug-" << item << ": " << BLD_INF_FILENAME << endl;
            if(QString::compare(item, winscw) == 0)
                t << "\t$(SBS) -c " << item << "_udeb.mwccinc" << testClause << endl;
            else
                t << "\t$(SBS) -c " << item << "_udeb" << testClause << endl;
        }

        foreach(QString item, releasePlatforms) {
            t << "release-" << item << ": " << BLD_INF_FILENAME << endl;
            if(QString::compare(item, winscw) == 0)
                t << "\t$(SBS) -c " << item << "_urel.mwccinc" << testClause << endl;
            else
                t << "\t$(SBS) -c " << item << "_urel" << testClause << endl;
        }

        t << endl;
        t << "export: " << BLD_INF_FILENAME << endl;
        t << "\t$(SBS) export" << endl;
        t << endl;

        t << "cleanexport: " << BLD_INF_FILENAME << endl;
        t << "\t$(SBS) cleanexport" << endl;
        t << endl;

    }

    // Add all extra targets including extra compiler targest also to wrapper makefile,
    // even though many of them may have already been added to bld.inf as FLMs.
    // This is to enable use of targets like 'mocables', which call targets generated by extra compilers.
    if (targetType != TypeSubdirs) {
        t << extraTargetsCache;
        t << extraCompilersCache;
    } else {
        QList<MakefileGenerator::SubTarget*> subtargets = findSubDirsSubTargets();
        writeSubTargets(t, subtargets, SubTargetSkipDefaultVariables|SubTargetSkipDefaultTargets);
        qDeleteAll(subtargets);
    }

    writeSisTargets(t);

    generateDistcleanTargets(t);

    t << "clean: " << BLD_INF_FILENAME << endl;
    t << "\t-$(SBS) reallyclean" << endl;
    t << endl;

    t << "clean-debug: " << BLD_INF_FILENAME << endl;
    t << "\t$(SBS) reallyclean";
    foreach(QString item, debugPlatforms) {
        t << " -c " << item << "_udeb" << testClause;
    }
    t << endl;
    t << "clean-release: " << BLD_INF_FILENAME << endl;
    t << "\t$(SBS) reallyclean";
    foreach(QString item, releasePlatforms) {
        t << " -c " << item << "_urel" << testClause;
    }
    t << endl;

    // For more specific builds, targets are in this form: clean-build-platform, e.g. clean-release-armv5
    foreach(QString item, debugPlatforms) {
        t << "clean-debug-" << item << ": " << BLD_INF_FILENAME << endl;
        t << "\t$(SBS) reallyclean -c " << item << "_udeb" << testClause << endl;
    }
    foreach(QString item, releasePlatforms) {
        t << "clean-release-" << item << ": " << BLD_INF_FILENAME << endl;
        t << "\t$(SBS) reallyclean -c " << item << "_urel" << testClause << endl;
    }
    t << endl;

    generateExecutionTargets(t, debugPlatforms);
}

void SymbianSbsv2MakefileGenerator::writeBldInfExtensionRulesPart(QTextStream& t, const QString &iconTargetFile)
{
    // Makes sure we have needed FLMs in place.
    exportFlm();

    // Parse extra compilers data
    QStringList defines;
    QStringList incPath;

    defines << varGlue("PRL_EXPORT_DEFINES","-D"," -D"," ")
            << varGlue("QMAKE_COMPILER_DEFINES", "-D", "-D", " ")
            << varGlue("DEFINES","-D"," -D","");
    for (QMap<QString, QStringList>::iterator it = systeminclude.begin(); it != systeminclude.end(); ++it) {
        QStringList values = it.value();
        for (int i = 0; i < values.size(); ++i) {
            incPath << QLatin1String(" -I\"") + values.at(i) + "\"";
        }
    }

    // Write extra compilers and targets to initialize QMAKE_ET_* variables
    // Cache results to avoid duplicate calls when creating wrapper makefile
    QTextStream extraCompilerStream(&extraCompilersCache);
    QTextStream extraTargetStream(&extraTargetsCache);
    writeExtraCompilerTargets(extraCompilerStream);
    writeExtraTargets(extraTargetStream);

    // Figure out everything the target depends on as we don't want to run extra targets that
    // are not necessary.
    QStringList allPreDeps;
    foreach(QString item, project->values("PRE_TARGETDEPS")) {
        // Predeps get mangled in windows, so fix them to more sbsv2 friendly format
#if defined(Q_OS_WIN)
        if (item.mid(1, 1) == ":")
            item = item.mid(0, 1).toUpper().append(item.mid(1)); // Fix drive to uppercase
#endif
        item.replace("\\", "/");
        allPreDeps << escapeDependencyPath(item);
    }

    foreach (QString item, project->values("GENERATED_SOURCES")) {
        allPreDeps.append(fileInfo(item).absoluteFilePath());
    }

    for (QMap<QString, QStringList>::iterator it = sources.begin(); it != sources.end(); ++it) {
        QString currentSourcePath = it.key();
        QStringList values = it.value();
        for (int i = 0; i < values.size(); ++i) {
            QString sourceFile = currentSourcePath + "/" + values.at(i);
            QStringList deps = findDependencies(QDir::toNativeSeparators(sourceFile));
            foreach(QString depItem, deps) {
                appendIfnotExist(allPreDeps, fileInfo(depItem).absoluteFilePath());
            }
        }
    }

    // Write FLM rules for all extra targets and compilers that we depend on to build the target.
    QStringList extraTargets;
    extraTargets << project->values("QMAKE_EXTRA_TARGETS") <<  project->values("QMAKE_EXTRA_COMPILERS");
    foreach(QString item, extraTargets) {
        foreach(QString targetItem, project->values(QLatin1String("QMAKE_INTERNAL_ET_PARSED_TARGETS.") + item)) {
            // Make sure targetpath is absolute
            QString absoluteTarget = fileInfo(targetItem).absoluteFilePath();
            if (allPreDeps.contains(absoluteTarget)) {
                QStringList deps = project->values(QLatin1String("QMAKE_INTERNAL_ET_PARSED_DEPS.") + item + targetItem);
                QString commandItem =  project->values(QLatin1String("QMAKE_INTERNAL_ET_PARSED_CMD.") + item + targetItem).join(" ");


                // Make sure all deps paths are absolute
                QString absoluteDeps;
                foreach (QString depItem, deps) {
                    if (!depItem.isEmpty()) {
                        absoluteDeps.append(fileInfo(depItem).absoluteFilePath());
                        absoluteDeps.append(" ");
                    }
                }

                t << "START EXTENSION qt/qmake_extra_pre_targetdep.export" << endl;
                t << "OPTION PREDEP_TARGET " << absoluteTarget << endl;
                t << "OPTION DEPS " << absoluteDeps << endl;

                if (commandItem.indexOf("$(INCPATH)") != -1)
                    commandItem.replace("$(INCPATH)", incPath.join(" "));
                if (commandItem.indexOf("$(DEFINES)") != -1)
                    commandItem.replace("$(DEFINES)", defines.join(" "));

                // Sbsv2 strips all backslashes (even doubles ones) from option parameters, so just replace them with slashes
                // Problem: If some command actually needs backslashes for something else than dir separator, we are out of luck...
                commandItem.replace("\\", "/");
                t << "OPTION COMMAND " << commandItem << endl;
                t << "END" << endl;
            }
        }
    }

    t << endl;

    // Write deployment rules
    QString remoteTestPath = epocRoot() + QLatin1String("epoc32/winscw/c/private/") + privateDirUid;
    DeploymentList depList;

    //write emulator deployment
    t << "#if defined(WINSCW)" << endl;
    initProjectDeploySymbian(project, depList, remoteTestPath, false,
        QLatin1String(EMULATOR_DEPLOYMENT_PLATFORM), QString(), generatedDirs, generatedFiles);
    writeSbsDeploymentList(depList, t);
    t << "#endif" << endl;

    //write ROM deployment
    remoteTestPath = epocRoot() + QLatin1String("epoc32/data/z/private/") + privateDirUid;
    depList.clear();
    initProjectDeploySymbian(project, depList, remoteTestPath, false,
        QLatin1String(ROM_DEPLOYMENT_PLATFORM), QString(), generatedDirs, generatedFiles);
    writeSbsDeploymentList(depList, t);
    t << endl;

    // Write post link rules
    if (!project->isEmpty("QMAKE_POST_LINK")) {
        t << "START EXTENSION qt/qmake_post_link" << endl;
        t << "OPTION POST_LINK_CMD " << var("QMAKE_POST_LINK") << endl;
        t << "OPTION LINK_TARGET " << removePathSeparators(escapeFilePath(fileFixify(project->first("TARGET"))).append(".").append(getTargetExtension())) << endl;
        t << "END" << endl;
        t << endl;
    }

    // Application icon generation
    QStringList icons = project->values("ICON");
    if (icons.size()) {
        QString icon = icons.first();
        if (icons.size() > 1)
            fprintf(stderr, "Warning: Only first icon specified in ICON variable is used: '%s'.", qPrintable(icon));

        t << "START EXTENSION s60/mifconv" << endl;

        QFileInfo iconInfo = fileInfo(icon);

        QFileInfo bldinf(project->values("MAKEFILE").first());
        QString iconPath = bldinf.dir().relativeFilePath(iconInfo.path());

        QString iconFile = iconInfo.baseName();

        QFileInfo iconTargetInfo = fileInfo(iconTargetFile);
        QString iconTarget = iconTargetInfo.fileName();

        t << "OPTION SOURCES -c32 " << iconFile << endl;
        t << "OPTION SOURCEDIR " << iconPath << endl;
        t << "OPTION TARGETFILE " << iconTarget << endl;
        t << "OPTION SVGENCODINGVERSION 3" << endl; // Compatibility with S60 3.1 devices and up
        t << "END" << endl;
    }

    t << "START EXTENSION qt/qmake_store_build" << endl;
    t << "END" << endl;
    t << endl;

    t << endl;
}

void SymbianSbsv2MakefileGenerator::writeBldInfMkFilePart(QTextStream& t, bool addDeploymentExtension)
{
    // We don't generate extension makefile in sbsb2
    Q_UNUSED(t);
    Q_UNUSED(addDeploymentExtension);
}

void SymbianSbsv2MakefileGenerator::appendAbldTempDirs(QStringList& sysincspaths, QString includepath)
{
    //Do nothing
    Q_UNUSED(sysincspaths);
    Q_UNUSED(includepath);
}
