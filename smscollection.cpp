#include "multimediamessage.h"
#include "smscollection.h"
#include "textmessage.h"

#include <QTextStream>

bool dateLessThan(const Message* m1, const Message* m2)
{
     return m1->getDate() < m2->getDate();
}

SmsCollection::SmsCollection(const QDomElement& element)
{
    assert(element.nodeName() == "smses");
    this->backupDate = element.attribute("backup_date").toLong();
    this->backupSet = element.attribute("backup_set");
    this->count = element.attribute("count").toLong();
    this->type = element.attribute("type");

    // read messages
    QDomElement child = element.firstChild().toElement();
    while (!child.isNull()) {
        if (child.nodeName() == "sms")
            messages.append(new TextMessage(child));
        else if (child.nodeName() == "mms")
            messages.append(new MultimediaMessage(child));
        else
            throw "Unknown child node detected: " + child.nodeName();

        child = child.nextSibling().toElement();
    }
    std::sort(messages.begin(), messages.end(), dateLessThan);
}

SmsCollection::~SmsCollection() {
    this->messages.clear();
}

SmsCollection SmsCollection::read(QFile& xmlFile) {
    QDomDocument document;
    if (!xmlFile.open(QIODevice::ReadOnly ))
    {
        // Error while loading file
        throw "Error opening file " + xmlFile.fileName();
    }
    // Set data into the QDomDocument before processing
    document.setContent(&xmlFile);
    xmlFile.close();

    return SmsCollection(document.documentElement());
}

SmsCollection SmsCollection::read(const QString& xmlFilename) {
    QFile xmlFile(xmlFilename);
    return read(xmlFile);
}
