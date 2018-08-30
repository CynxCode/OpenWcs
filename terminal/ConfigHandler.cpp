//
// Created by konstantin on 29.08.18.
//

#include <fstream>
#include "Poco/Util/JSONConfiguration.h"
#include "ConfigHandler.h"
#include "ThreadVector.h"
#include "timer/Timelapse.h"
#include "Config.h"

void ConfigHandler::save(std::string file) {
    Poco::Util::JSONConfiguration json;
    ThreadVector threadVector;
    std::ofstream outfile(file,std::ofstream::binary);

    int i = 0;
    json.setDouble("config.version", 0.2);
    json.setBool("config.motiondetection.enabled", false); //TODO: Get motion detection to work
    for (auto x : threadVector.getTimelapseVector()) {
        json.setString("config.timelapse[" + std::to_string(i) + "].name", x->getName());
        json.setString("config.timelapse[" + std::to_string(i) + "].path", x->getPath());
        json.setInt("config.timelapse[" + std::to_string(i) + "].fps", x->getFPS());
        json.setInt("config.timelapse[" + std::to_string(i) + "].intervalsnap", x->getIntervalSnap());
        json.setInt("config.timelapse[" + std::to_string(i) + "].intervalcreate", x->getIntervalCreate());
        i++;
    }
    json.save(outfile);
    outfile.close();
}
void ConfigHandler::load(std::string file) {
    Poco::Util::JSONConfiguration json;
    ThreadVector threadVector;

    json.load(file);
    if(std::floor(json.getDouble("config.version")) > openwcs_VERSION_MAJOR) {
        std::cout << "Version mismatch!";
    } else {
        std::cout << json.getDouble("config.version") << " passt ziemlich gut mit " << openwcs_VERSION_MAJOR << "." << openwcs_VERSION_MINOR;
    }
}