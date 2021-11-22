#include "multimediamessage.h"

MultimediaMessage::MultimediaMessage(const QDomElement& element) : Message(element)
{
    this->creator = element.attribute("creator");
    this->contentClass = element.attribute("ct_cls");
    this->contentLocation = element.attribute("ct_l");
    this->contentType = element.attribute("ct_t");
    this->deliveryReport = element.attribute("d_rpt").toInt();
    this->deliveryTime = element.attribute("d_tm").toLong();
    this->expiryTime = element.attribute("exp").toLong();
    this->messageClass = element.attribute("m_cls");
    this->messageId = element.attribute("m_id");
    this->messageSize = element.attribute("m_size").toInt();
    this->messageType = element.attribute("m_type").toInt();
    this->messageBox = element.attribute("msg_box").toInt();
    this->phoneId = element.attribute("phone_id");
    this->priority = element.attribute("pri").toInt();
    this->readStatus = element.attribute("read_status").toInt();
    this->responseStatus = element.attribute("resp_st").toInt();
    this->responseText = element.attribute("resp_txt");
    this->retrieveStatus = element.attribute("retr_st").toInt();
    this->retrieveText = element.attribute("retr_txt");
    this->retrieveTextCharset = element.attribute("retr_txt_cs").toInt();
    this->reportAllowed = element.attribute("rpt_a").toInt() == 1;
    this->readReport = element.attribute("rr").toInt();
    this->seen = element.attribute("seen").toInt() == 1;
    this->status = element.attribute("st").toInt();
    this->styleCode = element.attribute("style_code");
    this->subject = element.attribute("sub");
    this->subjectCharset = element.attribute("sub_cs").toInt();
    this->textOnly = element.attribute("text_only").toInt() == 1;
    this->transactionId = element.attribute("tr_id");
    this->version = element.attribute("version").toInt();

    QDomElement child = element.firstChild().toElement();
    while (!child.isNull()) {
        if (child.nodeName() == "parts") {
            QDomElement part = child.firstChild().toElement();
            while (!part.isNull()) {
                parts.append(new Part(part));
                part = part.nextSibling().toElement();
            }
        }
        else if (child.nodeName() == "addrs") {
            QDomElement addr = child.firstChild().toElement();
            while (!addr.isNull()) {
                addresses.append(new Address(addr));
                addr = addr.nextSibling().toElement();
            }
        }
        child = child.nextSibling().toElement();
    }
}

MultimediaMessage::~MultimediaMessage() {
    this->parts.clear();
    this->addresses.clear();
}
