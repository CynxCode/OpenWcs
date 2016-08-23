//
// Created by Lorenz Kofler on 09.08.16.
//

#include <opencv2/videoio.hpp>
#include <opencv2/videoio/videoio_c.h>
#include <Poco/Exception.h>
#include "Video.h"
#include "iostream"



Video::Video(std::string filename, int fps)
{
    int fcc = CV_FOURCC('M','J','P','G'); //fourcc.org

    cv::Size frameSize((int)_cap.get(CV_CAP_PROP_FRAME_WIDTH), (int)_cap.get(CV_CAP_PROP_FRAME_HEIGHT));
    _videoWriter.open(filename,fcc,fps,frameSize);

    if(!_videoWriter.isOpened())
        throw Poco::ApplicationException("Video could not be opened!");
}

void Video::record(cv::Mat _frame)
{
    _videoWriter.write(_frame);
}

