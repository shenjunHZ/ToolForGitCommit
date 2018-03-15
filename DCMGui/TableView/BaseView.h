/*
 *@file   BaseView.h
 *@brief  ��ͼ����
 * 
 *@author 
 *@date
 *
 */

#ifndef __DSGUI_BASEVIEW_H
#define __DSGUI_BASEVIEW_H

#include "DSGuiGlobal.h"
#include "ComGUIDef.h"
#include <QTreeView>
#include <QBasicTimer>

namespace DSGUI
{
	class DSBaseViewPrivate;

	class DS_GUI_EXPORT DSBaseView 
        : public QTreeView
	{
		Q_OBJECT

		Q_PROPERTY(QColor msgBoxBottomLineClr READ GetMsgBoxBottomLineColor WRITE SetMsgBoxBottomLineColor)
	public:
		explicit DSBaseView(QWidget* pParent = NULL);
		~DSBaseView();

		// �ź�
    signals:
        // ��װ��ͼ�ϵ��Ի�ͼƬ�ĵ������ ����2��ӦPixmap1Role��Pixmap2Role��Pixmap3Role
        void SignalPixmapClicked(const QModelIndex& miItem, DSGUI::struTreeViewData::DSItemDataRole enumItemRole);

        // ����ͷŷ��ͣ�Ĭ�ϵ�clicked���й�ѡ���ϲ��ᷢ�ͣ�
        void SignalClicked(const QModelIndex& miItem);

    public:
        // ���ú������Ƿ���ʾ
        void SetHorizontalGridVisible(bool bVisible);
        // ���ô�ֱ����Ƿ���ʾ
        void SetVerizontalGridVisible(bool bVisible);

	public:
		// ���ø������ֵ�������п�
		void SetColumnResizeToContents(int iColumn);
		//���õ��ö����ǲ���messagebox
		void SetObjType(bool bIsMsgBox);

	protected:
		// ������
		virtual void drawRow(QPainter* pPainter, const QStyleOptionViewItem& optionItem, const QModelIndex& miItem) const;

    protected:
        // ��ͼ�¼�
        virtual bool viewportEvent(QEvent* pEvent);
		// ��С�ı��¼�
		virtual void resizeEvent(QResizeEvent* pEvent);
		// ����Column��ȣ����������Զ���������ֹƵ�������������������
		virtual void timerEvent(QTimerEvent* pEvent);

	protected Q_SLOTS:
		// �������ؽӿڹ����Զ��������ֵ���column���ʹ��
		virtual void dataChanged(const QModelIndex& miTopLeft, const QModelIndex& miBottomRight);
		virtual void rowsInserted(const QModelIndex& miParent, int iStart, int iEnd);
		virtual void rowsAboutToBeRemoved(const QModelIndex& miParent, int iStart, int iEnd);

	private:
		QScopedPointer<DSBaseViewPrivate> d_ptr;

	private:
		Q_DECLARE_PRIVATE(DSBaseView)
		Q_DISABLE_COPY(DSBaseView)
		Q_PRIVATE_SLOT(d_func(), void OnExpanded(const QModelIndex& index))
		QColor GetMsgBoxBottomLineColor();
		void SetMsgBoxBottomLineColor(const QColor& msgBoxBottomLineClr);
		QColor m_msgBoxBottomLineClr;

		bool m_bIsMsgBox;
	};
}

#endif
