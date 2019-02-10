//
// CameraHandler.cpp
//
// Created by Konstantin Papesh.
// Copyright 2018
//
// Distributed under GNU GPL, Version 3.0.
// See the accompanying file LICENSE or http://www.gnu.org/licenses/.
//

#include "CameraHandler.h"
#include "opencv2/opencv.hpp"
#include "Poco/Exception.h"

std::list<std::pair<int, std::weak_ptr<Camera>>> CameraHandler::_capVect{};

std::shared_ptr<Camera> CameraHandler::getCamera(int index) {
    for (auto &item : _capVect) {
        if(item.first == index) { // in use
            if (item.second.expired()) {
                std::shared_ptr<Camera> tCap = std::make_shared<Camera>(index);
                item.second = tCap;
                return tCap;
            } else {
                return item.second.lock();
            }
        }
    }

    std::shared_ptr<Camera> tCap = std::make_shared<Camera>(index);
    _capVect.emplace_back(index, tCap);
    return tCap;
}
