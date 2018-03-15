#ifndef _DSGUI_TABPANEL_H
#define _DSGUI_TABPANEL_H

#include "DSGuiGlobal.h"
#include "PictureBrowser/PictureBrowser.h"
#include "TabMimeData.h"
#include <QVariant>
#include <QIcon>

namespace DSGUI
{
    class DSTabPanelPrivate;

	typedef struct TabPanel
	{
		QString strPluginId; //��strPluginIdGroupListΪ��ʱ��strPluginIdֵ��ʾ���id����strPluginIdGroupList��Ϊ��ʱ��strPluginIdֵ��ʾ������
		QStringList strPluginIdGroupList; //��ǩ������Ĳ��id
	}TabPanel_t;

	typedef struct TabItemInfo
	{
		QIcon iconItem;
		QString strText;
		QString strPluginID;
	}TabItemInfo_t;

	/**  ������DSTabPanel
	  *  ˵��  ����ǩ
	 **/
	class DS_GUI_EXPORT DSTabPanel : public DSPictureBrowser
	{
		Q_OBJECT

	public:
		// ����
		explicit DSTabPanel(QWidget* pParent = NULL);
		 ~DSTabPanel();

    public:
        // ���ø��Ӵ�С
        void SetGridSize(const QSize& szGrid);
		//����������
		void SetRowCol(int nRow, int nCol);
		//����������߿�ı߾�
		void SetMargins(int iLeft, int iTop, int iRight, int iBottom);
		//���ø������
		void SetFloatPanel(DSTabPanel* pFloatPanel);
		//���ø���item
		void SetFloatItem(QGraphicsItem* pItem);

    public:
        // ��ӱ�ǩ��������ӵ�λ��
        int AddTab(const QString &strName, const QString &strPluginID, const QVariant& vtUserData = QVariant());
        int AddTab(const QIcon& iconTab, const QString &strName, const QString &strPluginID, const QVariant& vtUserData = QVariant());
		int AddTabGroup(const QList<TabGroup_t>& lsTabGroup, const QString& strGroupName);
		int InsertTabGroup(int iIndex, const QList<TabGroup_t>& lsTabGroup, const QString& strGroupName);
        // �����ǩ��������ӵ�λ��
        int InsertTab(int iIndex, const QString &strName, const QString &strPluginID, const QVariant& vtUserData = QVariant());
        int InsertTab(int iIndex, const QIcon& iconTab, const QString &strName, const QString &strPluginID, const QVariant& vtUserData = QVariant());
        // ɾ����ǩ
        void RemoveTab(int iIndex);
        // tabҳ����
        int GetTabCount() const;

		// ��ȡ����tab��ID
		QList<TabPanel_t> GetAllTabPluginID();

		void setRoundMask(int xRnd, int yRnd);

		// ɾ�����б�ǩ
		void RemoveAllTab();

    public:
        // ��ǩ����
        QString GetTabText(int iIndex) const;
        void SetTabText(int iIndex, const QString &strTab);
        // ��ǩͼ��
        QIcon GetTabIcon(int iIndex) const;
        void SetTabIcon(int iIndex, const QIcon & iconTab);
		//��ǩ����
		QString GetTabPluginID(int iIndex) const;
		void SetTabPluginID(int iIndex, const QString &strPluginID);
        // ��ǩtip
        //void SetTabToolTip(int iIndex, const QString & strTip);
        //QString GetTabToolTip(int iIndex) const;
        // �����Զ�������
        void SetUserData(int iIndex, const QVariant& vtUserData);
        QVariant GetUserData(int iIndex) const;
		// ��ǩ����
		void SetGroupTabText(const QString& strText);
		QString GetGroupTabText() const;
		
		bool IsCombine(int iIndex);
		void GetItemsInfo(int iIndex, QList<TabItemInfo_t>& lsList) const;
		QString GetGroupName(int iIndex);

    public:
        /** ö�٣�TabDirection
         *  ˵�������ַ�ʽ
         **/
        enum TabDirection 
        { 
            LeftToRight = 0,
            //RightToLeft = 1,
            //TopToBottom = 2
        };
        // ���ַ�ʽ
        /*TabDirection GetTabDirection() const;
        void SetTabDirection(TabDirection enumTabDirection);*/

    public:
        enum DragDropMode
        {
            NoDragDrop     = 0,                   // ����קЧ��
            DragOnly       = 1,                   // ���ϳ�
            DropOnly       = 2,                   // ���Ͻ�
            DragDrop       = DragOnly | DropOnly, // ���ϳ����Ͻ�
            InternalMove   = 4,                   // ���ڲ��ƶ�
        };
        Q_DECLARE_FLAGS(DragDropModes, DragDropMode)
        
        // ��קģʽ
        void SetDragDropModes(DragDropModes enumModes);
        DragDropModes GetDragDropModes() const;

    public:
        // ���ø��Ӽ��
        void SetSpacing(int iSpacing);
		void SetHSpacing(int iSpacing);
		void SetVSpacing(int iSpacing);
        // ���ñ�Ե���
        void SetPanelMargins(int iLeft, int iTop, int iRight, int iBottom);

	Q_SIGNALS:
        // ѡ�иı�
        void SignalClickedTab(QString strPluginID);
        // Tab�ƶ�
        void SignalTabMoved(int iFrom, int iTo);
        // ��ק�����뿪
        void SignalAboutDragLeave(int iIndex);
        // �ϳ�Tab���ź�
        void SignalDragLeave();
		// ����Tab�ź�
		void SignalInsertTab();
        // �����������
        void SignalHoverEnter(QString strText, bool bCombine);
        // ��������뿪
        void SignalHoverLeave();
		// ��ʾ�ڵ���
		void SignalTabPanelGroup();
		// ѡ�е���
		void SignalPressTab(QString strPluginID);
		// ���ָı�
		void SignalLayoutChange();

    protected:
        // �¼�����
        virtual bool eventFilter(QObject *pObject, QEvent *pEvent);
		virtual void resizeEvent(QResizeEvent* pResizeEvent);

	private slots:
		void OnBtnEnter(QString strText, bool bCombine);
		void OnBtnLeave();
		void OnBtnClicked(QGraphicsItem*);
		void OnBtnPress(QGraphicsItem*);
		void OnCheckPageBtn();

    private:
        // ˽������
        QScopedPointer<DSTabPanelPrivate> d_ptr;

    private:
        Q_DECLARE_PRIVATE(DSTabPanel)
        Q_DISABLE_COPY(DSTabPanel)
        Q_PRIVATE_SLOT(d_func(), void OnPreviousBtnClicked())
        Q_PRIVATE_SLOT(d_func(), void OnNextBtnClicked())

	};
}

Q_DECLARE_OPERATORS_FOR_FLAGS(DSGUI::DSTabPanel::DragDropModes)

#endif
