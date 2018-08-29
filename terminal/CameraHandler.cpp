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

bool CameraHandler::_inUse = false;
cv::Mat CameraHandler::_lastPic = cv::Mat();

CameraHandler::CameraHandler() {
    if (!_inUse) {
        _cap = 0; // open the default camera TODO: Choose Camera...
        if (!_cap.isOpened()) {
            throw Poco::ApplicationException("Camera could not be opened!");
        }
    }
}
cv::Mat CameraHandler::getPic() {
    if(!_inUse) {
        _inUse = true;
        _cap >> _lastPic;
        _inUse = false;
    }
    return _lastPic;
}
