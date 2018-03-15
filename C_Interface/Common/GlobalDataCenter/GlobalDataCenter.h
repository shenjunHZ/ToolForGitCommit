/**
 * Copyright (c) 
 * All rights reserved.
 *
 * �ļ����ƣ�GlobalDataCenter.h
 * �ļ���ʶ��
 * ժ����Ҫ��
 *
 * version��1.0
*/

#pragma once

#include "Common/CommonGlobal.h"
#include "Common/Pattern/Singleton.h"

namespace Common
{
	class CGlobalDataCenterPrivate;
	class COMMON_EXPORT CGlobalDataCenter : public CSingleton<CGlobalDataCenter>
	{
		friend class CSingleton<CGlobalDataCenter>;

	public:
		/**
		 * @brief	���ÿ�ִ�г���·��
		 * @param	[IN] strDirPath	��ִ�г���·��
		 * @return
		 * @note	���ڳ����ʼ��ʱ����
		 */
		void SetCurrentDirPath(const std::string& strDirPath);

		/**
		 * @brief	��ȡ��ִ���ļ�·��
		 * @return
		 */
		std::string GetCurrentDirPath();

		/**
		 * @brief	���ÿ�ִ�г���·��
		 * @param	[IN] strDirPath ��ִ�г���·��	utf8����
		 * @return
		 * @note	sqlite��Ҫutf8�ı���
		 * @see
		 */
		void SetCurrentDirPath_UTF8(const std::string& strDirPath);

		/**
		 * @brief	��ȡ��ִ���ļ�·��
		 * @return
		 * @note	��ȡ��·����utf8����
		 */
		std::string GetCurrentDirPath_UTF8();

	public:
		CGlobalDataCenter();
		~CGlobalDataCenter();
	private:
		DS_DECLARE_PRIVATE(CGlobalDataCenter);
		CGlobalDataCenterPrivate* d_ptr;
	};

} // end namespace common
