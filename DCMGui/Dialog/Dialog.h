/*
 *@file   Dialog.h
 *@brief  
 * 
 *@author cc
 *@date   2014-07-01
 *
 */

#ifndef _DSGUI_DIALOG_H
#define _DSGUI_DIALOG_H

#include "DSGuiGlobal.h"
#include <QDialog>

class QHBoxLayout;
class QToolButton;
class Ui_CDialogUI;

namespace DSGUI
{
    class DSDialogPrivate;
    /** @class DSDialog
     *  @brief �Ի���
     */
    class DS_GUI_EXPORT DSDialog 
        : public QDialog
    {
        Q_OBJECT
        Q_ENUMS(DialogFlag)
        Q_PROPERTY(QPixmap pixBorderImage READ GetBorderImage WRITE SetBorderImage)
    public:
        /*@enum:  DialogFlag
         *@brief: ���ڶ��ƴ��ڿؼ�
         *
         */
        enum DialogFlag
        {
            CloseButtonHint = 0x1,     // �رհ�ť��ʾ
            MinimizeButtonHint = 0x2,  // ��С����ť��ʾ
            MaximizeButtonHint = 0x4,  // ��󻯰�ť��ʾ
            MinMaxButtonsHint = MinimizeButtonHint | MaximizeButtonHint,   // 
        };
        Q_DECLARE_FLAGS(DialogFlags, DialogFlag)

    public:
        // ���죬����2���ùرգ���С��������Ƿ���ʾ��������ò�������
        DSDialog(QWidget* pParent = NULL, DialogFlags enumDialogFlags = 0);
        ~DSDialog();

    public:
        // ���ñ�������
        void SetTitle(const QString& strTitle);
        // ��ȡ��������
        QString GetTitle() const;
        // ���ñ�����ʾ��ʽ
        void SetTitleAlignment(Qt::Alignment enumAlignment);
        // �ڹرհ�ť�����ӿؼ�
        void InsertTitleWidget(QWidget* pWidget, int iIndex = 0);
        // ˫���������󻯺ͻ�ԭ
        void SetOpenDoubleClickTitle(bool bOpen);
        //�Ƿ����˳���Ч
        void SetCloseAnimaEnable(bool bOpen);

    public:
        // ����м�Ĵ���
        void AddCentralWidget(QWidget* pWidget);
        // ��ȡ�м�Ĵ���
        QWidget* GetCentralWidget() const;
        // ���ش��ڱ���
        void SetTitleHide(bool bhide = true);

    public:
        // �Ƿ�� �ı䴰�ڴ�С
        void SetOpenChangeSize(bool bOpen);

    public Q_SLOTS:
        // �رհ�ť��Ӧ�����ش˽ӿڿɹ���Ĭ�Ϲرհ�ť����
        virtual void OnCloseBtmClicked();

    protected:
        // ����Բ��
        virtual void resizeEvent(QResizeEvent* pEvent);
        // ���˼���Key_Escape���¼�
        virtual void keyPressEvent(QKeyEvent* pEvent);
        virtual void moveEvent(QMoveEvent *event);
        virtual void done(int);

    protected slots:
        // �л����ť ��󻯺ͻ�ԭ tooltip
        void OnTurnMaximizeButtonTip();

    private:
        // ����ͼƬ
        void SetBorderImage(const QPixmap& pixBorderImage);
        // ��ȡͼƬ
        QPixmap GetBorderImage() const;

    private:
        QScopedPointer<DSDialogPrivate> d_ptr;
        
    private:
        Q_DECLARE_PRIVATE(DSDialog)
        Q_DISABLE_COPY(DSDialog)
        Q_PRIVATE_SLOT(d_func(), void OnSizeStatusChanged())
        Q_PRIVATE_SLOT(d_func(), void OnDoneAnimaFinished())
    private:
        QScopedPointer<Ui_CDialogUI> m_ptDialogUI;
    };
}

Q_DECLARE_OPERATORS_FOR_FLAGS(DSGUI::DSDialog::DialogFlags)


#endif
