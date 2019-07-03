/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtNetwork module of the Qt Toolkit.
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

#ifndef QNETWORKACCESSDEBUGPIPEBACKEND_P_H
#define QNETWORKACCESSDEBUGPIPEBACKEND_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of the Network Access API.  This header file may change from
// version to version without notice, or even be removed.
//
// We mean it.
//

#include "qnetworkaccessbackend_p.h"
#include "qnetworkrequest.h"
#include "qnetworkreply.h"
#include "qtcpsocket.h"

QT_BEGIN_NAMESPACE

#ifdef QT_BUILD_INTERNAL

class QNetworkAccessDebugPipeBackend: public QNetworkAccessBackend
{
    Q_OBJECT
public:
    QNetworkAccessDebugPipeBackend();
    virtual ~QNetworkAccessDebugPipeBackend();

    virtual void open();
    virtual void closeDownstreamChannel();
    virtual bool waitForDownstreamReadyRead(int msecs);

    virtual void downstreamReadyWrite();

protected:
    void pushFromSocketToDownstream();
    void pushFromUpstreamToSocket();
    void possiblyFinish();
    QNonContiguousByteDevice *uploadByteDevice;

private slots:
    void uploadReadyReadSlot();
    void socketReadyRead();
    void socketBytesWritten(qint64 bytes);
    void socketError();
    void socketDisconnected();
    void socketConnected();

private:
    QTcpSocket socket;
    bool bareProtocol;
    bool hasUploadFinished;
    bool hasDownloadFinished;
    bool hasEverythingFinished;

    qint64 bytesDownloaded;
    qint64 bytesUploaded;
};

class QNetworkAccessDebugPipeBackendFactory: public QNetworkAccessBackendFactory
{
public:
    virtual QNetworkAccessBackend *create(QNetworkAccessManager::Operation op,
                                          const QNetworkRequest &request) const;
};

#endif  // QT_BUILD_INTERNAL

QT_END_NAMESPACE

#endif
