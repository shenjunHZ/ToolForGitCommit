#pragma once

#ifndef XML_SPLITWINDOW_H
#define XML_SPLITWINDOW_H

#ifdef WIN32
#pragma warning(disable : 4996)
#endif

#include "Common/CommonGlobal.h"

class  COMMON_EXPORT XMLSplitWindow
{
public:
	XMLSplitWindow(int idx);
	~XMLSplitWindow(void);

	int getIndex(void) { return _index; }
	bool getEnable(void) { return _enable; }
	int getCombine(void) { return _combine; }
	int getX1(void) { return _x1; }
	int getY1(void) { return _y1; }
	int getX2(void) { return _x2; }
	int getY2(void) { return _y2; }
	void setSplitWindow(bool enable,int combine,int x1,int y1,int x2,int y2);
	XMLSplitWindow* clone(void);
	
private:
	int _index;		//�������
	bool _enable;	//�Ƿ�����
	int _combine;	//���
	int _x1;		//��ʼx����
	int _y1;		//��ʼy����
	int _x2;		//��ֹx����
	int _y2;		//��ֹy����
};


class SearchSplitWndByID
{
public:
	SearchSplitWndByID(int idx)
	{
		_index = idx;
	}
	~SearchSplitWndByID(void){}

	bool operator()(XMLSplitWindow* splitWindow)
	{
		return (_index == splitWindow->getIndex()) ? true : false;
	}

private:
	int _index;
};

#else
#endif

