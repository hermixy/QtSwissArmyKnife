﻿/*
 * Copyright (C) 2020 wuuhii. All rights reserved.
 *
 * The file is encoding with utf-8 (with BOM). It is a part of QtSwissArmyKnife
 * project. The project is a open source project, you can get the source from:
 *     https://github.com/wuuhii/QtSwissArmyKnife
 *     https://gitee.com/wuuhii/QtSwissArmyKnife
 *
 * For more information about the project, please join our QQ group(952218522).
 * In addition, the email address of the project author is wuuhii@outlook.com.
 */
#ifndef SAKDEBUGGER_HH
#define SAKDEBUGGER_HH

#include <QObject>

class SAKCRCInterface;
class SAKDebuggerDevice;
class SAKDebuggerInputManager;
class SAKDebuggerDeviceSerialport;
class SAKDebugger : public QObject
{
    Q_OBJECT
    Q_PROPERTY(SAKDebuggerDevice* device READ device NOTIFY deviceChanged)
    Q_PROPERTY(SAKDebuggerInputManager* inputManager READ inputManager CONSTANT)
public:
    enum SAKDebuggertype {
        DebuggerTypeSerialport,
        DebuggerTypeUDP,
        DebuggerTypeTcpClient,
        DebuggerTypeTcpServer
    };
    Q_ENUM(SAKDebuggertype)

    SAKDebugger(int type, QObject *parent = Q_NULLPTR);
    ~SAKDebugger();
private:
    int debuggerType;
    SAKCRCInterface *crcInterface;
private:
    SAKDebuggerDevice *_device;
    SAKDebuggerDevice *device();

    SAKDebuggerInputManager *_inputManager;
    SAKDebuggerInputManager *inputManager();
signals:
    void deviceChanged();
};

#endif
