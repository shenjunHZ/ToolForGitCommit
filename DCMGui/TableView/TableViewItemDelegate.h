/*
 *@file   TableViewItemDelegate.h
 *@brief  
 * 
 *@author 
 *@date   2014-05-28
 *
 */

#ifndef __DS_TABLEVIEWITEMDELEGATE_H
#define __DS_TABLEVIEWITEMDELEGATE_H

#include "TableView/BaseViewItemDelegate.h"

namespace DSGUI
{
	class DS_GUI_EXPORT DSTableViewItemDelegate : public DSBaseViewItemDelegate
	{
		Q_OBJECT

	public:
        DSTableViewItemDelegate(QObject* pParent);

    public:
        // ��ͼ
        virtual void paint(QPainter* pPainter, const QStyleOptionViewItem& optionItem, const QModelIndex& miItem) const;

    public:
		// �༭״̬�������ؼ�
		virtual QWidget* createEditor(QWidget* pParent, const QStyleOptionViewItem& optionItem, const QModelIndex& miItem) const;

		// ���༭״̬�´����Ŀؼ���������
		virtual void setEditorData(QWidget *pEditor, const QModelIndex& miItem) const;

		// ����ͼ��������
		virtual void setModelData(QWidget *pEditor, QAbstractItemModel *pModel, const QModelIndex& miItem) const;

		// �༭״̬�¿ؼ�λ��
		virtual void updateEditorGeometry(QWidget *pEditor, const QStyleOptionViewItem& optionItem, const QModelIndex& miItem) const;

	public:
		// ����ͼƬ���
		void SetPixmapSpace(int nSpace);

		// ����ͼƬ�߾�
		void SetPixmapMargin(int nMargin);
	signals:
		// �༭���,���ݸı�
		void SignalEditorDataChanged(const QModelIndex& miItem) const;

    protected:
        // ͼƬ���з�ʽ
        virtual Qt::Alignment GetMousePixmapAlignment(const QStyleOptionViewItem& optionItem, const QModelIndex& miItem) const;

        // ����������λ��
        virtual struTreeViewData::DSItemDataRole CheckMouse(const QPoint& ptMouse, const QStyleOptionViewItem& optionItem, const QModelIndex& miItem) const;

        // ��ȡͼƬ����
        // ����1ΪItemPixmapOneRole��ItemPixmapTwoRole��ItemPixmapThreeRole
        // ����4ָͼƬ���з�ʽ
        virtual QRect GetItemPixmapRect(struTreeViewData::DSItemDataRole enumItemDataRole, const QStyleOptionViewItem& optionItem, 
            const QModelIndex& miItem, Qt::Alignment enumAlignment) const;

        // ��ȡͼƬռ�õ�����
        virtual QRect GetAllItemPixmapRect(const QStyleOptionViewItem& optionItem, const QModelIndex& miItem, Qt::Alignment enumAlignment) const;

    public Q_SLOTS:
        // ToolTip�¼�
        bool helpEvent(QHelpEvent* pEvent, QAbstractItemView* pView, const QStyleOptionViewItem& optionItem, const QModelIndex& miItem);
        // hover�¼�
        void hoverEvent(QHoverEvent* pHoverEvent, QAbstractItemView* pView, const QStyleOptionViewItem& optionItem, const QModelIndex& miItem);
        // ����ƶ��¼�
        struTreeViewData::DSItemDataRole mouseEvent(QMouseEvent* pMouseEvent, QAbstractItemView* pView, const QStyleOptionViewItem& optionItem,
            const QModelIndex& miItem);

	protected:
        bool m_bMousePressed; // ��갴��
		int  m_nPixmapSpace;	//ͼƬ���
		int	 m_nPixmapMargin;
	};
}

#endif
