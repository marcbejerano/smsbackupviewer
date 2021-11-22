#ifndef SMSCOLLECTION_H
#define SMSCOLLECTION_H

#include "message.h"

#include <QFile>
#include <QList>
#include <QString>


class SmsCollection
{
private:
    long backupDate;
    QString backupSet;
    long count;
    QString type;
    QList<Message*> messages;

public:
    static SmsCollection read(QFile& xmlFile);
    static SmsCollection read(const QString& xmlFilename);

    SmsCollection() : count(0L) { }
    virtual ~SmsCollection();
    SmsCollection(const QDomElement& element);
    SmsCollection(const SmsCollection& copy) : backupDate(copy.backupDate), backupSet(copy.backupSet), count(copy.count),
        type(copy.type), messages(copy.messages) { }
    SmsCollection(long backupDate, const QString& backupSet, long count, const QString& type, const QList<Message*>& messages) :
        backupDate(backupDate), backupSet(backupSet), count(count), type(type), messages(messages) { }
    void operator= (const SmsCollection& copy) {
        this->backupDate = copy.backupDate;
        this->backupSet = copy.backupSet;
        this->count = copy.count;
        this->type = copy.type;
        this->messages = copy.messages;
    }

    long getBackupDate() const { return this->backupDate; }
    const QString getBackupSet() const { return this->backupSet; }
    long getCount() const { return this->count; }
    const QString getType() const { return this->type; }
    const QList<Message*> getMessages() const { return this->messages; }
};


#endif // SMSCOLLECTION_H
