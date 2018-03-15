/*
 *@file   StandardItem.h
 *@brief  
 * 
 *@author 
 *@date   2014-05-28
 *
 */

#ifndef _GUITOOLKIT_STANDARDARDITE_H
#define _GUITOOLKIT_STANDARDARDITE_H

#include "DSGuiGlobal.h"
#include <QStandardItemModel>

namespace DSGUI
{
    class DS_GUI_EXPORT CStandardItem 
        : public QStandardItem
    {
    public:
        // ����
        CStandardItem();
        CStandardItem(const QString& strText);
        CStandardItem(const QIcon& icon, const QString& strText);

    public:
        // ���ò�����Ч��,�˽ӿڹ�item��ʾ������Ч��
        void SetEnabled(bool bEnabled);

    public:
        // ����item����
        bool SetItemData(const QMap<int, QVariant>& mapRoles);
    public:
        // ���ش˺��������⴦��ͼ������
        // ��ͨ������CDecorationRole�ؼ�ֵ���ı�ͼ��
        virtual QVariant data(int iRole = Qt::UserRole + 1) const;

    public:
        // ��¡item
        virtual QStandardItem* clone() const;

    protected:
        // ��������
        CStandardItem(const QStandardItem& otherItem);
    };
}

#endif
