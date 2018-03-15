/*
 *@file   CustomComboBox.h
 *@brief  �Զ��嵯����
 * 
 *@author cc
 *@date   2014-07-08
 *
 */

#ifndef _DSGUI_CUSTOMCOMBOBOX_H
#define _DSGUI_CUSTOMCOMBOBOX_H

#include "ComboBox.h"
#include <QScopedPointer>

namespace DSGUI
{
    class DSCustomComboBoxPrivate;
    class DSComboBoxPopupContainer;
	/**  ������DSCustomComboBox
	 *   ˵��  �Զ��嵯����
	**/
	class DS_GUI_EXPORT DSCustomComboBox : public DSComboBox
	{
        Q_OBJECT
	public:
		// ���� 
		DSCustomComboBox(QWidget* pParent = NULL);
        // ����
        ~DSCustomComboBox();

    public:
        // ���õ��������� 
        void SetPopupContainer(DSComboBoxPopupContainer* pWnd);
        DSComboBoxPopupContainer* GetPopupContainer() const;

	protected:
		// �¼�
		virtual bool event(QEvent* pEvent);

		// ����¼�
		virtual void mousePressEvent(QMouseEvent* pEvent);

		// ����������
		virtual void showPopup();

		// ����������
		virtual void hidePopup();

    private:
        QScopedPointer<DSCustomComboBoxPrivate> d_ptr;

    private:
        Q_DECLARE_PRIVATE(DSCustomComboBox)
        Q_DISABLE_COPY(DSCustomComboBox)
	};
}

#endif

