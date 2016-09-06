//
// Created by Lorenz Kofler on 05.09.16.
//

#ifndef OPENWCS_MOTIONDETECTION_H
#define OPENWCS_MOTIONDETECTION_H

#include "Poco/Util/Timer.h"

namespace Timer
{
class MotionDetection
{
public:
    MotionDetection();
    void check();


private:
    cv::Mat _prev_frame;
    cv::Mat _current_frame;
    cv::Mat _result;
    cv::Mat _pic;
    cv::VideoCapture _cap;
    bool _motionDetected();
    bool _motion;

};
}


#endif //OPENWCS_MOTIONDETECTION_H
