/*
 *@file   SystemUtil.h
 *@brief  ��װϵͳ��غ���
 * 
 *@author cc
 *@date   2014-07-01
 *
 */

#ifndef __DSGUI_SYSTEMUTIL_H
#define __DSGUI_SYSTEMUTIL_H

#include "DSGuiGlobal.h"
#include <QtNetWork/QNetworkInterface>

namespace DSGUI
{
    // ���������̵߳ĵȴ��������̵߳���Ϣ���л����ִ�У��迼������ͬ������
    DS_GUI_EXPORT void qWait(int iMs);

    // ���������߳�
    DS_GUI_EXPORT void qSleep(int iMs);

	// ��ȡ����IP
	DS_GUI_EXPORT QString GetLocalIP(QAbstractSocket::NetworkLayerProtocol enumProtocol);
}

#endif
