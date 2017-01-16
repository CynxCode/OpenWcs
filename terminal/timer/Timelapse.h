//
//  Timelapse.h
//  terminal/_timer
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
#include "Poco/File.h"

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
    Poco::Util::Timer _timer;
    std::string _path;
    std::string _picPath;
    int _FPS;
    int _startTime;
    int _intervalSnap;
    int _intervalCreate;
    int _picNo = 0;
    std::string _startDate;
    std::string _endDate;
};
}
#endif /* Timelapse_h */