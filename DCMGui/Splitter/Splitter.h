/*
 *@file   Splitter.h
 *@brief  
 * 
 *@author 28100
 *@date   2016-12-07
 *
 */

#ifndef _DSGUI_SPLITTER_H
#define _DSGUI_SPLITTER_H

#include "DSGuiGlobal.h"
#include <QSplitter>

namespace DSGUI
{
	/**  ������DSSplitter
	  *  ˵��  ��ֿؼ�
	 **/
	class DS_GUI_EXPORT DSSplitter : public QSplitter
	{
		Q_OBJECT

	public:
		explicit DSSplitter(QWidget* parent = 0);
		~DSSplitter();

	private:

	};
}

#endif // SPLITTER_H
