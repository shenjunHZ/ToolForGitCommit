#ifndef __COMMON_ERRORCODE_H__
#define __COMMON_ERRORCODE_H__

// ͨ�ô���[-99��0]
#define	DCM_RET_SUCCESS						0				// ���سɹ�
#define	DCM_UNKNOWN_ERROR			        -1		        // δ֪����
#define	DCM_FUNCTION_CALL_ERROR			    -2		        // �ڲ��������ô���
#define	DCM_INVAILD_PARAM					-3			    // ��Ч����

// ���ݿ�
#define DCM_OPEN_DB_FAILED                  -10             // �����ݿ�ʧ��
#define DCM_CLOSE_DB_FAILED				    -11		        // �ر����ݿ�ʧ��

// ErrorAnalyser
#define DCM_ERROR_QUERY_FAILED			    -15		        // ��ѯ������ʧ��

// Rest ������[-119, -100]
#define DCM_REST_INIT_FAILED                -100			// Rest��ʼ��ʧ��
#define DCM_REST_REQUEST_TIMEOUT            -101			// Rest����ʱ���˴����뱣�ָ�Rest�ڲ�һ��
#define DCM_USER_TOKEN_INVALID				-102			// ��Ч���û�token

// ��½[-149, -130]

// Ԥ��[-299, -200]
#define DCM_PREVIEW_OPEN_SOUND_FAILED		-200			// Ԥ��������ʧ��
#define DCM_PREVIEW_TALKING_WITH_OTHER		-201			// ������ʧ�ܣ������������豸�Խ�


// �ط�[-399, -300]
#define DCM_INVAILD_SS						-300			//�޿��õ�ss����
#define DCM_CAPTURE_FRAME_INFO_FAILED		-301			//ץȡ�طſ���ʧ��

// RRSPSDK ������[-499, -400]
#define DCM_RTSP_UDP_LISTEN_FAILED          -400			// UDP����ʧ��
#define DCM_RTSP_CONNECT_SERVER_FAILED		-401			// ���ӷ���ʧ��
#define DCM_RTSP_SENDDATA_FAILED			-402			// ���ݷ���ʧ��
#define DCM_RTSP_COMMAND_CANCELED			-403			// �����ѱ�ȡ��
#define DCM_RTSP_PORT_PARSE_FAILED		    -404			// �˿ڽ���ʧ��

// ��̨[-599, -500]
#define DCM_PTZ_CAMERA_OCCUPY				-500			// ����ͷ�������û�����
#define DCM_PTZ_OCCUPY_BY_OTHER_USER		-501			// �������û�ռ��
#define DCM_PTZ_SERVEROFFLINE				-502			// REST��������

// FTP[-699, -600]
#define DCM_FTP_ERROR_UNKNOW					-601
#define DCM_FTPCURL_ERROR						-602			// ����curl���ش���
#define DCM_FTPCURL_LOCALFILE_NOT_OPEN			-603			// ����curl����δ�ҵ������ļ�
#define DCM_FTPCURL_LOCALFILE_NOT_READ			-604			// ����curl���ش򿪱����ļ�����
#define DCM_FTPCURL_FTPFILE_ERROR				-605			// ����curl���ز���Զ���ļ�����
#define DCM_FTPCURL_FREE_ERROR					-606			// ����curl�����ͷų���

// �Խ�[-799, -700]
#define DCM_TALK_PARAM_UNMATCH				-701			// �Խ�������ƥ��

#define DCM_QUERYREC_FAILED					-107302			//��ѯ¼��ʧ��
#define DCM_QUERYREC_NORECORD               -107303           //��ѯ¼����¼��
#define DCM_QUERYREC_SUBSSCRIBER_NONE       -107304           //��ѯ�����߲����� 
#define DCM_QUERYREC_RET_DEV_DISCONNECT     -107305           //��ѯ���� �豸����
#define DCM_QUERYREC_RET_SENFAILED          -107306           //��ѯ ������Ϣʧ��
#define DCM_QUERYREC_RET_TIMEOUT            -107307           //��ѯ¼�� ��ѯ��ʱ
#define DCM_QUERYREC_RET_BUSY               -107308           //��ѯ¼�� ��ѯ��æ

#define DCM_QUERYTAG_FAILED                 -107309           //��ѯ¼���ǩʧ��
#define DCM_QUERYTAG_NOTAG                  -107310           //��ѯ¼���ǩ0��
#define DCM_QUERYTAG_TOOQUICK				-107311			//��ѯ¼���ǩ�ٶȹ���

#define DCM_QUERYLOCK_FAILED				-107312			//��ѯ¼������ʧ��
#define DCM_QUERYLOCK_NOLOCK				-107313			//��ѯ¼������0��
#define DCM_QUERYLOCK_BUSY					-107314			//��ѯ¼������ ��ѯ��æ

#define DCM_DOWNLOAD_WRITTENFAIL			-107315			//����д�ļ�ʧ��



#endif // __COMMON_ERRORCODE_H__
