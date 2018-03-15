#ifndef __DSGUI_WAITDIALOG_H__
#define __DSGUI_WAITDIALOG_H__

#include "DSGuiGlobal.h"
#include <QDialog>

class Ui_CWaitDialogUI;
namespace DSGUI
{
    class DSWaitDialogPrivate;

	/** ������DSWaitDialog
	 *  ˵��  �ȴ���
	 **/
	class DS_GUI_EXPORT DSWaitDialog : public QDialog
	{
		Q_OBJECT
	public:
        // ����������
		DSWaitDialog(QWidget* pParent = NULL);
		~DSWaitDialog();

	signals:
        // ȡ���ȴ�����
		void SignalCancelWait();

    public Q_SLOTS:// �ۺ���
        // ȡ���ȴ��������ᴥ��SignalCancelWait
		void OnCancelWait();
        // ����ֹͣ�ȴ�����������
		void OnStopWaitImmediately();

	protected:
		virtual void paintEvent(QPaintEvent *e);

    private:
        QScopedPointer<DSWaitDialogPrivate> d_ptr;

    private:
        Q_DECLARE_PRIVATE(DSWaitDialog)
        Q_DISABLE_COPY(DSWaitDialog)
        Q_PRIVATE_SLOT(d_func(), void OnTimeout())

    private:
        QScopedPointer<Ui_CWaitDialogUI> m_ptWaitDialogUI;

	};
}

#endif // __DSGUI_WAITDIALOG_H__
