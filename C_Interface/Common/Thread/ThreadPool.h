#ifndef __COMMON_THREADPOOL_H__
#define __COMMON_THREADPOOL_H__

#include "Common/CommonGlobal.h"
#include "Common/Pattern/Singleton.h"

namespace Common
{
    class CTask;
	// ���߳���Ϣѭ������˳�򡢶�ʱִ�С����Ƶ�¼�����ȡ�
	class CScheduleThreadPoolPrivate;
	class CScheduleThreadPool
	{
	public:
		// �������
		bool PostTask(CTask* pTask);
	protected:
		// ������Ϣ����
		bool Start();
		// ֹͣ��Ϣ����
		void Stop();

		// ��Ϣ����ѭ��
		void Run();

	private:
		CScheduleThreadPool(int iMaxThreadNum);
		~CScheduleThreadPool();

	private:
		DS_DECLARE_PRIVATE(CScheduleThreadPool);
		CScheduleThreadPoolPrivate* d_ptr;
	};

	//////////////////////////////////////////////////////////////////////////
	class CCachedThreadPoolPrivate;
	// �ɻ�����̳߳ء�������Ԥ�����طŵȲ�����ء� 
	class COMMON_EXPORT CCachedThreadPool
	{
		friend class CMessageLoopPoolForSDK;
	public:
		/** ��������
		 * @param[in] const std::string& strID �̳߳ض��б�ʶ�룬��ͬ�����豣֤Ψһ��
		 * @param[in] CTask* pTask ����
		 * @return 
		 */
		bool PostTask(const std::string& strID, CTask* pTask);        /** ��Ϊ��������������е�����
         *  �ȴ���ǰ����ִ���������
		 * @param[in] const std::string& strID �̳߳ض��б�ʶ�룬��ͬ�����豣֤Ψһ��
		 * @return 
		 */        void ClearTask(const std::string& strID);        /** �첽��Ϊ��������������е�����
         *  �������ǰ����ִ������
		 * @param[in] const std::string& strID �̳߳ض��б�ʶ�룬��ͬ�����豣֤Ψһ��
		 * @return 
		 */        void AsyncClearTask(const std::string& strID);
	public:
		// ����
		bool Start();
		// ֹͣ
		void Stop();

	private:
		CCachedThreadPool();
		~CCachedThreadPool();

	private:
		DS_DECLARE_PRIVATE(CCachedThreadPool);
		CCachedThreadPoolPrivate* d_ptr;
	};

	// SDKͬ�����ö��У����������ʹ�õģ������¼�����ȣ���ʹ�ô��̳߳�
	class COMMON_EXPORT CMessageLoopPoolForSDK : public CCachedThreadPool,
		public CSingleton<CMessageLoopPoolForSDK>
	{
		friend class CSingleton<CMessageLoopPoolForSDK>;
	};
	//////////////////////////////////////////////////////////////////////////
}

#endif // __COMMON_THREADPOOL_H__