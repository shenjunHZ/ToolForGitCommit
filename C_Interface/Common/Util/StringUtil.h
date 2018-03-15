
#ifndef __COMMON_STRINGUTIL_H
#define __COMMON_STRINGUTIL_H

#include "Common/CommonGlobal.h"
#include "boost/format.hpp"
#include <string>
#include <sstream>
#include <assert.h>

namespace Common
{
	// ָ��ת�ַ�,��pStrΪ��ֵʱ,Ĭ�Ϸ���strDefaultValue
	inline std::string PToString(const char* pStr, const std::string& strDefaultValue = "")
	{
		if (NULL == pStr)
		{
			return strDefaultValue;
		}

		return pStr;
	}

	// ָ��תint,��pStrΪ��ֵʱ,Ĭ�Ϸ���nDefaultValue
	inline int PToInt(const char* pStr, int nDefaultValue = 0)
	{
		if ( NULL == pStr )
		{
			return nDefaultValue;
		}

		return atoi(pStr);
	}

	// ָ��תlong,��pStrΪ��ֵʱ,Ĭ�Ϸ���nDefaultValue
	inline long PToLong(const char* pStr, long nDefaultValue = 0)
	{
		if ( NULL == pStr )
		{
			return nDefaultValue;
		}

		return atol(pStr);
	}

	// ָ��תfloat,��pStrΪ��ֵʱ,Ĭ�Ϸ���nDefaultValue
	inline float PToFloat(const char* pStr, float nDefaultValue = 0.0)
	{
		if ( NULL == pStr )
		{
			return nDefaultValue;
		}

		return (float)atof(pStr);
	}

    template <class T>
    inline std::string TToString(const T& source)
    {
        std::stringstream ss;
        ss << source;
        return ss.str();
    }

    template <size_t N>
    inline std::string ArrayToString(const unsigned char (&szArray)[N])
    {
        char szDuplicate[N + 1] = { 0 };
        memcpy(szDuplicate, szArray, N);
        return szDuplicate;
    }

    template <size_t N>
    inline void StringToArray(char (&szArray)[N], const char* pStr)
    {
        assert(pStr != NULL); 
        memset(szArray, 0, N);
        strncpy((char*)szArray, pStr, N);
    }

    template <size_t N>
	inline void StringToArray(char (&szArray)[N], const std::string& str)
    {
        StringToArray(szArray, str.c_str());
    }

	template<class TFirst>
	void StringFormat(boost::format& fmt, const TFirst& first)
	{
		fmt % first;
	}

	template<class TFirst, class TOther>
	void StringFormat(boost::format& fmt, const TFirst& first, const TOther& second)
	{
		StringFormat(fmt, first);
		StringFormat(fmt, second);
	}

	/*��ͳc���Է��
	cout << boost::format("\n\n%s" 
		"%1t ʮ���� = [%d]\n" 
		"%1t ��ʽ����ʮ���� = [%5d]\n" 
		"%1t ��ʽ��ʮ���ƣ�ǰ��'0' = [%05d]\n" 
		"%1t ʮ������ = [%x]\n" 
		"%1t �˽��� = [%o]\n" 
		"%1t ���� = [%f]\n" 
		"%1t ��ʽ���ĸ��� = [%3.3f]\n" 
		"%1t ��ѧ���� = [%e]\n" 
		) % "example :\n" % 15 % 15 % 15 % 15 % 15 % 15.01 % 15.01 % 15.01 << endl; 

	//.net�ķ��
	cout << boost::format("%1%" 
		"%1t ʮ���� = [%2$d]\n" 
		"%1t ��ʽ����ʮ���� = [%2$5d]\n" 
		"%1t ��ʽ��ʮ���ƣ�ǰ��'0' = [%2$05d]\n" 
		"%1t ʮ������ = [%2$x]\n" 
		"%1t �˽��� = [%2$o]\n" 
		"%1t ���� = [%3$f]\n" 
		"%1t ��ʽ���ĸ��� = [%3$3.3f]\n" 
		"%1t ��ѧ���� = [%3$e]\n" 
		) % "example :\n" % 15 % 15.01 << endl; 
	**********************************************************/
	// ����StringFormat("%s--%s", "str1", "str2");
	// ����StringFormat("%1--%2", "str1", "str2");
	template<class TFirst>
	std::string StringFormat(const char* pFormat, const TFirst& first)
	{
		boost::format fmt(pFormat);
		StringFormat(fmt, first);
		return fmt.str();
	} 

	template<class TFirst, class TOther>
	std::string StringFormat(const char* pFormat, const TFirst& first, const TOther& second)
	{
		boost::format fmt(pFormat);
		StringFormat(fmt, first, second);
		return fmt.str();
	} 
}

#endif
