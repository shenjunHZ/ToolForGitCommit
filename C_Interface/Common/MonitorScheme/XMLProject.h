
#ifndef XML_PROJECT_H
#define XML_PROJECT_H

#include "Common/CommonGlobal.h"
#include "AX_API/platform.h"
#include "MonitorScheme/XMLItemTask.h"
#include <string.h>

#ifdef WIN32
#pragma warning(disable : 4996)
#endif

class COMMON_EXPORT XMLProject
{
public:
	XMLProject(const char* name);
	~XMLProject(void);

public:
	bool isTaskItemExist(uint32 taskId, uint32 beginTime);
	XMLItemTask* getTaskItem(uint32 taskId, uint32 beginTime);

	//����addTaskItem֮ǰ�������isTaskItemExistȷ��taskδ��ӹ�
	//modified by fengjian 2012.9.1
	//XMLItemTask* addTaskItem(uint32 taskId, uint32 beginTime, uint32 endTime);
	XMLItemTask* addTaskItem(uint32 taskId, uint32 beginTime, uint32 endTime, uint32 runTime = 0 );
	//modified end 
	int delTaskItem(uint32 taskId); //ɾ�����и�ID����������
	int delTaskItem(uint32 taskId, uint32 beginTime); //��Ϊ����һ������������Σ���������ʱ����ȷ��Ψһ�ԣ�gaowei 09-04-06
	void clearTaskItems(void);

	//������������ʵ�ֶ�ͨ���ı�����firstChannel����NULL��˵��û�нڵ㣬nextChannel����NULL��˵����������
	XMLItemTask* firstTaskItem(void);
	XMLItemTask* nextTaskItem(void);

public:
	int copy(XMLProject* srcProj);
	XMLProject* clone(void);

public:
	char		_name[64];
	int32		_mode;			//�ƻ�ģʽ	add by zhaojian 2010-05-10 add by fengjian 2012.9.1
private:
	ITaskList	_tasks;
	ITaskEntry	_current_task_entry;
};

class SearchProjectByName
{
public:
	SearchProjectByName(const char* name)
	{
		strcpy(_name, name);
	}
	~SearchProjectByName(void){}

	bool operator()(XMLProject* project)
	{
		return strcmp(project->_name, _name) == 0;
	}

private:
	char	_name[64];
};

#include <list>
typedef std::list<XMLProject*> ProjectList;
typedef ProjectList::iterator ProjectEntry;

#endif
