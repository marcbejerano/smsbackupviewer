#ifndef TEXTMESSAGE_H
#define TEXTMESSAGE_H

#include "message.h"

class TextMessage : public Message
{
private:
    QString body;
    int protocol;
    QString serviceCenterToAddress; // sc_toa;
    QString serviceCenter; // service_center;
    int status;
    QString subject;
    QString toa;
    int type;

public:
    TextMessage() : Message() { }
    TextMessage(const QDomElement& element);
    TextMessage(const TextMessage& copy) : Message(copy) { }
    TextMessage(const QString& address, const QString& subjectId, const QString& contactName, const QString& readableDate,
                long date, long dateSent, bool locked, bool read, const QString& body, int protocol, const QString& serviceCenterToAddress,
                const QString& serviceCenter, int status, const QString& subject, const QString& toa, int type) :
        Message(address, subjectId, contactName, readableDate, date, dateSent, locked, read),
        body(body), protocol(protocol), serviceCenterToAddress(serviceCenterToAddress), serviceCenter(serviceCenter), status(status),
        subject(subject), toa(toa), type(type) { }
    void operator= (const TextMessage& copy) {
        Message::operator=(copy);
        this->body = copy.body;
        this->protocol = copy.protocol;
        this->serviceCenterToAddress = copy.serviceCenterToAddress;
        this->serviceCenter = copy.serviceCenter;
        this->status = copy.status;
        this->subject = copy.subject;
        this->toa = copy.toa;
        this->type = copy.type;
    }

    const QString getBody() const { return this->body; }
    int getProtocol() const { return this->protocol; }
    const QString getServiceCenterToAddress() const { return this->serviceCenterToAddress; }
    const QString getServiceCenter() const { return this->serviceCenter; }
    int getStatus() const { return this->status; }
    const QString getSubject() const { return this->subject; }
    const QString getToa() const { return this->toa; }
    int getType() const { return this->type; }

    enum MessageType {
        MESSAGE_TYPE_ALL = 0,
        MESSAGE_TYPE_INBOX = 1,
        MESSAGE_TYPE_SENT = 2,
        MESSAGE_TYPE_DRAFT = 3,
        MESSAGE_TYPE_OUTBOX = 4,
        MESSAGE_TYPE_FAILED = 5,
        MESSAGE_TYPE_QUEUED = 6
    };

    virtual bool isTextMessage() const { return true; };
    virtual bool isMultimediaMessage() const { return false; };
    virtual bool isOutgoing() const { return type != MESSAGE_TYPE_INBOX; };

};

#endif // TEXTMESSAGE_H
