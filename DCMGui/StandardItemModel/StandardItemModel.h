/*
 *@file   StandardItemModel.h
 *@brief  
 * 
 *@author cc
 *@date   2014-08-25
 *
 */

#ifndef _GUITOOLKIT_STANDARDARDITEMODEL_H
#define _GUITOOLKIT_STANDARDARDITEMODEL_H

#include "DSGuiGlobal.h"
#include <QStandardItemModel>

namespace DSGUI
{
    class DSStandardItemModelPrivate;

    class DS_GUI_EXPORT DSStandardItemModel 
        : public QStandardItemModel
    {
        Q_OBJECT
    public:
        // ����
        DSStandardItemModel(QObject* pParent = NULL);
        ~DSStandardItemModel();

    public:
        // ���ػ�ȡ����
        virtual QVariant data(const QModelIndex& miIndex, int iRole = Qt::DisplayRole) const;

    public:
        // ����ӳ��
        // ��iProxyColumn��iProxyRole�����ݴ���iSourceColumn��iSourceRole��ȡ
        // iProxyColumnΪ-1��ʾ�����ж�ӳ��
        void AddKeyMapping(int iProxyColumn, int iProxyRole, int iSourceColumn, int iSourceRole);
    private:
        QScopedPointer<DSStandardItemModelPrivate> d_ptr;

    private:
        Q_DECLARE_PRIVATE(DSStandardItemModel)
        Q_DISABLE_COPY(DSStandardItemModel)
    };
}

#endif
