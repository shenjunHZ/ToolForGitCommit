/*
 *@file   DSDir.h
 *@brief  ��װ�����ļ�Ŀ¼����
 * 
 *@author 20753
 *@date   2015-03-17
 *
 */

#ifndef __DSGUI_DIR_H
#define __DSGUI_DIR_H

#include "DSGuiGlobal.h"
#include <QString>

namespace DSGUI
{
	/** @class DSDir
	  * @brief ��װ�����ļ�Ŀ¼����
	  */
	class DS_GUI_EXPORT DSDir
	{
	public:
		//���ó�������·��
		static void SetCurrentPath(QString& strPath);

		//��ȡ��������·��
		static QString GetCurrentPath();

	};
}

#endif
