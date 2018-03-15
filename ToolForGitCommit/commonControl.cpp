#include "commonControl.h"
#include "Tools/Dir.h"
#include "DSGuiGlobalData.h"

#include <QtCore/QFile>

namespace commonSpace
{

	bool loadStyleSheet(const QString &sheetName, QString &styleSheet)
	{
		QFile file(sheetName);
		bool state = false;
		state = file.open(QFile::ReadOnly);
		if (state)
		{
			styleSheet = QLatin1String(file.readAll());
		}
		return state;
	}

	QString GetSkinPath(const QString& strFolder, const QString& strSkinName /*= QString()*/)
	{
		QString strPath = DSGUI::DSDir::GetCurrentPath() + "/Skin/" + DSGUI::GetSkinVersion() + "/" + strFolder + "/" + strSkinName;
		return strPath;
	}

}