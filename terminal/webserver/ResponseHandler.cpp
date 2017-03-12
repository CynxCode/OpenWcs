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
#include "../ThreadVector.h"
#include <Poco/Net/MediaType.h>
#include <Poco/Net/ICMPClient.h>
#include "Poco/URI.h"

void ResponseHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    Poco::URI URI(request.getURI());
    std::string Method = request.getMethod();
    if (URI.getPath() == "/30") {
        Poco::Net::MediaType mediaType("multipart/x-mixed-replace");
        mediaType.setParameter("boundary", "--boundary");

        response.set("Cache-control", "no-cache");
        response.setContentType(mediaType);
        response.set("Expires", "1");
        response.set("Pragma", "no-cache");
        response.setChunkedTransferEncoding(false);
        std::ostream &responseStream = response.send();
        Picture picture;
        int params[3] = {0};
        params[0] = CV_IMWRITE_JPEG_QUALITY;
        params[1] = 80;
        int connectionAlive = true;

        do {
            for (int i = 0; i < 10; i++) {
                picture.snap();

                cv::Mat tPicture = picture.get();
                std::vector<uchar> buf;
                cv::imencode(".jpg", tPicture, buf, std::vector<int>(params, params + 2));
                responseStream << "--boundary";
                responseStream << "\r\n";
                responseStream << "Content-Type: image/jpeg";
                responseStream << "\r\n";
                responseStream << "Content-Length: " << std::to_string(buf.size());
                responseStream << "\r\n";
                responseStream << "\r\n";
                responseStream.write(reinterpret_cast<const char *>(buf.data()), buf.size());
            }
            //connectionAlive = Poco::Net::ICMPClient::pingIPv4(request.clientAddress(), 20);

        }
        while (connectionAlive);
    }
    else if (URI.getPath() == "/snap" && Method == "GET") {
        response.setChunkedTransferEncoding(true);
        try {
            Picture picture;
            usleep(500000); //TODO: anderen Befehl finden!
            picture.snap();
            picture.displayDate();
            picture.save("", "");
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_OK);
            response.send() << "Picture saved!";
        }

        catch (Poco::Exception &exc) {
            std::cerr << exc.displayText() << std::endl;
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_INTERNAL_SERVER_ERROR);
            response.send() << "Error while trying to snap picture!";
        }
    }
    else if (URI.getPath() == "/timelapse" && Method == "GET") {
        static ThreadVector threadVector;
        static int request = 0;
        response.setChunkedTransferEncoding(true);

        int start = 0;
        int intervalSnap = 0;
        int intervalCreate = 0;
        std::string path = "";
        int FPS = 0;
        Poco::URI::QueryParameters query = URI.getQueryParameters();
        for (int i = 0; i < query.size(); i++) {
            if (Poco::toLower(query[i].first) == "invsnap") {
                intervalSnap = std::stoi(query[i].second);
            }
            else if (Poco::toLower(query[i].first) == "invcreate") {
                intervalCreate = std::stoi(query[i].second);
            }
            else if (Poco::toLower(query[i].first) == "fps") {
                FPS = std::stoi(query[i].second);
            }
            else {
                response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_BAD_REQUEST);
                response.send() << "Invalid parameter!";
                return;
            }
        }
        if (!intervalSnap || !intervalCreate || !FPS) {
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_BAD_REQUEST);
            response.send() << "Too few arguments!";
            return;
        }
        Poco::SharedPtr<Timer::Timelapse>
            tempTimelapse(new Timer::Timelapse(start, intervalSnap * 1000, intervalCreate * 1000, "", FPS));
        tempTimelapse->start();
        request++;
        threadVector.addTimelapse("webreq#" + std::to_string(request), tempTimelapse);

        response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_OK);
        response.send();
    }
    else {
        response.redirect(request.getHost(), Poco::Net::HTTPResponse::HTTP_TEMPORARY_REDIRECT);
        response.send();
    }
}