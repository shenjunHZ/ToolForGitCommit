/*
 *@file   DSFile.h
 *@brief  ��װ�����ļ���������
 * 
 *@author cc
 *@date   2014-06-12
 *
 */

#ifndef __DSGUI_FILE_H
#define __DSGUI_FILE_H

#include "DSGuiGlobal.h"
#include <QString>

namespace DSGUI
{
	/** @class DSFile
	  * @brief ��װ�����ļ���������
	  */
	class DS_GUI_EXPORT DSFile
	{
	public:
        // ��ȡ�����ļ��������ַ�
        static QByteArray ReadAll(const QString& strFile, const QString& strFilePath = QString());

        // ��ȡ�ļ��б��������ַ�
        static QByteArray ReadAll(const QStringList& strListFile, const QString& strFilePath = QString());
	};
}

#endif
