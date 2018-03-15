#ifndef _DSGUI_GRAPHICSPAGELAYOUT_H
#define _DSGUI_GRAPHICSPAGELAYOUT_H

#include "GraphicsLayout.h"

namespace DSGUI
{
    class DSPictureBrowser;
    // ����Ԫ��
    class DS_GUI_EXPORT DSGraphicsPageLayout : public DSGraphicsLayout
	{
        Q_OBJECT
	public:
		// ����
        DSGraphicsPageLayout(DSPictureBrowser* pParent);

    public:
        // ����һҳ��Ԫ��
        void SetPageCellCount(int iRowCount, int iColCount);
        // ���õ�ǰpageҳ
        void SetCurrentPage(int iIndex);
        // ��ȡ��ǰpageҳ
        int GetCurrentPage() const;
        // ��һҳ
        void NextPage();
        // ��һҳ
        void PrePage();
        // ��ȡ��ǰpageҳ����
        int GetPageCount() const;
		//��ק��ҳ ��һҳ
		void MoveNextPage(int index);
		//��ק��ҳ  ��һҳ
		void MovePrePage(int index);
		//��ȡ��ǰҳ��һ��index
		int GetFirstIndex();
		//��ȡ��ǰҳ���һ��index
		int GetLastIndex();

    public:
        // ���QGraphicsItem,���ʧ�ܷ���-1
        virtual int AddItem(QGraphicsItem* pItem);
        // ����QGraphicsItem,���ʧ�ܷ���-1
        virtual int InsertItem(int iIndex, QGraphicsItem* pItem);
        // ���㷵�ص�iIndex��QGraphicsItem��������б����Ƴ�
        virtual QGraphicsItem* ItemAt(int iIndex) const;
        // ����Ϊ�����ĵ����λ��
        virtual QGraphicsItem* ItemAt(const QPointF& ptPos) const;
		QList<QGraphicsItem*> ItemsAt(const QPointF& ptPos) const;
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
    signals:
        // ��ǰpageҳ�ı�
        void SignalCurrentPageChanged(int iIndex);
        // ��pageҳ�ı�
        void SignalPageCountChanged(int iPageCount);
    public:
        // ���²���
        virtual void ReLayout();

		void MoveReLayout(int index);

    private:
        // ����page����
        void UpdatePageCount();
    private:
        QGraphicsView* m_pGraphicsView;
        QList<QGraphicsItem*> m_listItems;
        int m_iRowCount;
        int m_iColCount;
        int m_iCurrentPage;
        int m_iPageCount;
	};
}

#endif
