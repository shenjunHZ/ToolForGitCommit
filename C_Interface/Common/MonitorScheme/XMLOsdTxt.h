/*
* Copyright (c) 
* All rights reserved.
*
* �ļ����ƣ�XMLOsdTxt.h
* �ļ���ʶ��
* ժ����Ҫ��
*

* ��ǰ�汾��1.0
* ԭ���ߡ���
* ������ڣ�
* �޶���¼������
*/
#ifndef _XML_OSD_TXT_H_
#define _XML_OSD_TXT_H_
#include "Common/CommonGlobal.h"
#include "AX_API/platform.h"

class COMMON_EXPORT XMLOsdTxt
{
public:
	XMLOsdTxt(void);
	~XMLOsdTxt(void);

	XMLOsdTxt* clone(void);
	int copy(XMLOsdTxt* src);

public:
	int		 _enable; //ʹ��
	uint16	 _posX;   //���ӵ�����
	uint16   _posY;
	uint32   _color; //������ɫ
	int      _fontSize; //�����С
	int		 _fontType; //����
	int		 _isBold;
	int		 _isTransparent;
	uint32   _bkColor; //����ɫ
};

#endif
