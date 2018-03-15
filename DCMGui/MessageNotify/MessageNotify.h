#ifndef __DSGUI_MESSAGENOTIFY_H__
#define __DSGUI_MESSAGENOTIFY_H__

#include "DSGuiGlobal.h"
#include "Pattern/Singleton.h"
#include <QtNetwork/QLocalSocket>

namespace DSGUI
{
    class DSMessageNotifyPrivate;

    /** ������DSMessageNotify
     *  ˵�������½���ʾ��
     *  �˽ӿ�����QCoreApplication::exec()����֮ǰʹ��
     **/
    class DS_GUI_EXPORT DSMessageNotify : public QObject,
        public DSSingleton<DSMessageNotify>
    {
        Q_OBJECT
        friend class DSSingleton<DSMessageNotify>;

    public:
        ~DSMessageNotify();

    public:
        // ��ʾ����⡣������ʾ������֮ǰ���ã�ֻ������һ�μ��ɡ�
        void SetMessageNotifyTitle(const QString& strTitle);
        // �������������1Ϊ������Դ�б�����2ΪƤ��
        void SetParam(const QStringList& strListTranslations, const QStringList& strListSkins,const QString& strLang);
		// ������Ϣ��ʾ����̣��ϲ����
		void StartMessageProcess();

    public:
        // ���������ʾ��Ϣ
        void AddTextNotification(const QString& strNotifyInfo);
        // ���ͼƬ��ʾ��Ϣ
        void AddPictureNotification(const QString& strNotifyInfo, const QString& strFile);
		// ���¼����ʾ��Ϣ
		void AddRecordNotification(const QString& strNotifyInfo, const QString& strFile);
		// ��ʾ������
		void ShowModalProgressBar(bool bShow);
    private:
        DSMessageNotify();

    private:
        QScopedPointer<DSMessageNotifyPrivate> d_ptr;

    private:
        Q_DECLARE_PRIVATE(DSMessageNotify)
        Q_DISABLE_COPY(DSMessageNotify)
        Q_PRIVATE_SLOT(d_func(), void OnAPPAboutToQuit())
        Q_PRIVATE_SLOT(d_func(), void OnAPPAboutToQuit())
        Q_PRIVATE_SLOT(d_func(), void OnLocalSocketError(QLocalSocket::LocalSocketError))
        
    };
}

#endif
