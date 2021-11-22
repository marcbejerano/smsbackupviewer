#ifndef SMSMAP_H
#define SMSMAP_H

#include "message.h"
#include "smscollection.h"

#include <QFile>
#include <QList>
#include <QMap>



class SmsMap : public QMap<QString, QList<Message*>*>
{
public:
    static SmsMap fromCollection(const SmsCollection& collection);
    static SmsMap read(QFile& xmlFile);
    static SmsMap read(const QString& xmlFilename);
    static void save(const SmsMap& map, const QString& address, const QString& dest);
};

#endif // SMSMAP_H
