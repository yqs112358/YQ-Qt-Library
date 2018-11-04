#include "qregistrystartup.h"
#define REG_PATH "\\Software\\Microsoft\\Windows\\CurrentVersion\\Run"

bool createStartup(QString appName,QString appPath,bool allMachine,QSettings::Status *errorCode)
{
    QSettings s(QString(allMachine?"HKEY_LOCAL_MACHINE":"HKEY_CURRENT_USER")+REG_PATH,QSettings::NativeFormat);
    s.setValue(appName,appPath);
    if(errorCode)
        *errorCode=s.status();
    return s.status() == QSettings::NoError;
}
bool clearStartup(QString appName,bool allMachine,QSettings::Status *errorCode)
{
    QSettings s(QString(allMachine?"HKEY_LOCAL_MACHINE":"HKEY_CURRENT_USER")+REG_PATH,QSettings::NativeFormat);
    if(s.contains(appName))
        s.remove(appName);
    if(errorCode)
        *errorCode=s.status();
    return s.status() == QSettings::NoError;
}
bool queryStartup(QString appName,bool allMachine,QSettings::Status *errorCode)
{
    QSettings s(QString(allMachine?"HKEY_LOCAL_MACHINE":"HKEY_CURRENT_USER")+REG_PATH,QSettings::NativeFormat);
    bool bRet=s.contains(appName);
    if(errorCode)
        *errorCode=s.status();
    return bRet;
}

#undef REG_PATH
