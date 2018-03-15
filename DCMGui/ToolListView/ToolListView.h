#ifndef _DSGUI_TOOLLISTVIEW_H
#define _DSGUI_TOOLLISTVIEW_H

#include "DSGuiGlobal.h"

#include <QFrame>

namespace DSGUI
{
    class DSToolListViewPrivate;

    class DS_GUI_EXPORT DSToolListView : public QFrame
    {
        Q_OBJECT
    public:
        // ����
        explicit DSToolListView(QWidget* pParent = NULL);
        // ����
        ~DSToolListView();

    public:
        // ���
        int AddItem(const QString& strText);
        // ͼ��֧�ֶ�̬�л�������1����ʵ��ʾ�����£�
        // QIcon iconItem;
        // iconItem.addPixmap(QPixmap("normal.png"), QIcon::Normal);
        // iconItem.addPixmap(QPixmap("hover.png"),  QIcon::Active);
        // iconItem.addPixmap(QPixmap("Selected.png"), QIcon::Selected);
        // iconItem.addPixmap(QPixmap("Disabled.png"), QIcon::Disabled);
        int AddItem(const QIcon& icon, const QString& strText);
        // ����
        int InsertItem(int iIndex, const QString& strText);
        int InsertItem(int iIndex, const QIcon& icon, const QString& strText);
        // ɾ��
        void RemoveItem(int iIndex);

    public:
        // �Ƿ����
        void SetItemEnabled(int iIndex, bool bEnabled);
        bool IsItemEnabled(int iIndex) const;
        // �Ƿ���ʾ
        void SetItemVisible(int iIndex, bool bVisible);
        bool IsItemVisible(int iIndex) const;
        // ����
        void SetItemText(int iIndex, const QString& strText);
        QString GetItemText(int iIndex) const;
        // ͼ��
        void SetItemIcon(int iIndex, const QIcon& icon);
        QIcon GetItemIcon(int iIndex) const;
        // tooltip
        void SetItemToolTip(int iIndex, const QString& strToolTip);
        QString GetItemToolTip(int iIndex) const;

    public:
        // ��ȡ��ӵ�item��
        int GetItemCount() const;

    public:
        // ���õ�ǰItem
        void SetCurrentIndex(int iIndex);
        // ��ǰ����
        int GetCurrentIndex() const;

    signals:
        // �������
        void SignalClickedItem(int iIndex);
        // ѡ�иı�
        void SignalCurrentIndexChanged(int iIndex);

    protected:
        // �¼��ı�
        virtual void changeEvent(QEvent* pEvent);

    private:
        // ˽������
        QScopedPointer<DSToolListViewPrivate> d_ptr;

    private:
        Q_DECLARE_PRIVATE(DSToolListView)
        Q_DISABLE_COPY(DSToolListView)
        Q_PRIVATE_SLOT(d_func(), void OnButtonClicked())
    };
}

#endif
