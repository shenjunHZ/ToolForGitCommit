/*
 *@file   MessageBox.h
 *@brief  
 * 
 *@author wp
 *@date   2014-07-015
 *
 */

#ifndef __DSGUI_MESSAGEBOX_H
#define __DSGUI_MESSAGEBOX_H

#include "DSGuiGlobal.h"
#include "Dialog/Dialog.h"

class QAbstractButton;
class QDialogButtonBox;

namespace DSGUI
{
	class DSMessageBoxPrivate;
	class DSPushButton;
	/**	@class DSMessageBox
	 *	@brief ��Ϣ��ʾ��
	 */
	class DS_GUI_EXPORT DSMessageBox : public DSDialog
	{
		Q_OBJECT
		Q_PROPERTY(QPixmap pixWarningImage READ GetWarningImage WRITE SetWarningImage)

	public:
		 /*@enum:  DialogFlag
         *@brief: ��������ͼ��
         *
         */
        enum Icon
        {
            NoIcon = 0,
            Information = 1,
            //Warning = 2,
            //Critical = 3,
            //Question = 4
        };

		 /*@enum:  DialogFlag
         *@brief: ���ڶ�����Ϣ�򰴼�
         *
         */
        enum StandardButton 
        {
            NoButton           = 0x00000000,
            Ok                 = 0x00000400,
            Cancel             = 0x00002000,
            Yes                = 0x00004000,
            No                 = 0x00010000,
            Close              = 0x00200000,
        };
        Q_DECLARE_FLAGS(StandardButtons, StandardButton)

	public:
		 // ���캯��
		DSMessageBox(QWidget* pParent = NULL);
		 // ���캯��������1����ͼ�꣬����2���ñ��⣬����3������Ϣ���ݣ�����4���ð���
		 //����6�������ùرգ���С��������Ƿ���ʾ
        DSMessageBox(Icon enumIcon, const QString& strTitle, const QString& strMsg,
            StandardButtons enumButtons = NoButton, QWidget* pParent = NULL, DialogFlags enumDialogFlag = DSDialog::CloseButtonHint);

		~DSMessageBox();

    public:
        // ��Ϣ�򣬲���2���ñ��⣬����3������Ϣ���ݣ�����4���ð���
        static StandardButton ShowInformation(QWidget* pParent, const QString& strTitle,
            const QString& strMsg, StandardButtons enumButtons);

		// ������Ϣ���ı�����
		void SetMsgText(QString strMsgText);

		// ��ȡ�û�����İ�ť
		StandardButton GetClickBtn();


	private:
		QScopedPointer<DSMessageBoxPrivate> d_ptr;

		// ����ͼƬ
		void SetWarningImage(const QPixmap& pixBorderImage);
		// ��ȡͼƬ
		QPixmap GetWarningImage() const;
	private:
		Q_PRIVATE_SLOT(d_func(), void OnButtonOkClicked())
        Q_PRIVATE_SLOT(d_func(), void OnButtonYesClicked())
        Q_PRIVATE_SLOT(d_func(), void OnButtonCancelClicked())
        Q_PRIVATE_SLOT(d_func(), void OnButtonNoClicked())
        Q_PRIVATE_SLOT(d_func(), void OnButtonCancelClicked())
		Q_DISABLE_COPY(DSMessageBox)
		Q_DECLARE_PRIVATE(DSMessageBox)
	};
}

Q_DECLARE_OPERATORS_FOR_FLAGS(DSGUI::DSMessageBox::StandardButtons)
#endif
