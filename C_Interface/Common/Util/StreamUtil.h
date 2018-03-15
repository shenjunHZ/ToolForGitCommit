
#ifndef __COMMON_STREAMUTIL_H__
#define __COMMON_STREAMUTIL_H__

#include "Common/CommonGlobal.h"
#include <string>


#define  MEDIAPARSERBUFLEN	1*1024*1024		// ���������⻺���С	

namespace Common
{
	//�������� �������벥�ſ��Դ���vaxplayer.ini��һһӳ��
	typedef enum
	{
		STREAM_TYPE_UNKNOW = 0,			//δ֪
		STREAM_TYPE_DAHUA = 1,			//����
		STREAM_TYPE_HIK = 2,			//������
		STREAM_TYPE_H3C = 3,			//������
		STREAM_TYPE_HANBANG = 4,		//����˽����
	}stream_type_e;

	/*
		Э�鳧�̡����ſ⳧�̡���׺������ӳ���ϵ���£�
		
			Э�鳧��	���ſ⳧��	��׺��
	 ��		0			1		 .dav
	 ����		1			2		 .hav
	 ����		2			4		 .bav
	 ����		3			3		 .ts
	 ...		..			..		 ...
	*/

	/** brief	Э�鳧������ת���ɲ��ſ⳧������
		@param	IN int nProStreamType	Э�鳧������
		@return	���ſ⳧������ ����ֵ��ʾ��ö��stream_type_e
		@see    
	*/
	COMMON_EXPORT int ChangeStreamTypeFromProToVax(int nProStreamType);

	/** brief	���ݳ������͸��ĺ�׺��
		@param	IN int nStreamType	���ſ⳧������ ����ֵ��ʾ��ö��stream_type_e
		@param	IN string szOldName ԭʼ�ļ���
		@param	OUT string szNewName �޸ĺ���ļ���
		@return	true:���޸� false:δ�޸�
		@see    
	*/
	COMMON_EXPORT  bool ChangeFileExtName(int nStreamType, const std::string& szOldName, std::string& szNewName);

	/** brief	�����ļ�����׺��ȡ����ĳ�������
		@param	IN char szFilePath �ļ�ȫ·��
		@return	�������ͣ�����ֵ��ʾ��ö��stream_type_e
		@see    
	*/
	COMMON_EXPORT int GetStreamTypeByFileExtName(const char* szFilePath);

	/** brief	���ݾ���ĳ������ͻ�ȡ�ļ�����׺
		@param	[IN]int iStreamType ��������	����ֵ��ʾ��ö��stream_type_e
		@return	��׺��,��"."
		@see    
	*/
	COMMON_EXPORT std::string GetFileExtNameByStreamType( int iStreamType );
}

#endif
