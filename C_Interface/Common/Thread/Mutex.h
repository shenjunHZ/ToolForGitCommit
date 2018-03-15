#ifndef __COMMON_MUTEX_H__
#define __COMMON_MUTEX_H__

#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/recursive_mutex.hpp>
#include <boost/thread/locks.hpp>
#include <boost/thread/shared_mutex.hpp>

namespace Common
{
    //////////////////////////////////////////////////////////////////////////
    //��ռ��
    typedef boost::mutex DSMutex;                            // ��ռ��
    typedef boost::unique_lock<boost::mutex> DSMutexLock;    // ��ռ��Lock

    //////////////////////////////////////////////////////////////////////////
    //�ݹ���
    typedef boost::recursive_mutex DSRecursiveMutex;                   // �ݹ���(������ʹ�ã�����ʹ��DSMutex)
    typedef boost::recursive_mutex::scoped_lock DSRecursiveMutexLock;  // �ݹ���Lock

    //////////////////////////////////////////////////////////////////////////
    //��д��
    // ��д�������������ᴴ��������������������ʹ�ã�����ʹ�ö�ռ��DSMutex��
    typedef boost::shared_mutex DSRWMutex; 
    // ����
    typedef boost::shared_lock<DSRWMutex> DSReadLock; 
    // д��
    typedef boost::unique_lock <DSRWMutex> DSWriteLock; 
}

#endif // __COMMON_MUTEX_H__
