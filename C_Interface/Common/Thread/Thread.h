#ifndef __COMMON_THREAD_H__
#define __COMMON_THREAD_H__

#include "Common/CommonGlobal.h"

namespace Common
{
	class CThreadPrivate;
	// ���߳���Ϣѭ��
	class COMMON_EXPORT CThread
	{
	protected:
		CThread();
		~CThread();

	public:
		// �����̣߳���λ����
		bool StartThread(unsigned int uWaitTime);
		// ֹͣ�߳�
		void StopThread();

		// �����̣߳�ȡ���ȴ�
		void WakeUpOnce();

		// �߳��Ƿ�����
		bool IsRunning() const;
	public:
		// �߳�˯��
		static void Sleep(unsigned long iSecs);
		static void MSleep(unsigned long iMSecs);
		static void USleep(unsigned long iUSecs);

	protected:
		// �߳�ִ�С�����ֵ��false��ֹͣ�̺߳��� true������ִ��
		virtual bool Run() = 0;

	private:
		// �����߳�
		void CallThread();

	private:
		DS_DECLARE_PRIVATE(CThread);
		CThreadPrivate* d_ptr;
	};
}

#endif // __COMMON_THREAD_H__