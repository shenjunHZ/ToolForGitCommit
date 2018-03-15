#ifndef __DSGUI_WAITDIALOGWATCHER_H__
#define __DSGUI_WAITDIALOGWATCHER_H__

#include "WaitDialog/WaitDialog.h"
#include "Pattern/Singleton.h"
#include <QFutureWatcher>
#include <QtConcurrentRun>

namespace DSGUI
{
    /** ������DSWaitDialogWatcher
     *  ˵�����ȴ����װ�����첽����ִ�к���
     **/
	class DS_GUI_EXPORT DSWaitDialogWatcher 
        : public DSSingleton<DSWaitDialogWatcher>
	{
		friend class DSSingleton<DSWaitDialogWatcher>;
	public:
		~DSWaitDialogWatcher();

	public:
        /* @fn    int WaitFunction(T (*pFunction)(), QWidget* pParent)
         * @brief �첽ִ�к���pFunction���������صȴ�����ʧ
         * @param <IN> T (*pFunction)() - ����ָ��
         * @param <IN> QWidget* pParent - �ȴ��򸸴���
         * @return �ȴ���ִ�н��.
         */
		template <typename T>
		int WaitFunction(T (*pFunction)(), QWidget* pParent)
		{
            // �ȴ���
			DSWaitDialog dlgWait(pParent);
			QFutureWatcher<T>* pFutureWatcher = new QFutureWatcher<T>;
			// QFutureWatcher�����ĺ������أ��ȴ�����ʧ
            QObject::connect(pFutureWatcher, SIGNAL(finished()), &dlgWait, SLOT(OnStopWaitImmediately()));

            // �첽��������
			QFuture<T> future = QtConcurrent::run(pFunction);
			pFutureWatcher->setFuture(future);
			int iRes = dlgWait.exec();

			delete pFutureWatcher;
            return iRes;
		}

        /* @fn    int WaitFunction(Class* pClass, T (Class::*pFunction)(), QWidget* pParent)
         * @brief �첽ִ�к���pFunction���������صȴ�����ʧ
         * @param <IN> Class* pClass    - ������
         * @param <IN> T (*pFunction)() - ����ָ��
         * @param <IN> QWidget* pParent - �ȴ��򸸴���
         * @return �ȴ���ִ�н��.
         */
		template <typename T, typename Class>
		int WaitFunction(Class* pClass, T (Class::*pFunction)(), QWidget* pParent)
		{
            // �ȴ���
			DSWaitDialog dlgWait(pParent);
			QFutureWatcher<T>* pFutureWatcher = new QFutureWatcher<T>;
			// QFutureWatcher�����ĺ������أ��ȴ�����ʧ
			QObject::connect(pFutureWatcher, SIGNAL(finished()), &dlgWait, SLOT(OnStopWaitImmediately()));

            // �첽��������
			QFuture<T> future = QtConcurrent::run<T>(pClass, pFunction);
			pFutureWatcher->setFuture(future);
			int iRes = dlgWait.exec();
	        
			delete pFutureWatcher;
            return iRes;
		}

        /* @fn    int WaitFunction(Class* pClass, T (Class::*pFunction)(), const char* pCancelSlot, QWidget* pParent)
         * @brief �첽ִ�к���pFunction���������صȴ�����ʧ
         * @param <IN> Class* pClass            - ������
         * @param <IN> T (*pFunction)()         - ����ָ��
         * @param <IN> const char* pCancelSlot  - ��ת�ȴ���ȡ�����������ۺ���
         * @param <IN> QWidget* pParent         - �ȴ��򸸴���
         * @return �ȴ���ִ�н��.
         */
        template <typename T, typename Class>
        int WaitFunction(Class* pClass, T (Class::*pFunction)(), const char* pCancelSlot, QWidget* pParent)
        {
            // �ȴ���
            DSWaitDialog dlgWait(pParent);
            QFutureWatcher<T>* pFutureWatcher = new QFutureWatcher<T>;
            // QFutureWatcher�����ĺ������أ��ȴ�����ʧ
            QObject::connect(pFutureWatcher, SIGNAL(finished()), &dlgWait, SLOT(OnStopWaitImmediately()));
            // ����ȡ������
            QObject::connect(&dlgWait, SIGNAL(SignalCancelWait()), pClass, pCancelSlot);

            // �첽��������
            QFuture<T> future = QtConcurrent::run<T>(pClass, pFunction);
            pFutureWatcher->setFuture(future);
            int iRes = dlgWait.exec();

            delete pFutureWatcher;
            return iRes;
        }

        /* @fn    int WaitFunction(Class* pClass, T (Class::*pFunction)(Param1), const Arg1& arg1, const char* pCancelSlot, QWidget* pParent)
         * @brief �첽ִ�к���pFunction���������صȴ�����ʧ
         * @param <IN> Class* pClass                     - ������
         * @param <IN> T (Class::*pFunction)(Param1)     - ����ָ��
         * @param <IN> const Arg1& arg1                  - ��������
         * @param <IN> const char* pCancelSlot           - ��ת�ȴ���ȡ�����������ۺ���
         * @param <IN> QWidget* pParent                  - �ȴ��򸸴���
         * @return �ȴ���ִ�н��.
         */
        template <typename T, typename Class, typename Param1, typename Arg1>
        int WaitFunction(Class* pClass, T (Class::*pFunction)(Param1), const Arg1& arg1, const char* pCancelSlot, QWidget* pParent)
        {
            // �ȴ���
            DSWaitDialog dlgWait(pParent);
            QFutureWatcher<T>* pFutureWatcher = new QFutureWatcher<T>;
            // QFutureWatcher�����ĺ������أ��ȴ�����ʧ
            QObject::connect(pFutureWatcher, SIGNAL(finished()), &dlgWait, SLOT(OnStopWaitImmediately()));
            // ����ȡ������
            QObject::connect(&dlgWait, SIGNAL(SignalCancelWait()), pClass, pCancelSlot);

            // �첽��������
            QFuture<T> future = QtConcurrent::run<T>(pClass, pFunction, arg1);
            pFutureWatcher->setFuture(future);
            int iRes = dlgWait.exec();

            delete pFutureWatcher;
            return iRes;
        }

	private:
		DSWaitDialogWatcher();
	};
}


#endif // __DSGUI_WAITDIALOGWATCHER_H__
