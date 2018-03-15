#ifndef __COMMON_MEMORYPOOL_H__
#define __COMMON_MEMORYPOOL_H__

#include "Common/CommonGlobal.h"
#include "Common/Thread/Mutex.h"
#include <boost/pool/singleton_pool.hpp>

namespace Common
{
    template <class T>
    class CMemoryAlloc
    {
    public:
        // ���캯��
        CMemoryAlloc();
        ~CMemoryAlloc();

    public:
        // ���ڴ�ط���
        void* Malloc();

        // ���ڴ���ͷ�
        void Free(void* p);

    private:
        boost::pool<> m_pool;     // �ڴ��
        mutable DSMutex m_mutex;  // ��
    };

	// ���캯��
	template <class T>
	CMemoryAlloc<T>::CMemoryAlloc()
		: m_pool(sizeof(T))
	{}

	template <class T>
	CMemoryAlloc<T>::~CMemoryAlloc()
	{
	}

	// ���ڴ�ط���
	template <class T>
	void* CMemoryAlloc<T>::Malloc()
	{
		DSMutexLock lock(m_mutex);
		return m_pool.malloc();
	}

	// ���ڴ���ͷ�
	template <class T>
	void CMemoryAlloc<T>::Free(void* p)
	{
		DSMutexLock lock(m_mutex);
		m_pool.free(p);
	}

    /** @class class CMemoryPool
     * 
     *  @brief �Զ����ڴ��
     * 
     */
    template <class T, class U = CMemoryAlloc<T> >
    class CMemoryPool
    {
    public:
        CMemoryPool()
        {}

        // �����ڴ棬����ʹ��Free�����ͷ�
        void* Malloc();
        // �ͷ��ڴ�
        void Free(void* p);
    private:
        U m_allocMemery;
    };

	// �����ڴ棬����ʹ��Free�����ͷ�
	template <class T, class U>
	void* CMemoryPool<T, U>::Malloc()
	{
		void* p = m_allocMemery.Malloc();
		if (NULL == p)
		{
			throw std::bad_alloc();
		}

		return p;
	}

	// �ͷ��ڴ�
	template <class T, class U>
	void CMemoryPool<T, U>::Free(void* p)
	{
		if (NULL != p)
		{
			m_allocMemery.Free(p);
		}
	}
}

#define DECLARE_MEMORYPOOL(class_type) \
    public: \
        static void* operator new(size_t) \
        { \
            return memorypool.Malloc(); \
        } \
        static void operator delete(void* p) \
        { \
            memorypool.Free(p); \
        } \
    private: \
        static Common::CMemoryPool<class_type> memorypool;

#define DEFINE_MEMORYPOOL(class_type) \
    Common::CMemoryPool<class_type> class_type::memorypool;

#endif
