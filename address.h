#ifndef ADDRESS_H
#define ADDRESS_H

#include <QDomElement>

class Address
{
private:
    QString address;
    QString charset;
    QString type;

public:
    Address() { }
    Address(const QDomElement& element);
    Address(const Address& copy) : address(copy.address), charset(copy.charset), type(copy.type) { }
    Address(const QString& address, const QString& charset, const QString& type) : address(address), charset(charset), type(type) { }
    void operator= (const Address& copy) {
        this->address = copy.address;
        this->charset = copy.charset;
        this->type = copy.type;
    }

    const QString getAddress() const { return this->address; }
    const QString getCharset() const { return this->charset; }
    const QString getType() const { return this->type; }
};

#endif // ADDRESS_H
