#include <QtCore/QTextCodec>
#include <QtCore/QDir>
#include <Tools/Dir.h>
#include <Tools/File.h>
#include <QtGui/QIcon>
#include <QtCore/QCoreApplication>

#include "ToolForGitCommit.h"
#include "commonControl.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QString strCurrPath = QCoreApplication::applicationDirPath();
    QDir::setCurrent(strCurrPath);
    DSGUI::DSDir::SetCurrentPath(strCurrPath);

    app.setWindowIcon(QIcon("./Tool.ico"));
    QString strStyle = "";
    QFile fpStyle(commonSpace::GetSkinPath("public", "style.qss"));
    if (fpStyle.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        strStyle = fpStyle.readAll();
        fpStyle.close();
    }
    QString strCSSFilePath = commonSpace::GetSkinPath("") + QString("/DSGUI/CSS/");
    QStringList strList;
    strList.push_back("*.CSS");
    QStringList strFileList = QDir(strCSSFilePath).entryList(strList, QDir::Files);
    qApp->setStyleSheet(strStyle + DSGUI::DSFile::ReadAll(strFileList, strCSSFilePath));

    ToolForGitCommit w;
    w.show();
    return app.exec();
}
