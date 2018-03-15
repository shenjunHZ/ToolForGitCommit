#ifndef _DSGUI_CHECKBOXITEM_H
#define _DSGUI_CHECKBOXITEM_H

#include "DSGuiGlobal.h"
#include <QGraphicsPixmapItem>

namespace DSGUI
{
    // ��ѡ��Ԫ��
    class DS_GUI_EXPORT DSCheckBoxItem : public QGraphicsPixmapItem
    {
    public:
        // ����
        DSCheckBoxItem(const QPixmap& pixUnChechBox, const QPixmap& pixChechBox, QGraphicsItem *pParent = NULL);

    public:
        // �Ƿ�ѡ
        bool IsChecked() const;
    protected:
        // ��������ͷ��¼�
        virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    private:
        bool m_bChecked; // �Ƿ�ѡ
        QPixmap m_pixUnCheckPicture; // ��ѡͼƬ
        QPixmap m_pixCheckPicture;   // �ǹ�ѡͼƬ
    };
}

#endif
