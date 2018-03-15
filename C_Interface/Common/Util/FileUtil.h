#ifndef __COMMON_FILEUTIL_H__
#define __COMMON_FILEUTIL_H__

#include "Common/CommonGlobal.h"
#include <vector>
#include <string>

namespace Common
{
	// ��ȡ�ļ��б�
	COMMON_EXPORT std::vector<std::string> GetFileList(const char* pDirName);

	// ��ȡ�ļ����б�
	COMMON_EXPORT std::vector<std::string> GetFileNameList(const char* pDirName);

	// �����ļ���
	COMMON_EXPORT bool MakeDir(const char* pDirName);

	// �����ļ��� ����ԭ��c����
	COMMON_EXPORT bool MakeDirEx(const char* pDirName);

	// ɾ���ļ�
	COMMON_EXPORT bool RemoveFile(const char* pFileName);

	// ����windows �ļ�������Ч�ԣ���Ч���ַ�ʹ�á�_���滻. 
	COMMON_EXPORT std::string GetValidFileName(const char* szFileName);

	// �ж��ļ��Ƿ����
	COMMON_EXPORT bool FileExists(const char* pFilePath);

	// �������ļ�
	COMMON_EXPORT bool RenameFile(const char* pOldFileName, const char* pNewFileName);

	// �����ļ�
	COMMON_EXPORT bool CopyFileFunc(const char* pSrcFile, const char* pDstFile);

	// ��ȡ��ִ�г���·��
	COMMON_EXPORT std::string GetCurDirPath();
}

#endif