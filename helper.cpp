#include "helper.h"
#include "multimediamessage.h"
#include "textmessage.h"

#include <QDateTime>

const QString cssMsgSend = "style=\"width:100%;margin:8px 0px 8px 60px;background-color:#cc33ff;color:#000000;\"";
const QString cssMsgRecv = "style=\"width:100%;margin:8px 60px 8px 0px;background-color:#3399ff;color:#000000;\"";
const QString cssImgSend = "style=\"width:100%;margin:8px 0px 8px 60px;\"";
const QString cssImgRecv = "style=\"width:100%;margin:8px 60px 8px 0px;\"";
const QString cssImg = "style=\"max-width:50%;height:auto;\"";

const QString Helper::formatMessageForHtml(const Message* msg)
{
    QString line;

    const TextMessage* tmsg = (TextMessage*) msg;
    const MultimediaMessage *mmsg = (MultimediaMessage*) msg;

    QString css = msg->isOutgoing() ? cssMsgSend : cssMsgRecv;
    if (msg->isMultimediaMessage() && !mmsg->getParts().last()->getContentType().startsWith("text")) {
        css = msg->isOutgoing() ? cssImgSend : cssImgRecv;
    }
    line.append("<div ").append(css).append(">");

    if (msg->isTextMessage()) {
        if (tmsg->getBody().startsWith("http")) {
            line.append("<a href=\"").append(tmsg->getBody()).append("\">").append(tmsg->getBody()).append("</a>");
        } else
            line.append(tmsg->getBody());
    } else {
        Part* part = mmsg->getParts().last();
        if (part->getContentType().startsWith("text")) {
            line.append(part->getText());
        } else {
            const QString ctype = part->getContentType();
            if (ctype.startsWith("image")) {
                line.append("<img ")
                    .append(cssImg)
                    .append(" width=\"400\" height-=\"400\" src=\"data:")
                    .append(ctype)
                    .append(";base64,")
                    .append(part->getData())
                    .append("\" />");
            } else
                line.append(part->getContentType());
        }
    }
    line.append("</div>\n");
    return line;
}
