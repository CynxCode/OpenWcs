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


#include "opencv2/opencv.hpp"
#include "Poco/Exception.h"

#include "Overlay.h"
#include "Picture.h"
#include "DateTimeString.h"

Picture::Picture()
{
    _cap = 0; // open the default camera TODO: Choose Camera...

    if(!_cap.isOpened())
    {
        throw Poco::ApplicationException("Camera could not be opened!");
    }
}

void Picture::snap()
{
    _cap >> _frame;
}

void Picture::save(std::string name)
{

    if(_frame.empty())
        throw Poco::LogicException("Frame is empty!");

    if (name.empty()) {
        DateTimeString dateTimeString;
        name = dateTimeString.getISO(true, true);
    }
    std::string imagename = "IMG_" + name + ".jpg";
    imwrite(imagename, _frame);
}

void Picture::displayDate()
{
    Overlay overlay;
    overlay.putDateOnPicture(_frame);
}

cv::Mat Picture::get()
{
    return _frame;
}







