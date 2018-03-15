/*
 *@file   Singleton.h
 *@brief  ������
 * 
 *@author 
 *@date   
 *
 */

#ifndef __COMMON_SINGLETON_H__
#define __COMMON_SINGLETON_H__

#include "Common/Thread/Mutex.h"

namespace Common
{
	/**  ������CSingleton
	  *  ˵����������
	 **/
	template <class T>
	class CSingleton
	{
	public:
		// ��ȡ����
		static T& GetInstance();

	protected:
		// ����
		CSingleton() {}
		// ����
		virtual ~CSingleton() {}
	};

	/** @fn	    inline T& CSingleton<T>::GetInstance()
	 *  @brief	��ȡ����
	 *  @param	void
	 *  @return	T ���ص���
	 */
	template <class T>
	inline T& CSingleton<T>::GetInstance()
	{
        static std::auto_ptr<T> s_ptrInstance;
		static DSMutex m_mutexInstance;

		if (s_ptrInstance.get() == NULL)
		{
            // ���ⴴ������
			DSMutexLock locker(m_mutexInstance); 
            // ���̱߳���
			if (s_ptrInstance.get() == NULL)
			{
				s_ptrInstance = std::auto_ptr<T>(new T);
			}
		}

		return *s_ptrInstance.get();
	}
}

#endif // __COMMON_SINGLETON_H__
