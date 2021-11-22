#include "address.h"
#include "message.h"

Address::Address(const QDomElement& element) {
    assert(element.tagName() == "addr");
    address = Message::fixAddress(element.attribute("address"));
    charset = element.attribute("charset");
    type = element.attribute("type");
}
