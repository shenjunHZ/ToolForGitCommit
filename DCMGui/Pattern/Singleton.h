/*
 *@file   Singleton.h
 *@brief  �������ʹ�õĵ�����
 * 
 *@author cc
 *@date   2014-07-19
 *
 */

#ifndef __DSGUI_SINGLETON_H__
#define __DSGUI_SINGLETON_H__

#include <QMutex>

namespace DSGUI
{
	/**  ������DSSingleton
	  *  ˵����������
	 **/
	template <class T>
	class DSSingleton
	{
	public:
		// ��ȡ����
		static T& Instance();

	protected:
		// ����
		DSSingleton() {}
		// ����
		virtual ~DSSingleton() {}
	};

	/** @fn	    inline T& DSSingleton<T>::Instance()
	 *  @brief	��ȡ����
	 *  @param	void
	 *  @return	T ���ص���
	 */
	template <class T>
	inline T& DSSingleton<T>::Instance()
	{
        static std::auto_ptr<T> s_ptrInstance;
		static QMutex m_mutexInstance;

		if (s_ptrInstance.get() == NULL)
		{
            // ���ⴴ������
			QMutexLocker locker(&m_mutexInstance); 
            // ���̱߳���
			if (s_ptrInstance.get() == NULL)
			{
				s_ptrInstance = std::auto_ptr<T>(new T);
			}
		}

		return *s_ptrInstance.get();
	}
}

#endif
