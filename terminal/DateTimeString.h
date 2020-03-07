//
// Created by Lorenz Kofler on 05.08.16.
//

#ifndef OPENWCS_DATETIMESTRING_H
#define OPENWCS_DATETIMESTRING_H

#include <iostream>

class DateTimeString {
 public:
  static std::string getISO(bool, bool);
  static std::string getFancy();

 private:
  static std::string _getFormattedTime(const std::string &, bool);
};


#endif //OPENWCS_DATETIMESTRING_H
