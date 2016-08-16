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

namespace Timer
{
class Timelapse
{
public:
    Timelapse(int, int);
    void cancelTimer();
private:
    void createTimelapse(Poco::Util::TimerTask &task);
    void snapPicture(Poco::Util::TimerTask &task);
    Poco::Util::Timer timer;
};
}
#endif /* Timelapse_h */