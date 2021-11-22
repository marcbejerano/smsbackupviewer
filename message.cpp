#include "message.h"

Message::Message(const QDomElement& element)
{
    assert(element.nodeName() == "sms" || element.nodeName() == "mms");
    this->address = fixAddress(element.attribute("address"));
    this->subjectId = element.attribute("sub_id");
    this->contactName = element.attribute("contact_name");
    this->readableDate = element.attribute("readable_date");
    this->date = element.attribute("date").toLong();
    this->dateSent = element.attribute("date_sent").toLong();
    this->locked = element.attribute("locked").toInt() == 1;
    this->read = element.attribute("read").toInt() == 1;
}

QString Message::fixAddress(const QString& address) {
    QString fixed = address;
    while (fixed.contains("+1")) {
        fixed.remove("+1");
    }
    if (fixed.contains("(")) {
        fixed.remove("(");
        fixed.remove(")");
    }
    // if there are any parentheses, remove them
    return fixed;
}
