#ifndef __COMMON_DISKUTIL_H__
#define __COMMON_DISKUTIL_H__

#include "Common/CommonGlobal.h"
#include "Common/BasicTypes.h"
#include <vector>
#include <string>

namespace Common
{
	// ������Ϣ
	struct DiskSpaceInfo
	{
		unsigned long long iCapacity;  // ������
		unsigned long long iFree;      // ʣ��
		unsigned long long iAvailable; // ����
	};

	// ��ȡ������Ϣ
	COMMON_EXPORT bool GetDiskSpace(const char* pPathName, DiskSpaceInfo& struDiskSpaceInfo );
}

#endif // __COMMON_DISKUTIL_H__
