/*
 *@file   TableView.h
 *@brief  ���ؼ�
 * 
 *@author 
 *@date   2014-05-27
 *
 */

#ifndef _DSGUI_TABLEVIEW_H
#define _DSGUI_TABLEVIEW_H

#include "TableView/BaseView.h"

namespace DSGUI
{
	class DS_GUI_EXPORT DSTableView : public DSBaseView
	{
		Q_OBJECT
	public:
		DSTableView(QWidget* pParent = NULL);

	protected:
        // ���༭����ʱ����굥���ᴥ��˫��Ч��
		virtual bool edit(const QModelIndex& miIndex, EditTrigger enumTrigger, QEvent* pEvent);
	};

}

#endif
