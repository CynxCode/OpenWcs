//
// Created by konstantin on 29.08.18.
//

#ifndef OPENWCS_CONFIGHANDLER_H
#define OPENWCS_CONFIGHANDLER_H


#include <string>

class ConfigHandler {
public:
    void save(std::string path = ".config");
    void load();
    void load(std::string);
private:

};


#endif //OPENWCS_CONFIGHANDLER_H
