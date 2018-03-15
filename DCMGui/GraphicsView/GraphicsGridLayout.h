#ifndef _DSGUI_GRAPHICSGRIDLAYOUT_H
#define _DSGUI_GRAPHICSGRIDLAYOUT_H

#include "GraphicsLayout.h"

namespace DSGUI
{
    class DSPictureBrowser;
    // ����Ԫ��
    class DS_GUI_EXPORT DSGraphicsGridLayout : public DSGraphicsLayout
	{
        Q_OBJECT
	public:
		// ����
        DSGraphicsGridLayout(DSPictureBrowser* pParent);

    public:
        // ���QGraphicsItem,���ʧ�ܷ���-1
        virtual int AddItem(QGraphicsItem* pItem);
        // ����QGraphicsItem,���ʧ�ܷ���-1
        virtual int InsertItem(int iIndex, QGraphicsItem* pItem);
        // ���㷵�ص�iIndex��QGraphicsItem��������б����Ƴ�
        virtual QGraphicsItem* ItemAt(int iIndex) const;
        // ȡ����iIndex��QGraphicsItem������б����Ƴ�
        virtual QGraphicsItem* TakeAt(int iIndex);
        // ��������
        virtual int IndexOfItem(QGraphicsItem* pItem) const;
        // ��ȡQGraphicsItem����
        virtual int GetItemCount() const;
        // ��ȡ����QGraphicsItem
        virtual QList<QGraphicsItem*> GetItems() const;
        // ����λ��
        virtual bool SwapItem(int iSource, int iTarget);
		// �����iIndex��QGraphicsItem��λ��
		virtual QRectF ActualItemRect(int iIndex);
    public:
        // ���²���
        virtual void ReLayout();
    private:
        QGraphicsView* m_pGraphicsView;
        QList<QGraphicsItem*> m_listItems;
	};
}

#endif
