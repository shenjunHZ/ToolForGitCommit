/*
 *@file   PixmapBrowser.h
 *@brief  ͼƬ�����
 * 
 *@author cc
 *@date   2014-06-21
 *
 */

#ifndef _DSGUI_PIXMAPBROWSER_H
#define _DSGUI_PIXMAPBROWSER_H

#include "DSGuiGlobal.h"
#include <QtGui/QGraphicsView>

namespace DSGUI
{
    class DSGraphicsLayout;
	class DS_GUI_EXPORT DSPictureBrowser : public QGraphicsView
	{
		Q_OBJECT

	public:
		// ����
        DSPictureBrowser(QWidget* pParent = NULL);

    public:
        // ���ò���
        void SetGraphicsLayout(DSGraphicsLayout* pLayout);
        // ��ȡ����
        DSGraphicsLayout* GetGraphicsLayout() const;

    public:
        //void SetCurrentIndex(int iIndex);
        //int GetCurrentIndex() const;

    Q_SIGNALS:
        // ѡ�иı䣬���û��ѡ�У�����NULL
        void SignalCurrentChanged(QGraphicsItem* pItem);
        // ˫���ź�
        void SignalClickedItem(QGraphicsItem* pItem);
        // ˫���ź�
        void SignalDoubleClickedItem(QGraphicsItem* pItem);
		// �����ź�
		void SignalPressItem(QGraphicsItem* pItem);

    protected:
        // ��С�ı��¼�
        virtual void resizeEvent(QResizeEvent* pResizeEvent);
        // ��굥���¼�
        virtual void mouseReleaseEvent(QMouseEvent* pMouseEvent);
        // ���˫���¼�
        virtual void mouseDoubleClickEvent(QMouseEvent* pMouseEvent);
		// ��굥���¼�
		virtual void mousePressEvent(QMouseEvent* pMouseEvent);
    private slots:
        // ѡ�иı�
        void OnSelectionChanged();

    private:
        DSGraphicsLayout* m_pGraphicsItemLayout; // ��������
	};
}

#endif //_DSGUI_LISTVIEW_H
