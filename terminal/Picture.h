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

#include <memory>
#include <opencv2/opencv.hpp>

#include "camera.h"

// Declaration of Picture class
class Picture
{

public:
    Picture(int index = 0);
    void snap();
    void save(std::string, std::string);
    void displayDate();
    void setVerbose(bool verbose);
    cv::Mat get();

private:
    void echoIfVerbose(std::string);
    cv::Mat _frame;
    bool _verbose = false;
    int _index;
    std::shared_ptr<Camera> _cap;
};

#endif /* Picture_h */
