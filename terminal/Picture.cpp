//
//  Picture.cpp
//  terminal/src
//
//  Created by Konstantin Papesh and Lorenz Kofler.
//  Copyright 2016 OpenWcs.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#include "Poco/DateTime.h"
#include "opencv2/opencv.hpp"

#include "Picture.h"

int Picture::init()
{
    cv::VideoCapture _cap(0); // open the default camera
    if (_cap.isOpened())  // check if we succeeded
        return OK;
    else
        return FAIL;
}

void Picture::snap()
{
    _cap >> _frame;
}

void Picture::save(std::string imgName)
{
    cv::imwrite(imgName, _frame);
}

void Picture::displayDate(bool isSet)
{
    Poco::DateTime now;
}




