/*
 *@file   Calendar.h
 *@brief  
 * 
 *@author wrb
 *@date   2015-02-04
 *
 */

#ifndef __DSGUI_CALENDAR_H
#define __DSGUI_CALENDAR_H

#include "DSGuiGlobal.h"
#include <QWidget>
#include <QtCore/QDate>

class QTableWidgetItem;
class QDate;

namespace Ui 
{
	class Calendar; 
}

namespace DSGUI
{
	class DSCalendarPrivate;
	/** @class DSCalendar
     *  @brief ����
     */
	class DS_GUI_EXPORT DSCalendar : public QWidget
	{
		Q_OBJECT

	public:
		typedef enum{
			Day,
			Mouth,
			Year,
		}DisplayType_e;


	public:
		DSCalendar(QWidget* pParent = NULL);
		~DSCalendar();

		//����ѡ�е����� ʱ��
		int SetSelDate(int iYear, int iMonth, int iDay, int iHour = 0, int iMinute = 0, int iSecond = 0);
		int SetDateTime(QDateTime dt);
		
		//��ȡѡ�е����� ʱ��
		int GetSelDate(int* pYear, int* pMonth, int* pDay, int* pHour = NULL, int* pMinute = NULL, int* pSecond = NULL);
		int GetDateTime(QDateTime& dt);

		//���ø��������Ƿ���¼��
		int	SetRecordDate(int iYear, int iMonth, int iDay, bool bHasRecrod = true);
		
		//�������¼��
		void ClearCellWidget();

		//������б������
		void ClearBackground();

		//���ƿ�ѡ�����ڷ�Χ
		int SetRestrcitDateRange(int nDates);

		//������������������
		int SetStartCalendar(bool);

		//��ȡ��ʼ����
		QDate GetDateStart();

		//��ȡ��������
		QDate GetDateEnd();

		//����չʾ��ʽ
		void ChangeDisplayType(DisplayType_e eType);

		//����ʱ��༭
		void SetTimeEditVisible(bool bVisible);

		//��ȡѡ�е����� ʱ��
		QDateTime GetSelectDate();

		//������������
		void SetCalendarName(QString strName);

	public slots:
		void OnStartDateTimeChanged(const QDate&);
		void OnEndDateTimeChanged(const QDate&);
		void OnCellDoubleClicked(int nRow,int nCol);

	protected:
		bool eventFilter(QObject * watched, QEvent * e);

	signals:
		void SgnDateTimeChanged();
		void SgnCalendarHide();

	private:
		QScopedPointer<DSCalendarPrivate> d_ptr;

	private:
		Q_DECLARE_PRIVATE(DSCalendar)
		Q_DISABLE_COPY(DSCalendar)
		Q_PRIVATE_SLOT(d_func(), void OnSelectionChanged())
		Q_PRIVATE_SLOT(d_func(), void OnNextMonth())
		Q_PRIVATE_SLOT(d_func(), void OnPreviewMonth())
		Q_PRIVATE_SLOT(d_func(), void OnShowYearWidget())
		Q_PRIVATE_SLOT(d_func(), void OnShowMonthWidget())
		Q_PRIVATE_SLOT(d_func(), void OnTabItemClicked(QTableWidgetItem*))
		Q_PRIVATE_SLOT(d_func(), void OnTableClick(QTableWidgetItem*))
		Q_PRIVATE_SLOT(d_func(), void OnDateTimeEditChanged(const QDateTime&))

	private:
		QScopedPointer<Ui::Calendar>	m_ptCalendarUI;
	};
}

#endif
