/*
 *@file   CustomToolBox.h
 *@brief  ������չ���������
 *        ����ӿڲ�����ʹ��
 *        ui������д�QFrame����
 *@author cc
 *@date   2014-08-20
 *
 */

#ifndef __DSGUI_CUSTOMTOOLBOX_H__
#define __DSGUI_CUSTOMTOOLBOX_H__

#include "ToolBox/ToolBox.h"

namespace DSGUI
{
    class DSCustomToolBoxPrivate;
    /** @class CCustomToolBox
     *  @brief ������չ���������
     *  ����ӿڲ�����ʹ��
     *  ui������д�QFrame����
     */
    class DS_GUI_EXPORT DSCustomToolBox : public DSToolBox
    {
        Q_OBJECT
    public:
        // ����
        explicit DSCustomToolBox(QWidget* pParent = NULL);
        // ����
        ~DSCustomToolBox();

    public:
        // ���
        int AddItem(QWidget* pWidget, const QString& strText);
        int AddItem(QWidget* pWidget, const QIcon& icon, const QString& strText);

		int AddItem(QWidget* pWidget, const QString& strText, QPixmap& pixIndicatorExpand, QPixmap& pixIndicatorCollapse, QSize indicatorSize);
		int AddItem(QWidget* pWidget, const QIcon& icon, const QString& strText, QPixmap& pixIndicatorExpand, QPixmap& pixIndicatorCollapse, QSize indicatorSize);

        // ����
        int InsertItem(int iIndex, QWidget* pWidget, const QString& strText);
        int InsertItem(int iIndex, QWidget* pWidget, const QIcon& icon, const QString& strText);

		int InsertItem(int iIndex, QWidget* pWidget, const QString& strText, QPixmap& pixIndicatorExpand, QPixmap& pixIndicatorCollapse, QSize indicatorSize);
		int InsertItem(int iIndex, QWidget* pWidget, const QIcon& icon, const QString& strText, QPixmap& pixIndicatorExpand, QPixmap& pixIndicatorCollapse, QSize indicatorSize);
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
        // ��ʾ
        void SetItemToolTip(int iIndex, const QString& strToolTip);
        QString GetItemToolTip(int iIndex) const;

    public:
        // ͨ��������ȡ����
        QWidget* GetWidget(int iIndex) const;
        // ��ȡ��ӵĴ�����item������
        int IndexOf(QWidget* pWidget) const;
        // ��ȡ��ӵ�item��
        int GetItemCount() const;

    public:
        // ����չ��������
        void SetExpandOrCollapseIndex(int iIndex, bool bExpanded);
        void SetExpandOrCollapseWidget(QWidget* pWidget, bool bExpanded);
        // �Ƿ�չ��
        bool IsExpanded(int iIndex) const;

    signals:
        // �������
        void SignalClickedItem(int iIndex);
        // �������������2����ǰ״̬
        void SignalClickedItem(int iIndex, bool bExpanded);
        // չ��������
        void SignalExpandOrCollapse(int iIndex, bool bExpanded);

    protected:
        // �¼��ı�
        virtual void changeEvent(QEvent* pEvent);

    private:
        QScopedPointer<DSCustomToolBoxPrivate> d_ptr;

    private:
        Q_DECLARE_PRIVATE(DSCustomToolBox)
        Q_DISABLE_COPY(DSCustomToolBox)
        Q_PRIVATE_SLOT(d_func(), void OnButtonClicked())
        Q_PRIVATE_SLOT(d_func(), void OnWidgetDestroyed(QObject*))
    };
}

#endif
