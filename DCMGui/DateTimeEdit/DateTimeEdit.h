#ifndef DSDATETIMEEDIT_H
#define DSDATETIMEEDIT_H

#include "DSGuiGlobal.h"
#include <QDateTimeEdit>
#include <qtoolbutton.h>

namespace DSGUI
{
	class DSCalendar;

	class DS_GUI_EXPORT DSDateTimeEdit : public QDateTimeEdit
	{
		Q_OBJECT

	public:
		DSDateTimeEdit(QWidget *pParent=NULL);
		~DSDateTimeEdit();

		void SetStartCalendar(bool bStartCalendar);
		int SetRecordDate(int iYear, int iMonth, int iDay, bool bHasRecrod = true);
		void ClearHasRecord();
		void SetRestrcitDateRange(int iDays);
		void SetCurTime(const QDateTime&);

	public slots:
		void OnStartDateTimeChanged(const QDate&);

	protected:
		virtual void mousePressEvent(QMouseEvent *pEvent);
		virtual bool eventFilter(QObject* pObj,QEvent *pEvent);

signals:
		void SgnYearMonthChanged(int iYear,int iMonth);
		void SgnStartDateChanged(const QDate&);

	private slots:
		void OnUpdateTime();
		void OnCalendarHide();

	private:
		void ShowCalendar();

	private:
		DSCalendar*	m_pCalendar;

		bool		m_bStartCalendar;	//�Ƿ�����ʼEdit
		QDate		m_StartDate;		//��ʼ����
		int			m_iRestrictDays;	//�������ڶ�

		int			m_iYear;			//��ǰ���
		int			m_iMonth;			//��ǰ�·�
	};
}

#endif // DSDATETIMEEDIT_H
