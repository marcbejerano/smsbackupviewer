#ifndef HELPER_H
#define HELPER_H

#include "message.h"

#include <QDate>



class Helper
{
public:
    static const QString formatMessageForHtml(const Message* msg);
};

#endif // HELPER_H
