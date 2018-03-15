/*
 *@file   DrawUtil.h
 *@brief  ��ͼ��װ
 * 
 *@author cc
 *@date   2014-07-01
 *
 */

#ifndef __DSGUI_DRAWUTIL_H
#define __DSGUI_DRAWUTIL_H

#include <QPainter>

namespace DSGUI
{
    // �Ź��иʽ��ͼ,����ʵ��ͼƬ�Ŵ�
    bool DrawBorderPixmap(QPixmap& pixmapTarget, const QRect& rtTarget, const QMargins& marginsTarget,
        QPixmap& pixmapSource, const QRect& rtSource,const QMargins& marginsSource);
}

#endif
