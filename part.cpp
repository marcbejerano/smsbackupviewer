#include "part.h"

Part::Part(const QDomElement& element)
{
    assert(element.nodeName() == "part");
    contentDisposition = element.attribute("cd");
    charSet = element.attribute("chset");
    contentId = element.attribute("cid");
    contentLocation = element.attribute("cl");
    contentType = element.attribute("ct");
    contentTypeStart = element.attribute("ctt_s");
    contentTypeType = element.attribute("ctt_t");
    data = element.attribute("data");
    filename = element.attribute("fn");
    name = element.attribute("name");
    sequence = element.attribute("seq");
    text = element.attribute("text");
}
