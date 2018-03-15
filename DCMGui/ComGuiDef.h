/*
 *@file   ComGUIDef.h
 *@brief  
 * 
 *@author 
 *@date   2014-05-22
 *
 */

#ifndef __DSGUI_COMGUIDEF_H
#define __DSGUI_COMGUIDEF_H

#include <QVariant>

namespace DSGUI
{
    typedef struct struTreeViewData
    {
        /** @enum  DSItemDataRole 
          * @brief ��ͼ�����ڱ�����ݵĹؼ�ֵ
          * @brief ��ͼ�еĹؼ�ֵ�����ظ���������������
          */ 
        enum DSItemDataRole
        {
            //////////////////////////////////////////////////////////////////////////
            InvalidRole     = Qt::UserRole + 98,
            MinUserRole     = Qt::UserRole + 99,                  // ��Сֵ�����ɶ�������С�Ĺؼ�ֵ

            // �����ؼ�ֵ
            DecorationRole = Qt::UserRole + 100,  
            DisplayRole    = Qt::UserRole + 101,
            CheckStateRole = Qt::UserRole + 102,
            ItemFlagRole   = Qt::UserRole + 103,
            //BackgroundColorRole,

            // ������ͼ
            HeaderViewDefautWidthRole    = Qt::UserRole + 110, // Ĭ�ϳ�ʼ�����
            HeaderViewCheckableRole      = Qt::UserRole + 111, // ��ѡ�Ƿ����
            HeaderViewMaxCheckedRole     = Qt::UserRole + 112, // ���ɹ�ѡ��

            // ��ͼ�пؼ�
            ComboBoxRole           = Qt::UserRole + 120,  // �Ƿ���ʾ������,�����д��ڴ�keyֵ����
            ComboBoxDataRole       = Qt::UserRole + 121,  // ���������ݣ����ݸ�ʽQVector<QVariantMap>��������СΪ�����б���
                                                          // typedef QMap<QString, QVariant> QVariantMap; �����еĹؼ�ֵ���ַ�����ʽ�洢
                                                          // �����û��Զ�������ʹ��Qt::UserRole�ؼ�ֵ
            ComboBoxIndexRole      = Qt::UserRole + 122,  // ��������

            DateTimeEditRole       = Qt::UserRole + 130,   // ���뵱ǰ����QDateTime
            //DateEditRole           = Qt::UserRole + 131,
            DisplayFormatRole      = Qt::UserRole + 135,   // ������ʽ yyyy/M/d H:mm:ss
            

            //////////////////////////////////////////////////////////////////////////
            PixmapAlignmentRole     = Qt::UserRole + 170,     // ����ͼ�����з�ʽ������ ���� ����

            // ���λ���ͼƬ
            Pixmap1Role           = Qt::UserRole + 180, // DSGUI::ItemPixmapValue��ʽ��������ͼƬ
            Pixmap2Role           = Qt::UserRole + 181,
            Pixmap3Role           = Qt::UserRole + 182,

			//ѡ��״̬�µ��滻ͼƬ(��ӦPixmapRole)
			PixmapChecked1Role    = Qt::UserRole + 190, 
			PixmapChecked2Role    = Qt::UserRole + 191,
			PixmapChecked3Role	  = Qt::UserRole + 192,

			//�༭״̬�µ��滻ͼƬ(��ӦPixmapRole)
			PixmapEdit1Role        = Qt::UserRole + 200, 
			PixmapEdit2Role        = Qt::UserRole + 201,
			PixmapEdit3Role		   = Qt::UserRole + 202,
        
            // ͼ��ToolTip
            Pixmap1ToolRole      = Qt::UserRole + 210,
            Pixmap2ToolRole      = Qt::UserRole + 211,
            Pixmap3ToolRole      = Qt::UserRole + 212,

            MouseCursorShapeRole        = Qt::UserRole + 220, // �����������״̬

            //////////////////////////////////////////////////////////////////////////
            
            ReservedRole    = Qt::UserRole + 500,             // �ڲ��������ڴ�֮�϶���ؼ�ֵ
            MaxUserRole     = Qt::UserRole + 800              // �ⲿ�������ڴ�֮�϶���ؼ�ֵ
        }; 

    }TreeViewData;


