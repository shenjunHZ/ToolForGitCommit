
#ifndef XML_WINDOW_H
#define XML_WINDOW_H

#include "Common/CommonGlobal.h"
#include "MonitorScheme/XMLChannel.h"

class COMMON_EXPORT XMLWindow
{
public:
	XMLWindow(int idx);
	~XMLWindow(void);

	int getIndex(void) { return _index; }
	void setIndex(int idx) { _index = idx; }

	XMLWindow* clone(void);

public:
	//����ͬID�ڵ㣬�ʷ�ֹ�˶��ӿ�
	//bool isChannelExist(const char* id);
	//XMLChannel* getChannel(const char* id);

	XMLChannel* addChannel(const char* id, int subStream, uint32 timeSpan, uint32 presetPos,int rotateDegree=0,int nodeType=0);//modified by fengjian 2012.8.14
	int delChannel(const char* id);
	void clearChannels(void);
	int addChannel(XMLChannel* channel); //��¡ʱ����

	//������������ʵ�ֶ�ͨ���ı�����firstChannel����NULL��˵��û�нڵ㣬nextChannel����NULL��˵����������
	XMLChannel* firstChannel(void);
	XMLChannel* nextChannel(void);

	//ѭ�������һ��ͨ����Ҳ����˵�������ǰͨ�������һ��ͨ������ô��һ��ͨ�����ǵ�һ����
	//IDΪ��ʱ��Ĭ�Ϸ����׸�����Ϊ��ʱ��ID���ã�ֱ�Ӹ��ݳ�Աֵ,������һ���ڵ�  09-05-18 yulu
	XMLChannel* cycleNextChannel(const char* currId);
	
private:
	int				_index;	//�������
	IChannelList	_channels;
	IChannelEntry	_current_chnl_entry;		//Ӧ����first����
	IChannelEntry	_cycle_chnl_entry;			//Ӧ����cycle����  09-05-18
};

#endif
