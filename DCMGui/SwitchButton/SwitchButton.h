#ifndef __DSGUI_SWITCHBUTTON_H
#define __DSGUI_SWITCHBUTTON_H

#include "DSGuiGlobal.h"
#include <QWidget>
#include <QTimer>

namespace DSGUI
{
	/**  @class DSSwitchButton
	 *   @brief ���ذ�ť
	 */
	class DS_GUI_EXPORT DSSwitchButton : public QWidget
	{
		Q_OBJECT
		Q_PROPERTY(QColor normalOpenBgColor READ normalOpenColor WRITE SetNormalOpenColor)
		Q_PROPERTY(QColor disableOpenBgColor READ disableOpenColor WRITE SetDisableOpenColor)
		Q_PROPERTY(QColor normalCloseBgColor READ normalCloseColor WRITE SetNormalCloseColor)
		Q_PROPERTY(QColor disableCloseBgColor READ disableCloseColor WRITE SetDisableCloseColor)
		Q_PROPERTY(QColor thumbColor READ thumbColor WRITE SetThumbColor)
		Q_PROPERTY(QColor disableThumbColor READ disableThumbColor WRITE SetDisableThumbColor)
		Q_PROPERTY(qint16 outHeight16 READ outHeight16 WRITE SetUserDefinedOutHeight)
		Q_PROPERTY(qint16 inHeight16 READ InHeight16 WRITE SetUserDefinedInHeight)
		Q_PROPERTY(qint16 width16 READ width16 WRITE SetUserDefinedWidth)
		Q_PROPERTY(qint16 margin16 READ margin16 WRITE SetUserDefinedMargin)
		Q_PROPERTY(qreal radius READ radius WRITE SetRadius)

	public:
		explicit DSSwitchButton(QWidget *parent = 0);

		// ���ؿ���״̬ - �򿪣�true �رգ�false
		bool isToggled() const;
		// ���ÿ���״̬
		void setToggle(bool checked);

	protected:
		// ���ƿ���
		void paintEvent(QPaintEvent *event) ;

		// ��갴���¼�
		void mousePressEvent(QMouseEvent *event) ;

		// ����ͷ��¼� - �л�����״̬������toggled()�ź�
		void mouseReleaseEvent(QMouseEvent *event) ;

		// ��С�ı��¼�
		void resizeEvent(QResizeEvent *event) ;

		// ȱʡ��С
		QSize sizeHint() const ;
		QSize minimumSizeHint() const ;

signals:
		// ״̬�ı�ʱ�������ź�
		void toggled(bool checked);

	private slots:
		// ״̬�л�ʱ�����ڲ�������Ч��
		void onTimeout();

	private:
		bool		m_bChecked;				// �Ƿ�ѡ��
		QTimer		m_timer;				// ��ʱ��
		qreal		m_nX;					// x������
		qreal		m_nY;					// y������

	private /*property*/:
		QColor		m_noramlOpenBgClr;		// �����򿪱���ɫ
		QColor		m_disableOpenBgClr;		// ���ô򿪱���ɫ
		QColor		m_normalCloseBgClr;		// �����رձ���ɫ
		QColor		m_disableCloseBgClr;    // ���ùرձ���ɫ
		QColor		m_thumbColor;			// Ĵָ��ɫ
		QColor		m_disbaleThumbColor;	// ����Ĵָ��ɫ
		qreal		m_radius;				// Բ��
		qint16		m_nOutHeight;			// ��Բ�߶�
		qint16		m_nInHeight;			// ��Բ�߶�
		qint16		m_nWidth;				// ���
		qint16		m_nMargin;				// ��߾�
	private:
		inline QColor normalOpenColor()const
		{
			return m_noramlOpenBgClr;
		}
		inline void SetNormalOpenColor(QColor color)
		{
			m_noramlOpenBgClr = color;
		}
		inline QColor disableOpenColor()const
		{
			return m_disableOpenBgClr;
		}
		inline void SetDisableOpenColor(QColor color)
		{
			m_disableOpenBgClr = color;
		}
		inline QColor normalCloseColor()const
		{
			return m_normalCloseBgClr;
		}
		inline void SetNormalCloseColor(QColor color)
		{
			m_normalCloseBgClr = color;
		}
		inline QColor disableCloseColor()const
		{
			return m_disableCloseBgClr;
		}
		inline void SetDisableCloseColor(QColor color)
		{
			m_disableCloseBgClr = color;
		}
		inline QColor thumbColor()const
		{
			return m_thumbColor;
		}
		inline void SetThumbColor(QColor color)
		{
			m_thumbColor = color;
		}
		inline QColor disableThumbColor()const
		{
			return m_disbaleThumbColor;
		}
		inline void SetDisableThumbColor(QColor color)
		{
			m_disbaleThumbColor = color;
		}
		inline qreal radius()const
		{
			return m_radius;
		}
		inline void SetRadius(qreal r)
		{
			m_radius = r;
		}
		inline qint16 outHeight16()const
		{
			return m_nOutHeight;
		}
		inline void SetUserDefinedOutHeight(qint16 h)
		{
			m_nOutHeight = h;
		}
		inline qint16 InHeight16()const
		{
			return m_nInHeight;
		}
		inline void SetUserDefinedInHeight(qint16 h)
		{
			m_nInHeight = h;
		}
		inline qint16 width16()const
		{
			return m_nWidth;
		}
		inline void SetUserDefinedWidth(qint16 w)
		{
			m_nWidth= w;
		}
		inline qint16 margin16()const
		{
			return m_nMargin;
		}
		inline void SetUserDefinedMargin(qint16 m)
		{
			m_nMargin = m;
		}
	};
}

#endif // 
