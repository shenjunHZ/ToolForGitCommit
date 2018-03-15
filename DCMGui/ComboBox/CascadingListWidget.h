/*
 *@file   CascadingListWidget.h
 *@brief  ���������б���Ͽ򵯳��ؼ���
 * 
 *@author 28100
 *@date   2017-01-23
 *
 */
#ifndef _DSGUI_CASCADINGLISTWIDGET_H
#define _DSGUI_CASCADINGLISTWIDGET_H

#include "DSGuiGlobal.h"
#include "ComboBoxPopupContainer.h"
#include "ListWidget/ListWidget.h"
#include "TableView/BaseViewItemDelegate.h"

namespace DSGUI
{
	class DS_GUI_EXPORT DSCascadingListWidget : public DSComboBoxPopupContainer
	{
		enum ItemDataRole {
			MainListDateRole = Qt::UserRole + 1,
			CascadingListRole = Qt::UserRole + 2,
		};
		Q_OBJECT

	public:
		DSCascadingListWidget(QWidget *parent = NULL);
		~DSCascadingListWidget();

		void InitDate(QMap<int, QString> mapMainListData, QMap<int, QMap<int, QString> > mapCascadingRelation);

		const QMap<int, QString>* GetCascadingMapByMainListItem(int nMainlistItemValue);
		void SetCascadingListVisible(bool bVisible);
		void AdjustListSize();

	signals:
		void SignalMainListItemClicked(int nItemValue, QString strItemName);
		void SignalCascadingListItemClicked(int nItemValue, QString strItemName);
		void SignalCascadingListVisibleChange(bool bVisible);

	protected slots:
		void OnMainListItemEnter(QListWidgetItem* pItem);
		void OnMainListItemClicked(QListWidgetItem* pItem);
		void OnCascadingListItemClicked(QListWidgetItem* pItem);

	private:
		DSListWidget* m_pMainList;			//��һ���б�
		DSListWidget* m_pCascadingList;		//�ڶ����б�
		
		QMap<int, QString> m_mapMainListData;					//��һ���б�����
		QMap<int, QMap<int, QString> > m_mapCascadingRelation;	//һ���б�������������� ��ϵ��ϱ�Key��һ�����ݼ�ֵ Value: һ�����ݶ�Ӧ�Ķ���������ϣ�
		int			  m_pItemHeight;
	};
}

#endif // _DSGUI_CASCADINGLISTWIDGET_H
