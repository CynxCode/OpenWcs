//
// Created by Lorenz Kofler on 05.08.16.
//

#ifndef OPENWCS_DATETIMESTRING_H
#define OPENWCS_DATETIMESTRING_H

#include <iostream>
#include <Poco/LocalDateTime.h>


class DateTimeString
{

public:
    std::string getISO();
    std::string getISO(Poco::LocalDateTime);
    std::string getISO(Poco::LocalDateTime, bool);
    std::string getISO(Poco::DateTime);


private:
    std::string _getISO(Poco::DateTime, bool, bool);

};


#endif //OPENWCS_DATETIMESTRING_H
