/*
 *@file   IconProvider.h
 *@brief  ͼ���ṩ��
 * 
 *@author cc
 *@date   2014-07-18
 *
 */

#ifndef __DSGUI_ICONPROVIDER_H
#define __DSGUI_ICONPROVIDER_H

#include "DSGuiGlobal.h"
#include <QIcon>

namespace DSGUI
{
	/** @class DSIconProvider
	  * @brief ��װ�����ļ�ͼ���ȡ
	  */
	class DS_GUI_EXPORT DSIconProvider
	{
	public:
        // ��ȡָ��·��ͼ��,����Ϊ����·��
        static QIcon GetIcon(const QString& strFilePath);
	};
}

#endif
