//
//  Picture.h
//  terminal/src
//
//  Created by Konstantin Papesh and Lorenz Kofler.
//  Copyright 2016 OpenWcs.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#ifndef Picture_h
#define Picture_h

#include "opencv2/opencv.hpp"

// Declaration of Picture class
class Picture
{

public:      //jede class kann die aufrufen
    void snap();
    void save(std::string);
    void displayDate(bool);
    int init();
    enum returnType
    {
        FAIL,
        OK
    };
private:    //nur die class Picture darf zugreifen
    cv::VideoCapture _cap;
    cv::Mat _frame;
};

#endif /* Picture_h */
