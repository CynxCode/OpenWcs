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


#include <thread>
#include "opencv2/opencv.hpp"
#include "Poco/Exception.h"

#include "Overlay.h"
#include "Picture.h"
#include "DateTimeString.h"
#include "CameraHandler.h"

Picture::Picture(int index) : _index{index}{
    CameraHandler cameraHandler;
  _cap = CameraHandler::getCamera(_index);
}

void Picture::snap() {
  std::this_thread::sleep_for(std::chrono::milliseconds(500)); //to start camera
  echoIfVerbose("Snapping picture...");
  _frame = _cap->getPic();
}

void Picture::echoIfVerbose(const std::string &msg) const {
  if (_verbose) {
    std::cout << msg << std::endl;
  }
}

void Picture::save(const std::string &path, std::string name) //saves the picture
{
  std::string imagename;
  if (_frame.empty())
    throw Poco::LogicException("Frame is empty!");

  if (name.empty()) {
    DateTimeString dateTimeString;
    name = DateTimeString::getISO(true, true);
    imagename = path + "IMG_" + name + ".jpg";
  }
    else{
        imagename = path + name + ".jpg";
    }
    imwrite(imagename, _frame);
    echoIfVerbose("Saved " + name + " to " + path + " successfully!");
}

void Picture::displayDate() //enables displaying the date on the picture
{
    Overlay overlay;
  Overlay::putDateOnPicture(_frame);
}

void Picture::setVerbose(bool verbose) //Echos steps to the console
{
    this->_verbose = verbose;
}

cv::Mat Picture::get() 
{
    return _frame;
}







