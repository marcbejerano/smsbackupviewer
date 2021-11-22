#ifndef MESSAGE_H
#define MESSAGE_H

#include "address.h"
#include "part.h"

#include <QDomElement>
#include <QList>

class Message
{
private:
    QString address;
    QString subjectId; // sub_id;
    QString contactName; // contact_name;
    QString readableDate; // readable_date;
    long date;
    long dateSent; // date_sent;
    bool locked;
    bool read;
    QList<Part> parts;
    QList<Address> addresses;

public:
    static QString fixAddress(const QString& address);

    Message() { }
    Message(const QDomElement& element);
    Message(const Message& copy) : address(copy.address), subjectId(copy.subjectId), contactName(copy.contactName),
        readableDate(copy.readableDate), date(copy.date), dateSent(copy.dateSent), locked(copy.locked), read(copy.read) { }
    Message(const QString& address, const QString& subjectId, const QString& contactName, const QString& readableDate,
            long date, long dateSent, bool locked, bool read) :
        address(address), subjectId(subjectId), contactName(contactName),
        readableDate(readableDate), date(date), dateSent(dateSent), locked(locked), read(read) { }
    void operator= (const Message& copy) {
        this->address = copy.address;
        this->subjectId = copy.subjectId;
        this->contactName = copy.contactName;
        this->readableDate = copy.readableDate;
        this->date = copy.date;
        this->dateSent = copy.dateSent;
        this->locked = copy.locked;
        this->read = copy.read;
    }

    const QString getAddress() const { return this->address; }
    const QString getSubjectId() const { return this->subjectId; }
    const QString getContactName() const { return this->contactName; }
    const QString getReadableDate() const { return this->readableDate; }
    long getDate() const { return this->date; }
    long getDateSent() const { return this->dateSent; }
    bool isLocked() const { return this->locked; }
    bool isRead() const { return this->read; }

    virtual bool isTextMessage() const = 0;
    virtual bool isMultimediaMessage() const = 0;
    virtual bool isOutgoing() const = 0;
};

#endif // MESSAGE_H
