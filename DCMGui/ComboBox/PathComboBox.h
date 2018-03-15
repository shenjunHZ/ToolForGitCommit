/*
 *@file   PathComboBox.h
 *@brief  ·��ѡ��ؼ�
 * 
 *@author cc
 *@date   2016-12-03
 *
 */

#ifndef _DSGUI_PATHCOMBOBOX_H
#define _DSGUI_PATHCOMBOBOX_H

#include "DSGuiGlobal.h"
#include <QComboBox>
#include <QFileDialog>

namespace DSGUI
{
	/**  ������DSPathComboBox
	 *   ˵��  ·��ѡ��ؼ�
	**/
	class DS_GUI_EXPORT DSPathComboBox : public QComboBox
	{
		Q_OBJECT

	public:
		// ����
		DSPathComboBox(QWidget* pParent = NULL);
		~DSPathComboBox();

		// �ο�QFileDialog::setFileMode
		void SetFileMode(QFileDialog::FileMode enumMode);

		// ���ñ�����
		void SetTitle(const QString& strTitle);

		// �ο�QFileDialog::setFilter
		void SetFilter(const QString& strFilter);

		// �ο�QFileDialog::setDirectory
		void SetDirectory(const QString& strDirectory);

	protected:
		virtual void showPopup();
		virtual void mousePressEvent(QMouseEvent* pEvent);
		virtual void keyPressEvent(QKeyEvent* pEvent);

	private:
		QFileDialog::FileMode m_enumMode; 
		QString m_strTitle;
		QString m_strFilter;
		QString m_strDirectory;
	};
}


#endif // _DSGUI_PATHCOMBOBOX_H
