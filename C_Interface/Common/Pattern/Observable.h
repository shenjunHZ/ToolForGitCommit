#ifndef __COMMON_OBSERVEABLE_H__
#define __COMMON_OBSERVEABLE_H__

#include "Common/CommonGlobal.h"
#include "Common/Thread/Mutex.h"
#include <list>
#include <algorithm>

namespace Common
{
    // �۲���ģʽ�еĿɹ۲���
    template <class TObserver>
    class CObservable
    {
        typedef typename std::list<TObserver*>::iterator ObserverIterator;
    public:
        CObservable();
        ~CObservable();

    public:
        // ע��
        bool RegisterObserver(TObserver* pObserver);
        // ����
        bool UnRegisterObserver(TObserver* pObserver);

    public:
        // FunctionPointer fnΪ����ָ��
        template <class FunctionPointer, class Param>
        void NotifyObservers(FunctionPointer fn, const Param& param);

		// FunctionPointer fnΪ����ָ��
		template <class FunctionPointer, class Param>
		void NotifyObservers(FunctionPointer fn, const Param* pParam);
    private:
        std::list<TObserver*> m_lstObservers;            // �۲����б�

    private:
        DSMutex m_mutex;                       // ��Q
    };

    template <class TObserver>
    inline CObservable<TObserver>::CObservable()
    {
    }

    template <class TObserver>
    inline CObservable<TObserver>::~CObservable()
    {
    }

    // ע��
    template <class TObserver>
    inline bool CObservable<TObserver>::RegisterObserver(TObserver* pObserver)
    {
        if (pObserver == NULL)
        {
            return false;
        }

        DSMutexLock lock(m_mutex);
        m_lstObservers.push_front(pObserver);

#ifdef _DEBUG
		pObserver->IncreaseCount();
#endif 

        return true;
    }

    // ����
    template <class TObserver>
    inline bool CObservable<TObserver>::UnRegisterObserver(TObserver* pObserver)
    {
        DSMutexLock lock(m_mutex);
        ObserverIterator it = find(m_lstObservers.begin(), m_lstObservers.end(), pObserver);
        if (it != m_lstObservers.end())
        {
#ifdef _DEBUG
			(*it)->DecreaseCount();
#endif 
            m_lstObservers.erase(it);
        }

        return true;
    }

    // �����й۲��߷ַ���Ϣ
    template <class TObserver> template <class FunctionPointer, class Param>
    inline void CObservable<TObserver>::NotifyObservers(FunctionPointer fn, const Param& param)
    {
        DSMutexLock lock(m_mutex);
        for (ObserverIterator it = m_lstObservers.begin(); it != m_lstObservers.end(); ++it)
        {
            TObserver* pTObserver = *it;
            (pTObserver->*fn)(param);
        }
    }

	// �����й۲��߷ַ���Ϣ
	template <class TObserver> template <class FunctionPointer, class Param>
	inline void CObservable<TObserver>::NotifyObservers(FunctionPointer fn, const Param* pParam)
	{
		DSMutexLock lock(m_mutex);
		for (ObserverIterator it = m_lstObservers.begin(); it != m_lstObservers.end(); ++it)
		{
			TObserver* pTObserver = *it;
			(pTObserver->*fn)(pParam);
		}
	}
}

#endif
