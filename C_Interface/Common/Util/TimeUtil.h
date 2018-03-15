#ifndef __COMMON_TIMEUTIL_H__
#define __COMMON_TIMEUTIL_H__

#include "Common/CommonGlobal.h"
#include <string>

namespace Common
{
	// ��ȡ��ǰʱ��
	COMMON_EXPORT time_t GetCurrentTime();

	// time_tת��Ϊ�ַ���
	COMMON_EXPORT std::string TimeToISOString(time_t tmDateTime, const char* pFormat = "%Y-%m-%d %H:%M:%S");
}

#endif // __COMMON_TIMEUTIL_H__
