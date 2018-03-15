#ifndef __DSGUI_WIDGETLAYOUT_H
#define __DSGUI_WIDGETLAYOUT_H

#include "DomNode/DomNodeResolve.h"
#include "ComGuiDef.h"

#include <QWidget>
#include <QList>
#include <QGridLayout>

#define MAX_WNDSPLIT_COUT			12
#define MAX_SPLIT_SIZE				8
#define MAX_SPLIT_WND_COUNT			(MAX_SPLIT_SIZE * MAX_SPLIT_SIZE)
#define MAX_NODE_COUNT				100


namespace DSGUI
{
	class DSSingleWnd;

	typedef struct struSubWnd{
		int wndID;								// �Ӵ��ڵ�������
		int wndColumn;							// �к�
		int wndRow;
		int wndHStretch;						// �Ӵ����б���ֵ
		int wndVStretch;						// �Ӵ����б���ֵ
	}subWnd;

	typedef struct struNode{
		QString splitName;						// �ָ�������
		int typeIndex;							// �ָ�����������
		int wndNum;								// ���ڷָ���
		QString rowStretch;						// �б���
		QString columnStretch;					// �б���
		int wndRows;							// ����������õ�
		int wndColumns;							// ����
		subWnd subWnds[MAX_SPLIT_WND_COUNT];	// �Ӵ���
	}wndNode;


	/** @class DSWidgetLayout
	  * @brief ���ڷָ��ʵ����
	  */
	class DSWidgetLayout
	{
	public:
		// ����
		DSWidgetLayout(const QString& strXmlFile);
		// ����
		~DSWidgetLayout();

	public:
		bool Init(QWidget* pParent, struLayoutData::LayoutType enumLayoutType = struLayoutData::D_2x2_4);
        bool UnInit();

    public:
		//bool ReLayout(LayoutType eunmType);
		// ���㴰�ھ���λ��
		QRect CalWndFrameRect(int iWndIndex, struLayoutData::LayoutType eunmType);

		struLayoutData::LayoutType GetLayoutType() const;

		int GetRows(struLayoutData::LayoutType eunmType) const;
		int GetColumns(struLayoutData::LayoutType eunmType) const;

		// �Զ���ָ�ֱ���
		// ���Ӳ�������
		bool AddLayoutInXml(const QString& strXmlFile, wndNode CustomNode);
		// �޸Ĳ������ͣ����ǣ�
		bool ModifyLayoutInXml(const QString& strXmlFile, wndNode CustomNode);

    /*public:
		void ShowMaximized(int iIndex);
		bool IsMaximized(int iIndex) const;
		void ShowNormal();*/

    public:
		//QWidget* GetWidget(int iIndex) const;
        //bool GetWidgets(QList<QWidget*>& listWidgets);

	private:
		// ��ȡXml�е����ݣ����浽����Ӧ�Ľṹ��
		void getDataFromXml();

		// ��ȡĳһ�ָ�������xml�е�������
		int GetIndexOfXML(struLayoutData::LayoutType eunmType) const;

		// �ı��Ӵ��ڵ���Ŀ
		void ChangeSingleWndNum();



	private:
		QWidget*			m_pParent;							// ������
		struLayoutData::LayoutType		m_enumlayoutType;					// ��ǰ���ڷָ�����
		int					m_iIndex;							// ��ǰ���ڷָ���xml�е�������
		wndNode				m_struWndNodes[MAX_NODE_COUNT];		// ����ÿ�ַָ����͵Ĳ���
		wndNode				m_struCustomWndNodes;
		int					m_iNodeNum;							// ���ڲ��ֵķָ�������Ŀ
		int					m_iCustomNodeNum;
		DSDomNodeResolve	m_dNode;							// Ĭ��
		DSDomNodeResolve	m_dCustomNode;						// �Զ���
		bool				m_bIsMaximized;						// �Ƿ����
	};
}

#endif
