#ifndef __COMMON_MESSAGELOOP_H__
#define __COMMON_MESSAGELOOP_H__

#include "Common/CommonGlobal.h"
#include "Common/Pattern/Singleton.h"

namespace Common
{
	class CBaseMessageLoopPrivate;
	class CTask;

	// ���߳���Ϣѭ��
	class COMMON_EXPORT CBaseMessageLoop
	{
	public:
		// �������
		bool PostTask(CTask* pTask);
	public:
		// ������Ϣ����(ȫ�ֵ���)
		bool Start();
		// ֹͣ��Ϣ����(ȫ�ֵ���)
		void Stop();

		//��Ϣ�߳��Ƿ��Ѿ�����
		bool IsRunning() const;

	protected:
		CBaseMessageLoop();
		~CBaseMessageLoop();

		// ��Ϣ����ѭ��
		void Run();

	private:
		DS_DECLARE_PRIVATE(CBaseMessageLoop);
		CBaseMessageLoopPrivate* d_ptr;
	};

	// ����״̬���¶���
	class COMMON_EXPORT CMessageLoopForUI : public CBaseMessageLoop,
		public CSingleton<CMessageLoopForUI>
	{
		friend class CSingleton<CMessageLoopForUI>;
	};
}

#endif // __COMMON_MESSAGELOOP_H__