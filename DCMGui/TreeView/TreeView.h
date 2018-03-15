/*
 *@file   TreeView.h
 *@brief  
 * 
 *@author cc
 *@date   2014-06-20
 *
 */

#ifndef _DSGUI_TREEVIEW_H
#define _DSGUI_TREEVIEW_H

#include "TableView/BaseView.h"

namespace DSGUI
{
	class DS_GUI_EXPORT DSTreeView : public DSBaseView
	{
		Q_OBJECT
    public:
        /** @enum ExpandState
         *  @brief itemչ������״̬
         */
        enum ExpandState
        {
            AllCollapse,        // ���ж������������ӽڵ㣩
            CollapseAndExpand,  // ����չ���������������ӽڵ㣩
            AllExpand           // ���ж�չ���������ӽڵ㣩
        };
	public:
        // ����
		DSTreeView(QWidget* pParent = NULL);
		~DSTreeView();

    public:
        // ����model
        virtual void setModel(QAbstractItemModel* pModel);

    public:
        // ������ͼcheckbox�Ƿ��Զ��ı�
        void SetAutoChangeCheckbox(bool bAutoChangeCheckbox);

	public:
        // չ�����У��������ӽڵ�
        void ExpandAll(const QModelIndex& miParent);
        // �������У��������ӽڵ�
        void CollapseAll(const QModelIndex& miParent);
		// ��ȡ�����б�չ������״̬,����������ӽڵ�ͷ�����Ч
		bool GetExpandState(ExpandState& enumExpandState, const QModelIndex& miParent = QModelIndex()) const;

	protected slots:
        // ���ݸı�
		virtual void dataChanged(const QModelIndex& miTopLeft, const QModelIndex& miBottomRight);
        // ����checkbox״̬
		void OnUpdateCheckState(const QModelIndex& miIndex);

    private:
        // �����ӽڵ�checkbox״̬
        void UpdateChildCheckState(const QModelIndex& miParent);

    private:
        bool m_bAutoChangeCheckbox; // �Ƿ��Զ��ı乴ѡ״̬
	};
}

#endif //_GUITOOLKIT_TREEVIEW_H
