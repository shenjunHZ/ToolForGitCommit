#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtWidgets/QDesktopWidget>
#include <QString>
#include <QtCore/QDebug>

#include "ToolForGitCommit.h"
#include "commonControl.h"
#include "ui_ToolForGitCommit.h"

ToolForGitCommit::ToolForGitCommit(QWidget *parent)
    : DSGUI::DSDialog(parent)
    , m_strMesageInfo("")
{
    m_pUI = new Ui::ToolForGitCommit();
    m_pUI->setupUi(this->GetCentralWidget());
    setAttribute(Qt::WA_StyledBackground);

    this->setFixedHeight(524);
    this->setFixedWidth(180);
    this->setObjectName("ToolForGitCommit");

    initUI();
    connectSgn();
    SET_MODULE_STYLE_BY_PATH("ToolForGitCommit");
}

void ToolForGitCommit::initUI()
{
    // move to middle
    QDesktopWidget* pDeskWidget = QApplication::desktop();
    int iScreen = pDeskWidget->primaryScreen(); // use primary screen for show
    QWidget* pPrimaryScreen = pDeskWidget->screen(iScreen);

    int iWidth = pPrimaryScreen->width();
    int iHeight = pPrimaryScreen->height();
    this->move((iWidth - width()) / 2, (iHeight - height()) / 2);
}

void ToolForGitCommit::connectSgn()
{
    connect(m_pUI->m_btnAdd, SIGNAL(clicked()), this, SLOT(onAddClick()));
    connect(m_pUI->m_btnModify, SIGNAL(clicked()), this, SLOT(onModifyClick()));
    connect(m_pUI->m_btnDel, SIGNAL(clicked()), this, SLOT(onDelClick()));
}

void ToolForGitCommit::onAddClick()
{
    QString strFilePath = "./TemeleteMessage/FeatureMessage.txt";
    m_strMesageInfo = "";
    bool bRead = readMessageInfo(strFilePath);

    if (bRead)
    {
        QString strWritePath = "MessageInfo.txt";
        writeMesageInfo(strWritePath);
    }

    close();
}

void ToolForGitCommit::onModifyClick()
{
    QString strFilePath = "./TemeleteMessage/ProntoMessage.txt";
    m_strMesageInfo = "";
    bool bRead = readMessageInfo(strFilePath);

    if (bRead)
    {
        QString strWritePath = "MessageInfo.txt";
        writeMesageInfo(strWritePath);
    }

    close();
}

void ToolForGitCommit::onDelClick()
{
    QString strFilePath = "./TemeleteMessage/CommonMessage.txt";
    m_strMesageInfo = "";
    bool bRead = readMessageInfo(strFilePath);

    if (bRead)
    {
        QString strWritePath = "MessageInfo.txt";
        writeMesageInfo(strWritePath);
    }

    close();
}

bool ToolForGitCommit::readMessageInfo(QString& strFilePath)
{
    QFile file(strFilePath);
    bool bRead = false;
    bRead = file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (bRead)
    {
        m_strMesageInfo = QLatin1String(file.readAll());
    }
    file.close();

    return bRead;
}

bool ToolForGitCommit::writeMesageInfo(QString& strFilePath)
{
    QFile file(strFilePath);
    bool bWrite = false;
    bWrite = file.open(QFile::WriteOnly);
    if (bWrite)
    {
        QTextStream out(&file);
        out << m_strMesageInfo;
    }
    file.close();

    return bWrite;
}
