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

std::vector<std::pair<int, std::shared_ptr<Camera>>> CameraHandler::_capVect{};

std::weak_ptr<Camera> CameraHandler::getCamera(int index) {
    for (const auto &item : _capVect) {
        if(item.first == index) // in use
            return item.second;
    }

    std::shared_ptr<Camera> tCap = std::make_shared<Camera>(index);
    _capVect.emplace_back(index, tCap);
    return tCap;
}
