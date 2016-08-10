//
// Created by Lorenz Kofler on 05.08.16.
//

#ifndef OPENWCS_DATETIMESTRING_H
#define OPENWCS_DATETIMESTRING_H

#include <iostream>

class DateTimeString
{
public:
    std::string getISO(bool, bool);
    std::string getFancy();

private:
    std::string _getFormattedTime(std::string, bool);
};


#endif //OPENWCS_DATETIMESTRING_H
