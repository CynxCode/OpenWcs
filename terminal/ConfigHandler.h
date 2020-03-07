//
// Created by konstantin on 29.08.18.
//

#ifndef OPENWCS_CONFIGHANDLER_H
#define OPENWCS_CONFIGHANDLER_H


#include <string>

class ConfigHandler {
 public:
  static void save(const std::string &file = ".config");
  static void load(const std::string &file = ".config");
 private:

};


#endif //OPENWCS_CONFIGHANDLER_H
