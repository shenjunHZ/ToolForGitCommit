/*
 *@file   Point.h
 *@brief  ��װ�Ե�����Ķ���ӿ�
 * 
 *@author cc
 *@date   2014-07-02
 *
 */

#ifndef _DSGUI_POINT_H
#define _DSGUI_POINT_H

#include "DSGuiGlobal.h"
#include <QPoint>

namespace DSGUI
{
	/** @class DSPoint
	  * @brief �������
	  */
    class DS_GUI_EXPORT DSPoint : public QPoint
	{
	public:
        DSPoint();
        DSPoint(int iX, int iY);

    public:
        // ��ptGlobalPosת������Ļ�ϵ���Ч��
        static QPoint GetDesktopAvailablePoint(const QPoint& ptGlobalPos);
    public:
        // ��ֵ����
        DSPoint& operator = (QPoint pt);
	};
}


#endif // _DSGUI_POINT_H

