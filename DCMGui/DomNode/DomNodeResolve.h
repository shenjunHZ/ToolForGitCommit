#ifndef __DSGUI_DOMNODERESOLVE_H
#define __DSGUI_DOMNODERESOLVE_H

#include "DSGuiGlobal.h"
#include <QtXml/QDomDocument>

namespace DSGUI
{
	/** @class DSDomNodeResolve
	  * @brief ����Qt��QDomNode�����xml
	  */
	class DS_GUI_EXPORT DSDomNodeResolve
	{
	public:
		// ����
		DSDomNodeResolve();
		// ����
		~DSDomNodeResolve();

	public:
		//////////////////////////////////////////////////////////////////////////
		// ��ȡ����
        //////////////////////////////////////////////////////////////////////////
		// ��ȡXML�ļ�
		bool LoadXML(const QString& strFileName);
        // �����ַ�
        bool LoadContent(const QByteArray& byteArrayText);
		// ����ӽڵ�����
		int GetChildNodeCount() const;
		// ��ȡ�ӽڵ�
		DSDomNodeResolve GetChild(int iIndex) const;
		// ͨ���ڵ�����ȡ�ӽڵ�
		DSDomNodeResolve FindChildByNodeName(const QString& strNodeName) const;
		// ��ȡ�ڵ�����
		QString GetNodeName() const;
        // ��ȡ�ڵ�ֵ
        bool GetNodeValue(QString& strNodeValue) const;
        QString GetNodeValue() const;
		// ͨ����ǩ����ȡֵ������ȡ���������ز���2
		QString GetAttribute(const QString& strTagValue, const QString& strDefValue = QString()) const;
		
	public:
		//////////////////////////////////////////////////////////////////////////
		// ����xml����
		//////////////////////////////////////////////////////////////////////////
		// �����ļ�
		bool SaveXML(const QString& strFileName);
        // ����ΪQByteArray
        QByteArray SaveAsByteArray() const; 
		// �������ڵ�
		bool CreateRootNode(const QString& strName);
		// ���Ϊ�ӽڵ�
		DSDomNodeResolve CreateChildNode(const QString& strNodeName);
		// ���õ�ǰ�ڵ�ֵ
		bool SetNodeValue(const QString& strValue);
		// ���õ�ǰ�ڵ����Լ�ֵ
		bool SetAttribute(const QString& strTagValue, const QString& strValue);
		//ɾ���ӽڵ�
		bool RemoveChildNode(int iIndex);
	
	private:
		QDomElement m_domElement;
        QDomDocument m_pDomDocument;
	};
}

#endif
