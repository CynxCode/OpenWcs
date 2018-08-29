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

std::vector<Poco::SharedPtr<Timer::Timelapse>> ThreadVector::_timelapseVector;

void ThreadVector::addTimelapse(Poco::SharedPtr<Timer::Timelapse> timelapse) {
    _timelapseVector.push_back(timelapse);
}

void ThreadVector::removeTimelapse(Poco::SharedPtr<Timer::Timelapse> timelapse) {
    for (int i = 0; i < _timelapseVector.size(); i++) {
        if (_timelapseVector[i] == timelapse) {
            _timelapseVector.erase(_timelapseVector.begin() + i);
            break;
        }
    }
}

std::vector<Poco::SharedPtr<Timer::Timelapse>> ThreadVector::getTimelapseVector() {
    return _timelapseVector;
}
