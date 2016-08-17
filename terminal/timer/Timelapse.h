//
//  Timelapse.h
//  terminal/timer
//
//  Created by Konstantin Papesh and Lorenz Kofler.
//  Copyright 2016 OpenWcs.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#ifndef Timelapse_h
#define Timelapse_h

#include "Poco/Util/Timer.h"
#include <iostream>

namespace Timer
{
class Timelapse
{
public:
    Timelapse(int, int, int, std::string, int);
    void start();
    void stop();
private:
    void createTimelapse(Poco::Util::TimerTask &task);
    void snapPicture(Poco::Util::TimerTask &task);
    void setAndCreatePicPath();
    Poco::Util::Timer timer;
    std::string path;
    std::string picPath;
    int FPS;
    int startTime;
    int intervalSnap;
    int intervalCreate;
};
}
#endif /* Timelapse_h */