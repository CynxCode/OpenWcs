//
// Created by Lorenz Kofler on 05.09.16.
//
#include "opencv2/opencv.hpp"
#include "Picture.h"
#include "Poco/File.h"


#include "MotionDetection.h"


Timer::MotionDetection::MotionDetection() //initatilizes the videocapture
{
    _cap = 0; // open the default camera TODO: Choose Camera...
    if (!_cap.isOpened()) {
        throw Poco::ApplicationException("Camera could not be opened!");
    }

    _picPath = _path + ".motiondetection/";
    Poco::File filePicPath(_picPath);
    filePicPath.createDirectory();

}

bool Timer::MotionDetection::_motionDetected() // = 1 if there is motion in the image
{
    _prev_frame = _current_frame;
    if (!_prev_frame.data) {
        _cap >> _current_frame;
        return false;
    }
    _cap >> _current_frame;
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