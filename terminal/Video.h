//
// Created by Lorenz Kofler on 09.08.16.
//

#ifndef OPENWCS_VIDEO_H
#define OPENWCS_VIDEO_H

#include "iostream"
#include "opencv2/opencv.hpp"

class Video
{
public:
    Video(std::string, int);
    void record(cv::Mat);
    enum returnType
    {
        FAIL,
        OK
    };

private:
    cv::VideoCapture _cap;
    cv::VideoWriter _videoWriter;
};


#endif //OPENWCS_VIDEO_H
