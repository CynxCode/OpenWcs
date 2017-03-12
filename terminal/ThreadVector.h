//
// ThreadVector.h
//
// Created by Konstantin Papesh.
// Copyright 2016
//
// Distributed under GNU GPL, Version 3.0.
// See the accompanying file LICENSE or http://www.gnu.org/licenses/.
//
#ifndef OPENWCS_THREADVECTOR_H
#define OPENWCS_THREADVECTOR_H
#include "Poco/SharedPtr.h"

#include "timer/Timelapse.h"
#include <iostream>
#include "DateTimeString.h"

class ThreadVector
{
public:
    void addTimelapse(Poco::SharedPtr<Timer::Timelapse>);
    void removeTimelapse(Poco::SharedPtr<Timer::Timelapse>);
    //Timer::Timelapse getTimelapse(int);
    std::vector<Poco::SharedPtr<Timer::Timelapse>> getTimelapseVector();
private:
    static std::vector<Poco::SharedPtr<Timer::Timelapse>> _timelapseVector;
};


#endif //OPENWCS_THREADVECTOR_H
