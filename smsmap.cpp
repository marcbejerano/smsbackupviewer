#include "message.h"
#include "multimediamessage.h"
#include "smscollection.h"
#include "smsmap.h"
#include "textmessage.h"

#include <QDateTime>
#include <QList>
#include <QMap>

SmsMap SmsMap::fromCollection(const SmsCollection& collection) {
    SmsMap map;

    QList<Message*>::const_iterator ix = collection.getMessages().cbegin();
    while (ix != collection.getMessages().cend()) {
        Message* msg = *ix;

        if (!map.contains(msg->getAddress())) {
            map[msg->getAddress()] = new QList<Message*>();
        }
        QList<Message*>* list = map[msg->getAddress()];
        list->append(msg);
        ++ix;
    }

    return map;
}

SmsMap SmsMap::read(QFile& xmlFile) {
    return fromCollection(SmsCollection::read(xmlFile));
}

SmsMap SmsMap::read(const QString& xmlFilename) {
    QFile xmlFile(xmlFilename);
    return read(xmlFile);
}


const QString fileExtension(const QString& ctype) {
    QString prefix = ctype;
    int slash = ctype.indexOf("/");

    return "." + prefix.remove(0, slash + 1).toLower();
}

const QString mediaFilename(const QDateTime& dt, const Part* part) {
    const QString dfn = dt.toString("yyyyMMdd.hhmmss");
    QString ctype_prefix = part->getContentType();
    ctype_prefix.remove(ctype_prefix.indexOf("/"), ctype_prefix.length());
    return ctype_prefix + "-" + dfn + fileExtension(part->getContentType());
}

void SmsMap::save(const SmsMap& map, const QString& address, const QString& dest) {
    QList<Message*>* msgs = map[address];
    QString buffer("Chat history for " + address + "\n\n");

    for (auto ix = msgs->cbegin(); ix != msgs->cend(); ix++) {
        const Message* msg = *ix;
        const TextMessage* tmsg = (TextMessage*) msg;
        const MultimediaMessage *mmsg = (MultimediaMessage*) msg;

        const QDateTime dt = QDateTime::fromMSecsSinceEpoch(msg->getDate());
        const QString dts = dt.toString("yyyy-MM-dd hh:mm:ss");
        const QString dfn = dt.toString("yyyyMMdd.hhmmss");

        buffer.append(dts);
        buffer.append(msg->isOutgoing() ? ": SEND " : ": RECV ");

        if (msg->isTextMessage()) {
            buffer.append(tmsg->getBody());
        } else {
            Part* part = mmsg->getParts().last();
            if (part->getContentType().startsWith("text")) {
                buffer.append(part->getText());
            } else {
                QString filename = mediaFilename(dt, part);
                QString filepath = dest + "/" + filename;

                QByteArray b64 = part->getData().toStdString().c_str();

                QFile videoFile(filepath);
                videoFile.open(QIODevice::WriteOnly);
                videoFile.write(QByteArray::fromBase64(b64));
                videoFile.close();

                buffer.append("{").append(part->getContentType()).append(":").append(filepath).append(")}");
            }
        }

        buffer.append("\n");
    }

    QFile chatFile(dest + "/chat-" + address + ".txt");
    chatFile.open(QIODevice::WriteOnly);
    chatFile.write(buffer.toStdString().c_str());
    chatFile.close();
}
