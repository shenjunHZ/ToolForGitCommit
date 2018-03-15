#ifndef __COMMON_BASE64_H__
#define __COMMON_BASE64_H__

#include "Common/CommonGlobal.h"
#include <string>

namespace Common
{
    //Base64����  
    COMMON_EXPORT std::string Base64Encode(const std::string& strInPut);  
    //Base64����  
    COMMON_EXPORT std::string Base64Decode(const std::string& strInPut);  
}

#endif // __COMMON_BASE64_H__
