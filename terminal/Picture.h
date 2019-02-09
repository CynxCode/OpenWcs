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

public:
    Picture();
    void snap(int index = 0);
    void save(std::string, std::string);
    void displayDate();
    void setVerbose(bool verbose);
    cv::Mat get();

private:
    void echoIfVerbose(std::string);
    cv::Mat _frame;
    bool verbose = false;
};

#endif /* Picture_h */
