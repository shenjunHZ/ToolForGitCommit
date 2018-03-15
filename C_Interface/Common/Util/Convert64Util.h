#ifndef __CONVERT64UTIL_H__
#define __CONVERT64UTIL_H__
/*
�ࡢ������صķ���
*/
#include "Common/CommonGlobal.h"
#include <string>

namespace Common
{

	COMMON_EXPORT  std::string enBase64( const char* inbuf, size_t inbufLen );
	COMMON_EXPORT  std::string enBase64( const std::string &inbuf);
	// TODO : �ӿ����� maxOutbufLen ����, ���뱣֤outbuf�㹻��
	COMMON_EXPORT  int  deBase64( std::string src, char* outbuf );
	COMMON_EXPORT  std::string deBase64( std::string src);

}


#endif
