#ifndef _DSGUI_LISTVIEW_H
#define _DSGUI_LISTVIEW_H

#include <QtGui/QListView>

namespace DSGUI
{
	/**  ������DSListView
	*    ˵�� �����б�ؼ�
	**/
	class DSListView : public QListView
	{
		Q_OBJECT
	public:
		// ����
		DSListView(QWidget* pParent = NULL);
	};
}

#endif //_DSGUI_LISTVIEW_H
