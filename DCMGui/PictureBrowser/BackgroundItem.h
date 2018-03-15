#ifndef _DSGUI_BACKGROUNDITEM_H
#define _DSGUI_BACKGROUNDITEM_H

#include "DSGuiGlobal.h"
#include <QGraphicsRectItem>
#include <QPen>

namespace DSGUI
{
    // ����Ԫ��
	class DS_GUI_EXPORT DSBackgroundItem : public QGraphicsRectItem
	{
	public:
		// ����
        DSBackgroundItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem* pParent = NULL);

    public:
        // ���û���
        void SetSelectedPen(const QPen& pen);
    public:
        // ��ͼ
        virtual void paint(QPainter *pPainter, const QStyleOptionGraphicsItem *option, QWidget *pWidget = 0);

    private:
        QPen m_penSelected;
	};
}

#endif
