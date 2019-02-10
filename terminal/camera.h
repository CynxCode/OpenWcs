//
// Created by khp on 09.02.19.
//

#ifndef OPENWCS_CAMERA_H
#define OPENWCS_CAMERA_H


#include <opencv2/core/mat.hpp>
#include <opencv2/videoio.hpp>

class Camera {
public:
    explicit Camera(int index);
    ~Camera();
    cv::Mat getPic();

private:
    int _index;
    cv::VideoCapture _cap;
    cv::Mat _lastPic;
};


#endif //OPENWCS_CAMERA_H
