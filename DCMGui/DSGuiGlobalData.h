/*
 * @file	DSGuiGlobalData.h
 * @note	Technology Co., Ltd. All Rights Reserved 
 * @brief	DSGUI ȫ������
 * @author	JCL 
 * @date	2015-8-25
 * 
 * @note 
 * @note 
 */
#ifndef __DSGUI_GLOBALDATA_H
#define __DSGUI_GLOBALDATA_H

#include "DSGuiGlobal.h"
#include <QString>

namespace DSGUI
{
	//����Ƥ��·�� (strFileName Ƥ���ļ�������)
	extern void SetSkinVersion(QString& strFileName);

	//��ȡ��������·��
	extern QString GetSkinVersion();
}
#endif

