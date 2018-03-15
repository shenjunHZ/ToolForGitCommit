
#ifndef XML_CHANNEL_H
#define XML_CHANNEL_H
#include "Common/CommonGlobal.h"
#include "MonitorScheme/XMLMonitorDefine.h"
#include "AX_API/platform.h"
#include <string.h>

#ifdef WIN32
#pragma warning(disable : 4996)
#endif

class COMMON_EXPORT XMLChannel
{
public:
	XMLChannel(void);
	~XMLChannel(void);

	XMLChannel* clone(void);

public:
	//uint32	_id;			//����ͷID
	char		_id[DEVICE_ID_LEN];		//��IPC��ID���ַ��������Ըĳ��ַ�����gaowei 08-11-22
	int			_subStream;		//��������
	uint32		_timeSpan;		//ͣ��ʱ��
	int			_presetPos;		//Ԥ��λ
	char		_devId[DEVICE_ID_LEN];		//�豸ID
	int			_channelNo;		//ͨ����
	int			_devType;		//�豸����
	char		_osdText[256];  //������Ϣ
	char        _devInfo[256];  //�豸������Ϣ
	int         _rotateDegree;//��ת�Ƕȣ�0Ϊ����ת //DSS_C
	int         _nodeType;      //channel type add by fengjian 2012.8.14
};

class SearchChannelByID
{
public:
	SearchChannelByID(const char* id)
	{
		strncpy(_id, id, sizeof(_id));
	}
	~SearchChannelByID(void){}

	bool operator()(XMLChannel* channel)
	{
		return 0 == strcmp(_id, channel->_id);
	}

protected:
	SearchChannelByID()
	{// for flexelint Info(1712)
		_id[0] = '\0';
	}

private:
	char _id[DEVICE_ID_LEN];
};

#include <list>
typedef std::list<XMLChannel*> IChannelList;
typedef IChannelList::iterator IChannelEntry;

#endif
