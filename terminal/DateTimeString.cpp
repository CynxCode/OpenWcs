//
// Created by Lorenz Kofler on 05.08.16.
//

#include <Poco/DateTimeFormatter.h>
#include "DateTimeString.h"

std::string DateTimeString::_getFormattedTime(const std::string &format, bool displayInUTC) {
  Poco::DateTimeFormatter dateTimeFormatter;
  if (!displayInUTC) {
    Poco::LocalDateTime now;
    return dateTimeFormatter.format(now, format);
  } else {
    Poco::DateTime dateTime;
    return dateTimeFormatter.format(dateTime, format);
  }
}
std::string DateTimeString::getISO(bool addZulu, bool displayInUTC) {
  std::string zulu;
  if (addZulu)
    zulu = "%z";
  return _getFormattedTime("%Y%m%dT%H%M%S" + zulu, displayInUTC);
}

std::string DateTimeString::getFancy()
{
    return _getFormattedTime("%W%f%.%n.%Y %H:%M:%S", false);
}
