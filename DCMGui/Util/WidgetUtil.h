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
#include <QtCore/QRectF>

class QWidget;
namespace DSGUI
{
    // ��ȡ���������pFilterClassName�������ڣ�����pWindow��
    DS_GUI_EXPORT QWidget* GetTopWindow(QWidget* pWindow, const char* pFilterClassName = NULL);

    typedef struct StruWindowData
    {
        enum WindowSection
        {
            NoSection,
            LeftSection,
            TopLeftSection,
            TopSection,
            TopRightSection,
            RightSection,
            BottomRightSection,
            BottomSection,
            BottomLeftSection,
            CenterSection 
        };

    }WindowData;

    // ���������ڴ�������
    StruWindowData::WindowSection WindowSectionAt(QRectF rtWidget, QPointF ptPos,
        qreal dLeftMargin, qreal dTopMargin, qreal dRightMargin, qreal dBottomMargin);
}

#endif
