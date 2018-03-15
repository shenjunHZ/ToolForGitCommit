// DATECALENDAR_H


/*
 *@file   DateCalendar.h
 *@brief  ����������չʾ�꣬�£��ܣ���������ʽ��ѡ������
 * 
 *@author 28100
 *@date   
 *
 */
#ifndef __DSGUI_DATECALENDAR_H
#define __DSGUI_DATECALENDAR_H

#include "DSGuiGlobal.h"
#include <QLabel>
#include "Calendar/Calendar.h"

namespace DSGUI
{
	class DS_GUI_EXPORT DSDateCalendar : public QLabel
	{
		Q_OBJECT

	public:
		DSDateCalendar(QWidget *parent);
		~DSDateCalendar();

		void InitDate(QDateTime& dateTime);
		void ChangeDisplayType(DSCalendar::DisplayType_e eType);

	protected:
		void mousePressEvent(QMouseEvent * e);

	private slots:
		void OnDateTimeChanged();
		void OnCalendarHide();

	private:
		QString DtConvToString(QDateTime& dsTime);

	private:
		DSCalendar* m_pCalendar;
	};
}

#endif 

