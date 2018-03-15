/*
* Copyright (c) 
* All rights reserved.
*
* �ļ����ƣ�XMLMonitorScheme.h
* �ļ���ʶ��
* ժ����Ҫ��
*

* ��ǰ�汾��1.0
* ԭ���ߡ���
* ������ڣ�
* �޶���¼������
*/
#ifndef XML_MONITOR_SCHEME_H
#define XML_MONITOR_SCHEME_H

#include "Common/CommonGlobal.h"
#include "MonitorScheme/XMLProject.h"
#include "MonitorScheme/XMLTask.h"
#include "MonitorScheme/XMLOsdTxt.h"
/*#include "tinyxml/tinyxml.h"*/
#include "pugixmldsl/pugiassist.h"

class COMMON_EXPORT XMLMonitorScheme
{
	typedef enum
	{
		PARSER_SUCCESS = 0,				// ��������ɹ�
		PARSER_FAILED,					// ��������ʧ��
		PARSER_NULL,					// �սڵ�
		PARSER_STATUS_ERROR,			// ״̬����
		PARSER_ATTRIBUTE_ERROR,			// ���Դ���
		PARSER_OUTMEMORY,				// ���治��
	}EnumParserState;
public:
	XMLMonitorScheme(void);
	~XMLMonitorScheme(void);

	int loadFile(const char* filename);
	int saveFile(const char* filename);

	int formStream(const char* data);
	int toStream(char* buf, int buflen, int& len);

	const char* getErrorMsg(void) { return _errorMsg; }

public:
	bool isProjectExist(const char* name);
	XMLProject* getProject(const char* name);
	XMLProject* addProject(const char* name); //����֮ǰ�������isProjectExist��ȷ�����Ƶ�Ψһ��
	int delProject(const char* name);
	void clearProjects(void);
	int addProject(XMLProject* project);

	//������������ʵ�ֶԼƻ��ı�����firstProject����NULL��˵��û�нڵ㣬nextProject����NULL��˵����������
	XMLProject* firstProject(void);
	XMLProject* nextProject(void);

	bool isTaskExist(const char* name);
	XMLTask* getTask(const char* name);
	XMLTask* getTask(uint32 taskId); //��project�еĵ�һ��task ID����Ҫʹ�øýӿڵõ�task����Ϣ
	XMLTask* addTask(const char* name, int windows,const char* desc = ""); //����֮ǰ�������isTaskExist��ȷ�����Ƶ�Ψһ��
	int delTask(const char* name);
	int delTask(uint32 taskId);
	void clearTasks(void); //�����task֮��projectҲû�����壬���Ե��õ�ͬʱ�������clearProjects
	int addTask(XMLTask* task); //��¡��ʱ�����

	//������������ʵ�ֶ�����ı�����firstTask����NULL��˵��û�нڵ㣬nextTask����NULL��˵����������
	XMLTask* firstTask(void);
	XMLTask* nextTask(void);

	XMLOsdTxt& getOsdTxt(void) { return _osdTxt; }

protected:
// 	int parseXmlInside(TiXmlDocument& doc);
// 	int packetXmlInside(TiXmlDocument& doc);
	int parseXmlInside(CPugiXmlDocument& doc);
	int packetXmlInside(CPugiXmlDocument& doc);

	void delTaskInProjects(uint32 taskId);
	uint32 getTaskId(void) { return ++_taskId; }

private:
	ProjectList	 _projects;
	ProjectEntry _current_project_entry;
	TaskList	 _tasks;
	TaskEntry    _current_task_entry;

	uint32		 _taskId;			//�Զ�����task��id

	char		 _errorMsg[1024];

	XMLOsdTxt	 _osdTxt;
};

#endif
