#ifndef __DSGUI_PLUGINLOADERMANAGER_H__
#define __DSGUI_PLUGINLOADERMANAGER_H__

#include "DSGuiGlobal.h"
#include <QStringList>
#include <QDir>
#include <QPluginLoader>

namespace DSGUI
{
    class DS_GUI_EXPORT DSPluginLoaderManager
    {
    public:
        // ����·��strPath�µĲ���⣬�����ı��ΪstrKey
        template <typename T>
        static T Load(const QString& strKey, const QString& strPath)
        {
            if (strKey.isNull())
            {
                return NULL;
            }

            QStringList strListPlugin = QDir(strPath).entryList(QDir::Files);
            for (int i = 0, iCount = strListPlugin.count(); i < iCount; ++i) 
            {
                QString strFileName = QDir::cleanPath(strPath + QLatin1Char('/') + strListPlugin.at(i));
                QPluginLoader loader(strFileName);
                if (loader.isLoaded()) // �Ѿ�����
                {
                    QObject* pObject = loader.instance();
                    T pFactoryInterface = qobject_cast<T>(pObject);
                    if (NULL != pFactoryInterface)
                    {
                        // ��ȡkeyֵ�����ڼ��ز��
                        QStringList strListKeys = pFactoryInterface->keys();
                        if (strListKeys.contains(strKey))
                        {
                            return pFactoryInterface;
                        }
                    }
                }
                else if (loader.load()) // ���ش˿�
                {
                    QObject* pObject = loader.instance();
                    T pFactoryInterface = qobject_cast<T>(pObject);
                    if (NULL != pFactoryInterface)
                    {
                        // ��ȡkeyֵ������keyֵ���ز��
                        QStringList strListKeys = pFactoryInterface->keys();
                        if (strListKeys.contains(strKey))
                        {
                            return pFactoryInterface;
                        }
                    }

                    loader.unload();
                }
            }

            return NULL;
        }
    };
}

#endif // __DSGUI_PLUGINLOADERMANAGER_H__
