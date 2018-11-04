#ifndef QREGISTRYSTARTUP_H
#define QREGISTRYSTARTUP_H

#include <QSettings>
#include <QString>

bool createStartup(QString appName,QString appPath,bool allMachine=false,QSettings::Status *errorCode=nullptr);
bool clearStartup(QString appName,bool allMachine=false,QSettings::Status *errorCode=nullptr);
bool queryStartup(QString appName,bool allMachine=false,QSettings::Status *errorCode=nullptr);

#endif // QREGISTRYSTARTUP_H
