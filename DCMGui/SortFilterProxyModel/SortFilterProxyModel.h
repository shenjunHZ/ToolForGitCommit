#ifndef __DSGUI_SORTFILTERPROXYMODEL_H__
#define __DSGUI_SORTFILTERPROXYMODEL_H__

#include "DSGuiGlobal.h"
#include <QSortFilterProxyModel>

namespace DSGUI
{
    class DS_GUI_EXPORT DSSortFilterProxyModel : public QSortFilterProxyModel
    {
        Q_OBJECT
    public:
        enum SortOrder
        {
            DefaultOrder,    // Ĭ������
            AscendingOrder,  // ����
            DescendingOrder, // ����
        };

        enum FilterMode
        {
            KeepMatchKey   = 1,     // ����ƥ��ؼ�ֵ
            FilterMatchKey = 2,     // ���˵�ƥ��Ĺؼ�ֵ
        };
        
        enum MatchMode
        {
            DefaultMatch    = 0,   // Ĭ��ƥ�䷽ʽ������ƥ�䣩
            EqualMatch      = 1,   // ��ͬƥ��
        };
    public:
        DSSortFilterProxyModel(QObject* pParent = NULL);
        ~DSSortFilterProxyModel();

    public:
        //���ù���ģʽ
        void SetFilterMode(FilterMode enumFilterMode);
        // ����ƥ�䷽ʽ
        void SetMatchMode(MatchMode enumMatchMode);

    public:
        // ��������ʽ
        void SetSortOrder(DSSortFilterProxyModel::SortOrder enumSortOrder = DSSortFilterProxyModel::DefaultOrder);

    protected:
        // ����ʵ�ִ�
        virtual bool filterAcceptsRow(int iSourceRow, const QModelIndex& miSourceParent) const;

    private:
        FilterMode m_enumFilterMode;    // ���˷�ʽ
        MatchMode m_enumMatchMode;      // ƥ�䷽ʽ
    };
}

#endif 
