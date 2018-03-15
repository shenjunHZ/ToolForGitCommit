#ifndef _DSGUI_TEXTITEM_H
#define _DSGUI_TEXTITEM_H

#include "DSGuiGlobal.h"
#include <QGraphicsTextItem>
#include <QGraphicsSimpleTextItem>

namespace DSGUI
{
    // ����Ԫ��
	class DS_GUI_EXPORT DSSimpleTextItem : public QGraphicsSimpleTextItem
	{
	public:
		// ����
        DSSimpleTextItem(const QString& strText, QGraphicsItem* pParent = NULL);

    public:
        // ���þ��Σ�������δ�С
        void SetRect(const QRectF& rtItem);
    public:
        // �������ֻ���
        void SetTextPen(const QPen& penText);
        // �����������з�ʽ
        void SetAlignment(Qt::Alignment enumAlignment);
        // ���ñ���ɫ
        void SetBackgroundColor(const QColor& colorBg);

    protected:
        // ��ͼ
        virtual void paint(QPainter *pPainter, const QStyleOptionGraphicsItem *option, QWidget *pWidget);

        // ��������
        virtual QRectF boundingRect() const;

    private:
        QRectF m_rtItem; // ���־���
        QColor m_colorBg; // ����ɫ
        Qt::Alignment m_enumAlignment; // �������з�ʽ
	};

    /*@cn:    DSComplexTextItem
     *@brief: ��������Ԫ��
     *        ��Ҫʵ����link���״̬�ı�
     *        ����ʹ��setHtml����ʽ���£�
     *        QString("<a href=\"file:///%1\" style='color: rgb(255, 255, 255);'>%1</a>").arg("Program Files");
     *        QString("<a href=\"%1\">%1</a>").arg("Program Files");
     */
    class DS_GUI_EXPORT DSComplexTextItem : public QGraphicsTextItem
    {
        Q_OBJECT
    public:
        // ����
        DSComplexTextItem(QGraphicsItem* pParent = NULL);

    private slots:
        // �������״̬
        void OnLinkHovered(const QString& strUrl);
    };
}

#endif
