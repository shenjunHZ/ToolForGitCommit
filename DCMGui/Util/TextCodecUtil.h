/*
 *@file   WidgetUtil.h
 *@brief  ��װ������غ���
 * 
 *@author cc
 *@date   2014-07-01
 *
 */

#ifndef __DSGUI_WIDGETUTIL_H
#define __DSGUI_WIDGETUTIL_H

#include "DSGuiGlobal.h"
#include <QTextCodec>

namespace DSGUI
{
    DS_GUI_EXPORT QString ConvertToUnicode(const char* pStr, const char* pEncodName = "utf-8");

    DS_GUI_EXPORT QByteArray ConvertFromUnicode(const QString& pStr, const char* pEncodName = "utf-8");
}

#endif
