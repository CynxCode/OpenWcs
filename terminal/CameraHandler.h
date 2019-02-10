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

#include <memory>
#include "opencv2/opencv.hpp"
#include "camera.h"

class CameraHandler {
public:
    std::shared_ptr<Camera> getCamera(int index = 0);
    void removeCamera(int index);
private:
    static std::list<std::pair<int, std::weak_ptr<Camera>>> _capVect;
};


#endif //OPENWCS_CAMERAHANDLER_H
