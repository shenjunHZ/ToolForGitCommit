/*
 *@file   DSPushButton.h
 *@brief  ���ؼ���MACƽ̨�������
 * 
 *@author cc
 *@date   2014-06-12
 *
 */

#ifndef _DSGUI_PUSHBUTTON_H
#define _DSGUI_PUSHBUTTON_H

#include "DSGuiGlobal.h"
#include <QPushButton>
#include <QStyle>
#include <QStyleOption>

namespace DSGUI
{
    /** @class DSPushButton
      * @brief ��ť
      * 
      */
    class DS_GUI_EXPORT DSPushButton : public QPushButton
    {
        Q_OBJECT
    public:
        //����
        DSPushButton(QWidget* pParent = NULL);
        DSPushButton(const QString& strText, QWidget* pParent = NULL);
        DSPushButton(const QIcon& icnIcon, const QString& strText, QWidget* pParent = NULL);
        
    protected:
        // ��ʼ�����
        void initStyleOption(QStyleOptionButton* pOpt) const;
        // ��ͼ
        virtual void paintEvent(QPaintEvent* pPaintEvent);

    #ifdef Q_WS_MAC
        // ���ص�Ϊ����MACƽ̨��windowsЧ��һ��
        virtual bool hitButton(const QPoint& ptPos) const;
    #endif

    };
}

#endif
