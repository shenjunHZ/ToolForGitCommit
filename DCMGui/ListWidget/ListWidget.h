/*
 *@file   DSListWidget.h
 *@brief  
 * 
 *@author cc
 *@date   2014-06-13
 *
 */

#ifndef _GUITOOLKIT_LISTWIDGET_H
#define _GUITOOLKIT_LISTWIDGET_H

#include "DSGuiGlobal.h"
#include <QtGui/QListWidget>

namespace DSGUI
{
	/**  ������CListWidget
	*    ˵�� �����б�ؼ�
	**/
	class DS_GUI_EXPORT DSListWidget : public QListWidget
	{
		Q_OBJECT
	public:
		// ����
		DSListWidget(QWidget* pParent = NULL);
	};
}

#endif //_GUITOOLKIT_LISTWIDGET_H
