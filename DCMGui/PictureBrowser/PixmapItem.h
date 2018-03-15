/*
 *@file   PixmapItem.h
 *@brief  
 * 
 *@author cc
 *@date   2014-06-23
 *
 */

#ifndef _DSGUI_PIXMAPITEM_H
#define _DSGUI_PIXMAPITEM_H

#include "DSGuiGlobal.h"
#include <QtGui/QGraphicsPixmapItem>

namespace DSGUI
{
    // ͼƬԪ��
	class DS_GUI_EXPORT DSPixmapItem : public QGraphicsPixmapItem
	{
	public:
		// ����1��ͼƬ ����2��ͼƬ��С
        DSPixmapItem(const QPixmap& pixmap, QSize szPix = QSize(), QGraphicsItem* pParent = NULL);

	};

    // ͼƬԪ�أ�ֻ�ڸ�Ԫ��ѡ��ʱ�����ʾ
    class DS_GUI_EXPORT DSSelectPixmapItem : public QGraphicsPixmapItem
    {
    public:
        // ����
        DSSelectPixmapItem(const QPixmap& pixmap, QGraphicsItem* pParent = NULL);

    public:
        // ��ͼ
        void paint(QPainter* pPainter, const QStyleOptionGraphicsItem *option, QWidget *pWidget );
    };

}

#endif