    struct ItemPixmapValue
    {
    public:
        enum StateFlag 
        {
            State_Default,   // Ĭ��״̬
            State_Hover,     // ����ӹ�״̬
            State_Pressed,   // ��갴��״̬
            State_Disabled,  // ������״̬
        };

    public:
        inline ItemPixmapValue()
        {

        }

    public:
        void AddValue(StateFlag enumStateFlag, QVariant vtValue)
        {
            mapValues[enumStateFlag] = vtValue;
        }

        QVariant GetValue(StateFlag enumStateFlag) const
        {
            if (mapValues.contains(enumStateFlag))
            {
                return mapValues.value(enumStateFlag);
            }

            return QVariant();
        }

        QMap<StateFlag, QVariant> mapValues;
    };

    typedef struct struLayoutData
    {
        enum LayoutType
        {
            // Ĭ�ϲ���
            D_1x1_1		    = 1,
            D_2x2_4		    = 4,
            D_3x3_6		    = 6,
            D_3x3_8		    = 8,
            D_3x3_9		    = 9,	
            D_4x4_13		= 13,
            D_4x4_16		= 16,
            D_5x5_20		= 20,
            D_5x5_25		= 25,
            D_6x6_36		= 36,
			D_6x6_64		= 64,

            // �Զ��岼��

        };

    }LayoutData;

    /** �ṹ�壺StructScaleRect
     *  ˵����  ���α���
     **/
    typedef struct StructScaleRect 
    {
        double dLeftScale;
        double dTopScale;
        double dRightScale;
        double dBottomScale;

        StructScaleRect() 
            : dLeftScale(0.0),
            dTopScale(0.0),
            dRightScale(0.0),
            dBottomScale(0.0)
        {

        }

        StructScaleRect(double dLeftScaleIn, double dTopScaleIn, double dRightScaleIn, double dBottomScaleIn) 
            : dLeftScale(dLeftScaleIn),
            dTopScale(dTopScaleIn),
            dRightScale(dRightScaleIn),
            dBottomScale(dBottomScaleIn)
        {

        }

        StructScaleRect(const StructScaleRect& struScale) 
            : dLeftScale(struScale.dLeftScale),
            dTopScale(struScale.dTopScale),
            dRightScale(struScale.dRightScale),
            dBottomScale(struScale.dBottomScale)
        {

        }

        // �ȺŲ�����ֻƥ�䴰����ͬ����
        inline bool operator == (const StructScaleRect& struOther) const
        {
            return struOther.dLeftScale == dLeftScale && struOther.dTopScale == dTopScale
                && struOther.dRightScale == dRightScale && struOther.dBottomScale == dBottomScale;
        }

    }ScaleRectData;

	typedef struct struPTZData
	{
		enum PTZBtnType
		{
			Direction_Up,					// �˷���
			Direction_Down,
			Direction_Left,
			Direction_Right,
			Direction_LeftUp,
			Direction_LeftDown,
			Direction_RightUp,
			Direction_RightDown,

			Direction_3DSiteOn,				// ��ά��λ
			Direction_3DSiteOff,

			Zoom_Inc,
			Zoom_Dec,
			Foucus_Inc,
			Foucus_Dec,
			Aperture_Inc,
			Aperture_Dec,

			Menu_Up,			  // ��̨�˵�
			Menu_Down,
			Menu_Left,
			Menu_Right,
			Menu_Enter,
			Menu_Open,
			Menu_Close,
			
			PresetPosition,       // Ԥ�õ㶨λ
			AddPreset,			  // ���Ԥ�õ�
			DeletePreset,		  // ɾ��Ԥ�õ�

			AutoRotate_On,		  // ˮƽ��ת
			AutoRotate_Off,

			Scan_LeftBoundarySet,    // ����ɨ��
			Scan_RightBoundarySet,
			Scan_On,
			Scan_Off,

			Pattern_Set_Start,    // Ѳ��
			Pattern_Set_Stop,
			Pattern_On,
			Pattern_Off,

			Asstst_On,			  // ��������
			Asstst_Off,			
		};
	}PTZBtnData;

    typedef QMap<int, QVariant> DSVariantMap;
}

Q_DECLARE_METATYPE(DSGUI::ItemPixmapValue)
Q_DECLARE_METATYPE(DSGUI::StructScaleRect)

Q_DECLARE_METATYPE(QList<DSGUI::DSVariantMap>)
#endif 
