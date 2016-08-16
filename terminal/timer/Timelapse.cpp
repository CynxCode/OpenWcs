//
//  Timelapse.cpp
//  terminal/timer
//
//  Created by Konstantin Papesh and Lorenz Kofler.
//  Copyright 2016 OpenWcs.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#include "Timelapse.h"
#include "Poco/Util/TimerTaskAdapter.h"
#include <iostream>

Timer::Timelapse::Timelapse(int start, int interval)
{
    Poco::Util::TimerTask::Ptr timerTaskCreateTimelapse =
        new Poco::Util::TimerTaskAdapter<Timer::Timelapse>(*this, &Timer::Timelapse::createTimelapse);
    Poco::Util::TimerTask::Ptr
        timerTaskSnapPic = new Poco::Util::TimerTaskAdapter<Timer::Timelapse>(*this, &Timer::Timelapse::snapPicture);

    timer.schedule(timerTaskSnapPic, start, interval);
    timer.schedule(timerTaskCreateTimelapse, start, 1000);
}
void Timer::Timelapse::cancelTimer()
{
    timer.cancel(true);
}
void Timer::Timelapse::createTimelapse(Poco::Util::TimerTask &task)
{
    std::cout << "Created Timelapse" << std::endl;
    //TODO: Create Timelapse here
}
void Timer::Timelapse::snapPicture(Poco::Util::TimerTask &task)
{
    std::cout << "Snapped Pic" << std::endl;
    //TODO: Create snapPic function here
}