/*
 *@file   CustomSplitter.h
 *@brief  
 * 
 *@author 28100
 *@date   2016-12-07
 *
 */

#ifndef _DSGUI_CUSTOMSPLITTER_H
#define _DSGUI_CUSTOMSPLITTER_H

#include "DSGuiGlobal.h"
#include "Splitter/Splitter.h"

namespace DSGUI
{

	class DSCustomSplitterPrivate;
	/**  ������DSCustomSplitter
	  *  ˵��  ���⴦��������Ĭ�ϲ�����OpaqueResize, ����ʱ�ָ��߻������ߣ�
	 **/
	class DS_GUI_EXPORT DSCustomSplitter : public DSSplitter
	{
		Q_OBJECT
	
	public:
		DSCustomSplitter(QWidget *parent = 0);
		~DSCustomSplitter();

	public:
		void setRubberBand(int position);

	protected:
		// �����¼�
		virtual QSplitterHandle *createHandle();

		void childEvent(QChildEvent *c);

	private:
		QScopedPointer<DSCustomSplitterPrivate> d_ptr;

	private:
		Q_DISABLE_COPY(DSCustomSplitter)
		Q_DECLARE_PRIVATE(DSCustomSplitter)
		
	};
}

#endif // _DSGUI_CUSTOMSPLITTER_H
