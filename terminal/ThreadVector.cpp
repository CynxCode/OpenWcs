//
// ThreadVector.cpp
//
// Created by Konstantin Papesh.
// Copyright 2016
//
// Distributed under GNU GPL, Version 3.0.
// See the accompanying file LICENSE or http://www.gnu.org/licenses/.
//
#include "ThreadVector.h"

#include <Poco/DateTimeFormatter.h>

void ThreadVector::addTimelapse(std::string name, Poco::SharedPtr<Timer::Timelapse> timelapse)
{
    DateTimeString dateTimeString;
    std::string tempTime = dateTimeString.getISO(false, false);
    _timelapseVector.push_back(std::make_tuple(name, timelapse, tempTime));
}
