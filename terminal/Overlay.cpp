//
//  Overlay.cpp
//  terminal/src
//
//  Created by Konstantin Papesh and Lorenz Kofler.
//  Copyright 2016 OpenWcs.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#include <iostream>
#include "Poco/LocalDateTime.h"
#include "Overlay.h"
#include "DateTimeString.h"


using namespace Poco;
using namespace cv;

void Overlay::putDateOnPicture(Mat frame)
{
    DateTimeString dateTimeString;
    std::string stringDate = dateTimeString.getISO(true, true);

    Point leftBottom(0, frame.rows);
    Point rightTop(frame.cols, frame.rows - 35);
    rectangle(frame, leftBottom, rightTop, Scalar::all(0), CV_FILLED, 8);

    Point textOrg(1, frame.rows - 10);
    putText(frame, stringDate, textOrg, FONT_HERSHEY_DUPLEX, 1, Scalar::all(255), 1, 8);
}

