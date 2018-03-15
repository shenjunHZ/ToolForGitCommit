#ifndef _DSGUI_ICONBUTTONITEM_H
#define _DSGUI_ICONBUTTONITEM_H

#include "DSGuiGlobal.h"
#include <QGraphicsPixmapItem>

namespace DSGUI
{
    // ��ťͼ��Ԫ�أ���OpenHandCursor״̬
	class DS_GUI_EXPORT DSIconButtonItem : public QObject,
        public QGraphicsPixmapItem
	{
        Q_OBJECT
	public:
		// ����
        DSIconButtonItem(const QPixmap& pixmap, QGraphicsItem *pParent = NULL);

    signals:
        // �����
        void SignalClicked();
    private:
        // ����ͷ�
        virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* pMouseEvent);
        // ��ͼ
        virtual void paint(QPainter *pPainter, const QStyleOptionGraphicsItem *option, QWidget *pWidget = 0);
	};
}

#endif
