//
// Created by Lorenz Kofler on 10.08.16.
//

#include "opencv2/opencv.hpp"
#include "timelapseCreator.h"
#include <iostream>

void createTimelapse(std::string path, std::string fileName, int FPS)
{
    cv::Mat _frame;
    cv::VideoWriter _videoWriter;
    int FCC = CV_FOURCC('M', 'J', 'P', 'G'); //fourcc.org
    std::string imgNamePrefix = "IMG_";
    std::string imgNameSuffix = ".jpg";

    fileName = fileName + ".avi";


    _frame = cv::imread(imgNamePrefix + "1" + imgNameSuffix); //

    cv::Size frameSize((double)_frame.cols, (double)_frame.rows);
    _videoWriter.open(fileName, FCC, FPS, frameSize);

    for (int i = 1; i++;) {
        std::string imgName = imgNamePrefix + std::to_string(i) + imgNameSuffix;
        _frame = cv::imread(imgName);
        if (_frame.empty()) {
            break;
        }
        _videoWriter.write(_frame);
    }
}
