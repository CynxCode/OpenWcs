//
// ResponseHandler.cpp
//
// Created by konstantin.
// Copyright 2017 ${ORGANIZATION_NAME}.
//
// Distributed under GNU GPL, Version 3.0.
// See the accompanying file LICENSE or http://www.gnu.org/licenses/.
//
#include "ResponseHandler.h"
#include "opencv2/opencv.hpp"
#include "../Picture.h"
#include <Poco/Net/MediaType.h>

void ResponseHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    std::string URI = request.getURI();
    if (URI == "/30") {
        Poco::Net::MediaType mediaType("multipart/x-mixed-replace");
        mediaType.setParameter("boundary", "--boundary");

        response.set("Cache-control", "no-cache");
        response.setContentType(mediaType);
        response.set("Expires", "5");
        response.set("Pragma", "no-cache");
        std::ostream &responseStream = response.send();
        Picture picture;
        int params[3] = {0};
        params[0] = CV_IMWRITE_JPEG_QUALITY;
        params[1] = 80;

        for (int i = 0; i < 1000; i++) {
            picture.snap();

            cv::Mat tPicture = picture.get();
            std::vector<uchar> buf;
            bool code = cv::imencode(".jpg", tPicture, buf, std::vector<int>(params, params + 2));
            responseStream << "--boundary";
            responseStream << "\r\n";
            responseStream << "Content-Type: image/jpeg";
            responseStream << "\r\n";
            responseStream << "Content-Length: " << std::to_string(buf.size());
            responseStream << "\r\n";
            responseStream << "\r\n";
            responseStream.write(reinterpret_cast<const char *>(buf.data()), buf.size());
        }
    }
    else {
        response.setChunkedTransferEncoding(true);
        response.setContentType("text/html");

        std::ostream &responseStream = response.send();
        responseStream << "<html><head><head><title>Simple HTTP Server</title></head>";
        responseStream << "<body><h1>Wo willsten du hin?</h1>";
        responseStream << "</body></html>";
    }
}