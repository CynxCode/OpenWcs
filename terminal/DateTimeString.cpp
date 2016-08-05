//
// Created by Lorenz Kofler on 05.08.16.
//

#include <Poco/DateTimeFormatter.h>
#include "DateTimeString.h"


std::string DateTimeString::getISO()
{
    Poco::DateTime now;
    return _getISO(now, false, false);
}

std::string DateTimeString::getISO(Poco::LocalDateTime now)
{
    Poco::DateTime dateTime = now.utc();
    return _getISO(dateTime, false, false);
}

std::string DateTimeString::getISO(Poco::LocalDateTime now, bool addZulu)
{
    Poco::DateTime dateTime = now.utc();
    return _getISO(dateTime, addZulu, false);
}

std::string DateTimeString::getISO(Poco::DateTime now)
{
    return _getISO(now, true, true);
}

std::string DateTimeString::_getISO(Poco::DateTime dateTime, bool addZulu, bool inUTC)
{
    //Maybe fix this one day.
    Poco::DateTimeFormatter dateTimeFormatter;
    std::string zulu;
    if (addZulu)
        zulu = "%z";
    if (!inUTC) {
        Poco::LocalDateTime now(dateTime);
        return dateTimeFormatter.format(now, "%Y%m%dT%H%M%S" + zulu);
    }
    else {
        Poco::DateTime now(dateTime);
        return dateTimeFormatter.format(now, "%Y%m%dT%H%M%S" + zulu);
    }
}
//%W%f%.%n.%Y %H:%M:%S TODO: alternative timeformat