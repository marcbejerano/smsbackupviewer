#ifndef MULTIMEDIAMESSAGE_H
#define MULTIMEDIAMESSAGE_H

#include "message.h"

class MultimediaMessage : public Message
{
private:
    QString creator;
    QString contentClass;       // ct_cls;
    QString contentLocation;    // ct_l;
    QString contentType;        // ct_t;
    int deliveryReport;         // d_rpt;
    long deliveryTime;          // d_tm;
    long expiryTime;            // exp;
    QString messageClass;       // m_cls;
    QString messageId;          // m_id;
    int messageSize;            // m_size;
    int messageType;            // m_type;
    int messageBox;             // msg_box;
    QString phoneId;            // phone_id;
    int priority;               //v pri;
    int readStatus;             // read_status;
    int responseStatus;         // resp_st;
    QString responseText;       // resp_txt
    int retrieveStatus;         // retr_st;
    QString retrieveText;       // retr_txt;
    int retrieveTextCharset;    // retr_txt_cs;
    bool reportAllowed;         // rpt_a;
    int readReport;             // rr;
    bool seen;
    int status;                 // st;
    QString styleCode;          // style_code;
    QString subject;            // sub;
    int  subjectCharset;        // sub_cs;
    bool textOnly;              //  text_only;
    QString transactionId;      // tr_id;
    int version;                // v;
    QList<Part*> parts;
    QList<Address*> addresses;

public:
    MultimediaMessage() : Message() { }
    virtual ~MultimediaMessage();
    MultimediaMessage(const QDomElement& element);
    MultimediaMessage(const MultimediaMessage& copy) : Message(copy), creator(copy.creator), contentClass(copy.contentClass),
        contentLocation(copy.contentLocation), contentType(copy.contentType), deliveryReport(copy.deliveryReport),
        deliveryTime(copy.deliveryTime), expiryTime(copy.expiryTime), messageClass(copy.messageClass), messageId(copy.messageId),
        messageSize(copy.messageSize), messageType(copy.messageType), messageBox(copy.messageBox), phoneId(copy.phoneId),
        priority(copy.priority), readStatus(copy.readStatus), responseStatus(copy.responseStatus), responseText(copy.responseText),
        retrieveStatus(copy.retrieveStatus), retrieveText(copy.retrieveText), retrieveTextCharset(copy.retrieveTextCharset),
        reportAllowed(copy.reportAllowed), readReport(copy.readReport), seen(copy.seen), status(copy.status), styleCode(copy.styleCode),
        subject(copy.subject), subjectCharset(copy.subjectCharset), textOnly(copy.textOnly), transactionId(copy.transactionId), version(copy.version) { }
    MultimediaMessage(const QString& address, const QString& subjectId, const QString& contactName, const QString& readableDate,
                      long date, long dateSent, bool locked, bool read, const QString& creator, const QString& contentClass, const QString& contentLocation,
                      const QString& contentType, int deliveryReport, long deliveryTime, long expiryTime, const QString& messageClass, const QString& messageId,
                      int messageSize, int messageType, int messageBox, const QString& phoneId, int priority, int readStatus, int responseStatus,
                      const QString& responseText, int retrieveStatus, const QString& retrieveText, int retrieveTextCharset, bool reportAllowed,
                      int readReport, bool seen, int status, const QString& styleCode, const QString& subject, int  subjectCharset, bool textOnly,
                      const QString& transactionId, int version) :
        Message(address, subjectId, contactName, readableDate, date, dateSent, locked, read),
        creator(creator), contentClass(contentClass), contentLocation(contentLocation), contentType(contentType), deliveryReport(deliveryReport),
        deliveryTime(deliveryTime), expiryTime(expiryTime), messageClass(messageClass), messageId(messageId), messageSize(messageSize),
        messageType(messageType), messageBox(messageBox), phoneId(phoneId), priority(priority), readStatus(readStatus), responseStatus(responseStatus),
        responseText(responseText), retrieveStatus(retrieveStatus), retrieveText(retrieveText), retrieveTextCharset(retrieveTextCharset),
        reportAllowed(reportAllowed), readReport(readReport), seen(seen), status(status), styleCode(styleCode), subject(subject),
        subjectCharset(subjectCharset), textOnly(textOnly), transactionId(transactionId), version(version) { }
    void operator= (const MultimediaMessage& copy) {
        Message::operator =(copy);
        creator = copy.creator;
        contentClass = copy.contentClass;
        contentLocation = copy.contentLocation;
        contentType = copy.contentType;
        deliveryReport = copy.deliveryReport;
        deliveryTime = copy.deliveryTime;
        expiryTime = copy.expiryTime;
        messageClass = copy.messageClass;
        messageId = copy.messageId;
        messageSize = copy.messageSize;
        messageType = copy.messageType;
        messageBox = copy.messageBox;
        phoneId = copy.phoneId;
        priority = copy.priority;
        readStatus = copy.readStatus;
        responseStatus = copy.responseStatus;
        responseText = copy.responseText;
        retrieveStatus = copy.retrieveStatus;
        retrieveText = copy.retrieveText;
        retrieveTextCharset = copy.retrieveTextCharset;
        reportAllowed = copy.reportAllowed;
        readReport = copy.readReport;
        seen = copy.seen;
        status = copy.status;
        styleCode = copy.styleCode;
        subject = copy.subject;
        subjectCharset = copy.subjectCharset;
        textOnly = copy.textOnly;
        transactionId = copy.transactionId;
        version = copy.version;
    }

