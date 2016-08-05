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

#include "Overlay.h"
#include "Picture.h"
#include "DateTimeString.h"

int Picture::init()
{
    _cap = 0; // open the default camera TODO: Choose Camera...
    if (_cap.isOpened())  // check if we succeeded
        return OK;
    else
        return FAIL;
}

void Picture::snap()
{
    _cap >> _frame;
}

void Picture::save(std::string name)
{
    if (name.empty()) {
        DateTimeString dateTimeString;
        name = dateTimeString.getISO();
    }
    std::string imagename = name + ".jpg";
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





