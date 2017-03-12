//
//  Timelapse.cpp
//  terminal/_timer
//
//  Created by Konstantin Papesh and Lorenz Kofler.
//  Copyright 2016 OpenWcs.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#include "Timelapse.h"
#include "Poco/Util/TimerTaskAdapter.h"
#include "../Picture.h"
#include "../ThreadVector.h"

Timer::Timelapse::Timelapse(int start, int intervalSnap, int intervalCreate, std::string path, int FPS)
{
    this->_FPS = FPS;
    this->_path = path;
    this->_startTime = start;
    this->_intervalSnap = intervalSnap;
    this->_intervalCreate = intervalCreate;

    setAndCreatePicPath();
}
void Timer::Timelapse::start()
{
    Poco::Util::TimerTask::Ptr timerTaskCreateTimelapse =
        new Poco::Util::TimerTaskAdapter<Timelapse>(*this, &Timer::Timelapse::createTimelapse);

    Poco::Util::TimerTask::Ptr timerTaskSnapPic =
        new Poco::Util::TimerTaskAdapter<Timelapse>(*this, &Timer::Timelapse::snapPicture);

    _timer.schedule(timerTaskSnapPic, _startTime, _intervalSnap);
    _timer.schedule(timerTaskCreateTimelapse, _intervalCreate, _intervalCreate);

    DateTimeString getStartDate;
    _startDate = getStartDate.getISO(true,true);
}
void Timer::Timelapse::stop()
{
    _timer.cancel(true);
}
void Timer::Timelapse::setName(std::string tName)
{
    this->_name = tName;
}
std::string Timer::Timelapse::getName()
{
    return this->_name;
}
void Timer::Timelapse::createTimelapse(Poco::Util::TimerTask &task)
{
    static ThreadVector threadVector;
    DateTimeString getEndDate;
    _endDate = getEndDate.getISO(true,true);

    cv::Mat _frame;
    cv::VideoWriter _videoWriter;
    int FCC = CV_FOURCC('M', 'J', 'P', 'G'); //fourcc.org

    std::string startName = _startDate.substr(4, 15);
    std::string endName = _endDate.substr(4, 15);
    std::string videoName = startName + " - " + endName;
    std::string fullPathVid = _path + videoName + ".avi";

    _frame = cv::imread(_picPath + "0" + ".jpg");
    cv::Size frameSize( _frame.cols, _frame.rows);
    _videoWriter.open(fullPathVid, FCC, _FPS, frameSize,true);

    for (int i = 0; i < _picNo; i++)
    {
        _frame = cv::imread(_picPath + std::to_string(i) + ".jpg");
        _videoWriter.write(_frame);
    }

    Poco::File delPath(_path + ".pictures");
    delPath.remove(1);  //removes .pictures Folder
    threadVector.removeTimelapse(this);
    stop(); //stops timer
}
void Timer::Timelapse::snapPicture(Poco::Util::TimerTask &task)
{
    try {
        Picture picture;
        picture.snap();
        picture.displayDate();
        picture.save(_picPath, std::to_string(_picNo));
        _picNo++;
    }
    catch (Poco::Exception &exc) {
        std::cerr << exc.displayText() << std::endl;
        stop();
    }
}

void Timer::Timelapse::setAndCreatePicPath()
{
    _picPath = _path + ".pictures/";
    Poco::File filePicPath(_picPath);
    filePicPath.createDirectory();
}