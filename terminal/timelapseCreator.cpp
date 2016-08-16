//
// Created by Lorenz Kofler on 10.08.16.
//

#include "opencv2/opencv.hpp"
#include "timelapseCreator.h"
#include <Poco/Exception.h>
#include  <Poco/File.h>

void createTimelapse(std::string pathPic, std::string pathVid, std::string videoName, int FPS)
{
    std::string fullPathVid = pathVid + videoName + ".avi";
    cv::Mat _frame;
    cv::VideoWriter _videoWriter;
    int FCC = CV_FOURCC('M', 'J', 'P', 'G'); //fourcc.org

    Poco::File allFiles(pathPic);
    std::vector<std::string> files;
    allFiles.list(files);
    std::vector<std::string> pictures;
    for (std::string e : files) {
        Poco::File temp(pathPic + e);
        if (!temp.isHidden() && !temp.isDirectory() && temp.canRead())
            pictures.push_back(e);
    }
    if (pictures.size() < 2)
        throw Poco::ApplicationException("Less than 2 pictures in directory!");

    std::sort(files.begin(), files.end());

    _frame = cv::imread(pathPic + pictures[0]);
    cv::Size frameSize((double)_frame.cols, (double)_frame.rows);
    _videoWriter.open(fullPathVid, FCC, FPS, frameSize);

    for (std::string e : pictures) {
        _frame = cv::imread(pathPic + e);
        _videoWriter.write(_frame);
    }
}

