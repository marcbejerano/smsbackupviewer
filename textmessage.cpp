#include "textmessage.h"

TextMessage::TextMessage(const QDomElement& element) : Message(element)
{
    this->body = element.attribute("body");
    this->protocol = element.attribute("protocol").toInt();
    this->serviceCenterToAddress = element.attribute("sc_toa");
    this->serviceCenter = element.attribute("service_center");
    this->status = element.attribute("status").toInt();
    this->subject = element.attribute("subject");
    this->toa = element.attribute("toa");
    this->type = element.attribute("type").toInt();
}