    const QString getCreator() const { return this->creator; }
    const QString getContentClass() const { return this->contentClass; }
    const QString getContentLocation() const { return this->contentLocation; }
    const QString getContentType() const { return this->contentType; }
    int getDeliveryReport() const { return this->deliveryReport; }
    long getDeliveryTime() const { return this->deliveryTime; }
    long getExpiryTime() const { return this->expiryTime; }
    const QString getMessageClass() const { return this->messageClass; }
    const QString getMessageId() const { return this->messageId; }
    int getMessageSize() const { return this->messageSize; }
    int getMessageType() const { return this->messageType; }
    int getMessageBox() const { return this->messageBox; }
    const QString getPhoneId() const { return this->phoneId; }
    int getPriority() const { return this->priority; }
    int getReadStatus() const { return this->readStatus; }
    int getResponseStatus() const { return this->responseStatus; }
    const QString getResponseText() const { return this->responseText; }
    int getRetrieveStatus() const { return this->retrieveStatus; }
    const QString getRetrieveText() const { return this->retrieveText; }
    int getRetrieveTextCharset() const { return this->retrieveTextCharset; }
    bool isReportAllowed() const { return this->reportAllowed; }
    int getReadReport() const { return this->readReport; }
    bool isSeen() const { return this->seen; }
    int getStatus() const { return this->status; }
    const QString getStyleCode() const { return this->styleCode; }
    const QString getSubject() const { return this->subject; }
    int  getSubjectcHarset() const { return this->subjectCharset; }
    bool isTextOnly() const { return this->textOnly; }
    const QString getTransactionId() const { return this->transactionId; }
    int getVersion() const { return this->version; }
    const QList<Part*> getParts() const { return this->parts; }
    const QList<Address*> getAddresses() const { return this->addresses; }

    enum MessageBoxType {
        MESSAGE_BOX_ALL = 0,
        MESSAGE_BOX_INBOX = 1,
        MESSAGE_BOX_SENT = 2,
        MESSAGE_BOX_DRAFTS = 3,
        MESSAGE_BOX_OUTBOX = 4,
        MESSAGE_BOX_FAILED = 5
    };

    virtual bool isTextMessage() const { return false; };
    virtual bool isMultimediaMessage() const { return true; };
    virtual bool isOutgoing() const { return messageBox != MESSAGE_BOX_INBOX; };
};

#endif // MULTIMEDIAMESSAGE_H
