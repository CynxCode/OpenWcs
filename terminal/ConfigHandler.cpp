//
// Created by konstantin on 29.08.18.
//

#include <fstream>

#include "Poco/Util/JSONConfiguration.h"

#include "ConfigHandler.h"
#include "ThreadVector.h"
#include "timer/Timelapse.h"
#include "Config.h"
#include "../cmake-build-debug/terminal/Config.h"

void ConfigHandler::save(const std::string &file) {
  Poco::Util::JSONConfiguration json;
  std::ofstream outfile(file, std::ofstream::binary);

  int i = 0;
  json.setDouble("config.version", 0.2);
  json.setBool("config.motiondetection.enabled", false); //TODO: Get motion detection to work
  for (auto x : ThreadVector::getTimelapseVector()) {
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
void ConfigHandler::load(const std::string &file) {
  Poco::Util::JSONConfiguration json;
  ThreadVector threadVector;

  json.load(file);
  if (std::floor(json.getDouble("config.version")) > OPENWCS_VERSION_MAJOR) {
    std::cout << "Version mismatch!";
  } else {
    bool fail = false;
    int i = 0;
    while (!fail) {
      try {
        std::string tName = json.getString("config.timelapse[" + std::to_string(i) + "].name");
        std::string tPath = json.getString("config.timelapse[" + std::to_string(i) + "].path");
        int tFPS = json.getInt("config.timelapse[" + std::to_string(i) + "].fps");
        int tIntervalSnap = json.getInt("config.timelapse[" + std::to_string(i) + "].intervalsnap");
        int tIntervalCreate = json.getInt("config.timelapse[" + std::to_string(i) + "].intervalcreate");
        Poco::SharedPtr<Timer::Timelapse>
            tempTimelapse(new Timer::Timelapse(0, tIntervalSnap, tIntervalCreate, tPath, tFPS));
        tempTimelapse->setName(tName);
        tempTimelapse->start();
        ThreadVector::addTimelapse(tempTimelapse);
      } catch(Poco::NotFoundException &exception) {
                fail = true;
            }
            i++;
        }

    }
}