#ifndef _DSGUI_GRAPHICSITEMLAYOUT_H
#define _DSGUI_GRAPHICSITEMLAYOUT_H

#include "DSGuiGlobal.h"
#include <QGraphicsView>

namespace DSGUI
{
    // ����Ԫ��
    class DS_GUI_EXPORT DSGraphicsLayout : public QObject
	{
        Q_OBJECT
	public:
		// ����
        DSGraphicsLayout(QGraphicsView* pParent = NULL);
        ~DSGraphicsLayout();

    public:
        // ���QGraphicsItem,���ʧ�ܷ���-1
        virtual int AddItem(QGraphicsItem* pItem) = 0;
        // ����QGraphicsItem,���ʧ�ܷ���-1
        virtual int InsertItem(int iIndex, QGraphicsItem* pItem) = 0;
        // ���㷵�ص�iIndex��QGraphicsItem��������б����Ƴ�
        virtual QGraphicsItem* ItemAt(int iIndex) const = 0;
        // ȡ����iIndex��QGraphicsItem������б����Ƴ�
        virtual QGraphicsItem* TakeAt(int iIndex) = 0;
        // ��������
        virtual int IndexOfItem(QGraphicsItem* pItem) const = 0;
        // ��ȡQGraphicsItem����
        virtual int GetItemCount() const = 0;
        // ��ȡ����QGraphicsItem
        virtual QList<QGraphicsItem*> GetItems() const = 0;
        // ����λ��
        virtual bool SwapItem(int iSource, int iTarget) = 0;
		// �����iIndex��QGraphicsItem��λ��
		virtual QRectF ActualItemRect(int iIndex) = 0;
    public:
        // ���ú�����
        void SetHorizontalSpacing(int iSpacing);
        // ��ȡ������
        int GetHorizontalSpacing() const;
        // ���ú�����
        void SetVerticalSpacing(int iSpacing);
        // ��ȡ������
        int GetVerticalSpacing() const;

        // ���ñ�Ե���
        void SetScenceMargins(int iLeft, int iTop, int iRight, int iBottom);
        void SetScenceMargins(const QMargins& margins);
        // ��ȡ��Ե���
        void GetScenceMargins(int* pLeft, int* pTop, int* pRight, int* pBottom) const;
        QMargins GetScenceMargins() const;
    public:
        // ���²���
        virtual void ReLayout() = 0;
    protected:
        int m_iHSpacing;
        int m_iVSpacing;
        int m_iLeftMargin;
        int m_iTopMargin;
        int m_iRightMargin;
        int m_iBottomMargin;
	};
}

#endif
