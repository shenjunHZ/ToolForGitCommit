#ifndef _DSGUI_GRAPHICSHITEMLAYOUT_H
#define _DSGUI_GRAPHICSHITEMLAYOUT_H

#include "GraphicsLayout.h"

namespace DSGUI
{
    class DSPictureBrowser;
    // ����Ԫ��
    class DS_GUI_EXPORT DSGraphicsHorLayout : public DSGraphicsLayout
	{
        Q_OBJECT
    public:
        enum LayoutDirection
        {
            LeftToRight = 0,
            RightToLeft = 1,
        };
	public:
		// ����
        DSGraphicsHorLayout(LayoutDirection enumLayout, DSPictureBrowser* pParent);
        ~DSGraphicsHorLayout();

    public:
        // ���QGraphicsItem,���ʧ�ܷ���-1
        virtual int AddItem(QGraphicsItem* pItem);
        // ����QGraphicsItem,���ʧ�ܷ���-1
        virtual int InsertItem(int iIndex, QGraphicsItem* pItem);
        // ���㷵�ص�iIndex��QGraphicsItem��������б����Ƴ�
        virtual QGraphicsItem* ItemAt(int iIndex) const;
        // ����Ϊ�����ĵ����λ��
        virtual QGraphicsItem* ItemAt(const QPointF& ptPos) const;
        // ȡ����iIndex��QGraphicsItem������б����Ƴ�
        virtual QGraphicsItem* TakeAt(int iIndex);
        // ��������
        virtual int IndexOfItem(QGraphicsItem* pItem) const;
        // ��ȡQGraphicsItem����
        virtual int GetItemCount() const;
        // ��ȡ����QGraphicsItem
        virtual QList<QGraphicsItem*> GetItems() const ;
        // ����λ��
        virtual bool SwapItem(int iSource, int iTarget);
		// �����iIndex��QGraphicsItem��λ��
		virtual QRectF ActualItemRect(int iIndex);
    public:
        // �����Զ��ƶ��Ƿ�����Ĭ�Ͽ���
        void SetOpenAutoMoveEnable(bool bOpen);
        // ���õ����ƶ���С
        void SetSingleStep(int iSingleStep);
        // ����
        void MoveLeft();
        // ����
        void MoveRight();
    public:
        // ���²���
        virtual void ReLayout();

    private slots:
        // ѡ�иı䣬�����Ƿ��Զ��ƶ�
        void OnClickedItem(QGraphicsItem* pItem);
        // ֵ�ı�
        void OnSliderReleased();
    private:
        QGraphicsView* m_pGraphicsView;
        LayoutDirection m_enumLayoutDirection; // ���ַ�ʽ
        QList<QGraphicsItem*> m_listItems;
        int m_iSingleStep;
        bool m_bOpenMove; // �Ƿ���ƶ�
        bool m_bCanMove;  // �Ƿ�����ƶ�
	};
}

#endif
