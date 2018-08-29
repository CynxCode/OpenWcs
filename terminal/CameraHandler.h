//
// CameraHandler.h
//
// Created by Konstantin Papesh.
// Copyright 2018
//
// Distributed under GNU GPL, Version 3.0.
// See the accompanying file LICENSE or http://www.gnu.org/licenses/.
//

#ifndef OPENWCS_CAMERAHANDLER_H
#define OPENWCS_CAMERAHANDLER_H

#include "opencv2/opencv.hpp"

class CameraHandler {
public:
    CameraHandler();
    cv::Mat getPic();
private:
    cv::VideoCapture _cap;
    static bool _inUse;
    static cv::Mat _lastPic;
};


#endif //OPENWCS_CAMERAHANDLER_H
