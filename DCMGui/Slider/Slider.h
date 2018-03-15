/*
 *@file   Slider.h
 *@brief  
 * 
 *@author cc
 *@date   2014-06-30
 *
 */

#ifndef _DSGUI_SLIDER_H
#define _DSGUI_SLIDER_H

#include "DSGuiGlobal.h"
#include <QSlider>
#include "QLabel"

namespace DSGUI
{
	/**  ������DSSlider
	  *  ˵��  ������
	 **/
	class DS_GUI_EXPORT DSSlider : public QSlider
	{
		Q_OBJECT

	public:
		// ����
		explicit DSSlider(QWidget* pParent = NULL);
		explicit DSSlider(Qt::Orientation enumOrientation, QWidget* pParent = NULL);
		void SetUponShowType();


	protected:
// 		// �����¼�
// 		virtual void mousePressEvent(QMouseEvent* pEvent);
// 		virtual void mouseMoveEvent(QMouseEvent* pEvent);

	protected:
        // ���ݻ���Orientation���з�ʽת�������ڵ�����ֵ
		int GetPick(const QPoint& ptMouse) const;
        // ͨ����������ֵת��������ֵ
		int PixelPosToRangeValue(int iPos) const;

		QLabel* m_pNumLab;
		QLabel* m_pHintNumUponLab;

		bool m_bShowHintUpon;

	private slots:
		void OnValueChanged(int changedValue);
	};
}

#endif
