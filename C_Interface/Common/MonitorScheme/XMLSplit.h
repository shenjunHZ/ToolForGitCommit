#pragma once
#ifndef XML_SPLIT_H
#define XML_SPLIT_H

#ifdef WIN32
#pragma warning(disable : 4996)
#endif

#include "Common/CommonGlobal.h"
#include <list>
#include "MonitorScheme/XMLSplitWindow.h"

#define MAX_WINDOWS 256

typedef std::list<XMLSplitWindow*> ISplitWindowList;
typedef ISplitWindowList::iterator ISplitWindowEntry;

/*
�Դ��ڷָ���Ϣ�ı��������ݴ�����ѭ��
*/

class COMMON_EXPORT XMLSplit
{
public:
	XMLSplit(int row,int col,int count);
	~XMLSplit(void);

public:
	XMLSplitWindow* firstSplitWindow();
	XMLSplitWindow* nextSplitWindow();
	XMLSplitWindow* getSplitWindow(int iIndex);
	XMLSplit* clone();	
	void createSplitWindow();
	int getRow(void) { return _row; }
	int getCol(void) { return _col; }
	int getCount(void) { return _count; }
private:
	void clearSplitWindow();
	int addSplitWindow(XMLSplitWindow* splitWindow);


private:
	int _row;		//�ָ������
	int _col;		//�ָ������
	int _count;		//�ָ�Ĵ�������

private:
	ISplitWindowList _splitWindows;				//�����б�
	ISplitWindowEntry _current_splitwnd_entry;	//ָ�򴰿��б�ǰλ�õĵ�����
};
#else
#endif

