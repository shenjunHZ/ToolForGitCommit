#pragma once

namespace Common
{
	struct struStream
	{
		// ��������
		enum StreamType
		{
			AllStream				= 0,									// ȫ��
			MainStream				= 1,									// ������
			SubStream				= 2,								    // ������
			ThirdStream				= 3,									// ������
			LocalSignalStream		= 5,									// �����ź�
		};
	};

	#define BASIC_IP_LEN							46			// Զ��IP��ַ����
	#define BASIC_USER_NAME_LEN						64          // �豸��½�û����ĳ���
	#define BASIC_PASSWORD_LEN						64	        // ���볤��
	#define BASIC_CHL_ID_LEN						64			// ͨ��ID����
	#define BASIC_DEV_ID_LEN						64			// �豸ID����
	#define BASIC_MATRIXID_LEN						32			// ���������id

}
