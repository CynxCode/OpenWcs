//
//  Timelapse.cpp
//  terminal/timer
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
#include "Poco/File.h"

Timer::Timelapse::Timelapse(int start, int intervalSnap, int intervalCreate, std::string path, int FPS)
{
    this->FPS = FPS;
    this->path = path;
    this->startTime = start;
    this->intervalSnap = intervalSnap;
    this->intervalCreate = intervalCreate;

    setAndCreatePicPath();
}
void Timer::Timelapse::start()
{
    Poco::Util::TimerTask::Ptr timerTaskCreateTimelapse =
        new Poco::Util::TimerTaskAdapter<Timelapse>(*this, &Timer::Timelapse::createTimelapse);
    Poco::Util::TimerTask::Ptr timerTaskSnapPic =
        new Poco::Util::TimerTaskAdapter<Timelapse>(*this, &Timer::Timelapse::snapPicture);

    timer.schedule(timerTaskSnapPic, startTime, intervalSnap);
    timer.schedule(timerTaskCreateTimelapse, startTime, intervalCreate);
}
void Timer::Timelapse::stop()
{
    timer.cancel(true);
}
void Timer::Timelapse::createTimelapse(Poco::Util::TimerTask &task)
{
    cv::Mat _frame;
    cv::VideoWriter _videoWriter;
    int FCC = CV_FOURCC('M', 'J', 'P', 'G'); //fourcc.org

    Poco::File allFiles(picPath);
    std::vector<std::string> files;
    allFiles.list(files);
    std::vector<std::string> pictures;
    for (std::string e : files) {
        Poco::File temp(picPath + e);
        if (!temp.isHidden() && !temp.isDirectory() && temp.canRead())
            pictures.push_back(e);
    }
    if (pictures.size() < 2)
        throw Poco::ApplicationException("Less than 2 pictures in directory!");

    std::sort(files.begin(), files.end());
    std::string name1 = pictures[0].substr(4, 15);
    std::string name2 = pictures.back().substr(4, 15);
    std::string videoName = name1 + " - " + name2;

    std::string fullPathVid = path + videoName + ".avi";
    _frame = cv::imread(picPath + pictures[0]);
    cv::Size frameSize((double) _frame.cols, (double) _frame.rows);
    _videoWriter.open(fullPathVid, FCC, FPS, frameSize);

    for (std::string e : pictures) {
        _frame = cv::imread(picPath + e);
        _videoWriter.write(_frame);
    }
}
void Timer::Timelapse::snapPicture(Poco::Util::TimerTask &task)
{
    try {
        Picture picture;
        picture.snap();
        picture.displayDate();
        picture.save(picPath, "");
    }
    catch (Poco::Exception &exc) {
        std::cerr << exc.displayText() << std::endl;
    }
}

void Timer::Timelapse::setAndCreatePicPath()
{
    picPath = path + ".pictures/";
    Poco::File filePicPath(picPath);
    filePicPath.createDirectory();
}

