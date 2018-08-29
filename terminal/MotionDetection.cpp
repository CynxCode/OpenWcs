//
// Created by Lorenz Kofler on 05.09.16.
//
#include "opencv2/opencv.hpp"
#include "Picture.h"
#include "Poco/File.h"


#include "MotionDetection.h"


Timer::MotionDetection::MotionDetection() //initatilizes the videocapture
{
    _picPath = _path + ".motiondetection/";
    Poco::File filePicPath(_picPath);
    filePicPath.createDirectory();
}

bool Timer::MotionDetection::_motionDetected() // = 1 if there is motion in the image
{
    Picture picture;
    picture.snap();
    _prev_frame = _current_frame;
    _current_frame = picture.get();
    if (!_prev_frame.data) {
        return false;
    }
    cv::absdiff(_prev_frame, _current_frame, _result);
    cv::cvtColor(_result, _result, CV_RGB2GRAY);
    cv::threshold(_result, _result, 150, 255, CV_THRESH_BINARY);

    return cv::countNonZero(_result) != 0;
}

void Timer::MotionDetection::check()
{
    if (_motionDetected()) {
        try {
            Picture picture;
            picture.snap();
            picture.displayDate();
            picture.save(_picPath, "");
        }
        catch (Poco::Exception &exc) {
            std::cerr << exc.displayText() << std::endl;
        }

        //send Email

        //...
        //filePicPath.remove(1);
    }
}