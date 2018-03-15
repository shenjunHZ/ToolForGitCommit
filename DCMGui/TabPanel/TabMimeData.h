#ifndef __DSGUI_TABMIMEDATA_H__
#define __DSGUI_TABMIMEDATA_H__

#include <QtCore/QMimeData>
#include <QVariant>
#include <QIcon>

namespace DSGUI
{
	typedef struct TabGroup
	{
		QIcon iconTab; //ͼ��
		QString strName; //��ǩ��	
		QString strPluginID; //���id
	}TabGroup_t;

	class TabMimeData : public QMimeData
	{
		Q_OBJECT
	public:
		TabMimeData();
		~TabMimeData();

		QList<TabGroup_t> ItemInfo() const;
		void setItemInfo(const QList<TabGroup_t> &Info);
		bool CombineItem() const;
		void setCombineItem(const bool bCombine);

	private:
		QList<TabGroup_t> m_lsItemInfo;
		bool m_bCombine;
	};
}

#endif
