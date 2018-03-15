#pragma once

#include <QtWidgets/QWidget>
#include <Dialog/Dialog.h>

namespace Ui
{
    class ToolForGitCommit;
}

class ToolForGitCommit : public DSGUI::DSDialog
{
    Q_OBJECT

public:
    ToolForGitCommit(QWidget *parent = nullptr);

private:
    void initUI();
    void connectSgn();

    bool readMessageInfo(QString& strFilePath);
    bool writeMesageInfo(QString& strFilePath);

private slots:
    void onAddClick();
    void onModifyClick();
    void onDelClick();

private:
    Ui::ToolForGitCommit* m_pUI;
    QString               m_strMesageInfo;
};
