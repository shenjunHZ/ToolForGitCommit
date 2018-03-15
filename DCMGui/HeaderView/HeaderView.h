/*
 *@file   HeaderView.h
 *@brief  ������ͼ
 * 
 *@author 
 *@date   
 *
 */

#ifndef __DSGUI_HEADERVIEW_H
#define __DSGUI_HEADERVIEW_H

#include "DSGuiGlobal.h"
#include <QtGui/QHeaderView>

namespace DSGUI
{
    class DSHeaderViewPrivate;
	class DS_GUI_EXPORT DSHeaderView : public QHeaderView
	{
		Q_OBJECT
	public:
		DSHeaderView(Qt::Orientation enumOrientation, QWidget* pParent);
        ~DSHeaderView();

    public:
		// ����model
		virtual void setModel(QAbstractItemModel *pModel);

	public:
		// �Ƿ������ͼ��ѡ�Զ��ı�
		void SetAutoChangeCheckbox(bool bAutoChangeCheckbox);

	signals:
		// ������checkbox״̬�ı� ����ͨ��headerDataChanged����ȡ״̬������Qt�ڲ�����Ϣ�������ͼ���²���
		void SignalCheckStateChanged(Qt::CheckState enumCheckState);  

		// ���������
		void SignalHeadClicked(Qt::CheckState enumCheckState);

	protected:
		// ���Ʊ����� ����checkbox
		virtual void paintSection(QPainter* pPainter, const QRect& rtHeader, int iIndex) const;
        // ����Qt�ڲ�������ȱ�ݣ�column�����û������ʱ����0�л��������ַ���ʾ��ȫ
        virtual QSize sectionSizeFromContents(int iLogicalIndex) const;

	private:
		// ����ͷ��¼�
		virtual void mouseReleaseEvent(QMouseEvent* pEvent);

    private:
        QScopedPointer<DSHeaderViewPrivate> d_ptr;

    private:
        Q_DECLARE_PRIVATE(DSHeaderView)
        Q_DISABLE_COPY(DSHeaderView)
        Q_PRIVATE_SLOT(d_func(), void OnDataChanged(const QModelIndex&))
        Q_PRIVATE_SLOT(d_func(), void OnUpdateCheckState())

	};
}

#endif
