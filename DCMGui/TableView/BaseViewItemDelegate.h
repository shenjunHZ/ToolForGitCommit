/*
 *@file   BaseItemDelegate.h
 *@brief  
 * 
 *@author 
 *@date   2014-05-24
 *
 */

#ifndef __DS_BASEITEMDELEGATE_H
#define __DS_BASEITEMDELEGATE_H

#include "DSGuiGlobal.h"
#include "ComGUIDef.h"
#include <QtGui/QStyledItemDelegate>

namespace DSGUI
{
    class DS_GUI_EXPORT DSBaseViewItemDelegate : public QStyledItemDelegate
    {
        Q_OBJECT
    public:
        DSBaseViewItemDelegate(QObject* pParent);

    public Q_SLOTS:
        // ����toolTip����
        bool helpEvent(QHelpEvent* pEvent, QAbstractItemView* pView, const QStyleOptionViewItem& optionItem, const QModelIndex& miItem);
        // �������Hoverʱ��
        void hoverEvent(QHoverEvent* pHoverEvent, QAbstractItemView* pView, const QStyleOptionViewItem& optionItem, const QModelIndex& miItem);
        // ��������¼�
        struTreeViewData::DSItemDataRole mouseEvent(QMouseEvent* pMouseEvent, QAbstractItemView* pView, 
            const QStyleOptionViewItem& optionItem, const QModelIndex& miItem);
    };
}

#endif //__DS_BASEITEMDELEGATE_H
