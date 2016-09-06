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
    void addTimelapse(std::string, Poco::SharedPtr<Timer::Timelapse>);
    //void removeTimelapse(int);
    //Timer::Timelapse getTimelapse(int);
private:
    std::vector<std::tuple<std::string, Poco::SharedPtr<Timer::Timelapse>, std::string>> _timelapseVector;
};


#endif //OPENWCS_THREADVECTOR_H
