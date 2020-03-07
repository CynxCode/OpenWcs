//
// ResponseHandler.cpp
//
// Created by konstantin.
// Copyright 2017 ${ORGANIZATION_NAME}.
//
// Distributed under GNU GPL, Version 3.0.
// See the accompanying file LICENSE or http://www.gnu.org/licenses/.
//
#include <Poco/Net/MediaType.h>
#include <Poco/Net/ICMPClient.h>
#include <Poco/URI.h>

#include <opencv2/opencv.hpp>

#include "ResponseHandler.h"
#include "../Picture.h"
#include "../ThreadVector.h"

void ResponseHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) {
  Poco::URI URI(request.getURI());
  const std::string &Method = request.getMethod();
  if (URI.getPath() == "/stream") { //TODO: Include this in webserver
    response.setChunkedTransferEncoding(true);
    response.setContentType("text/html");
    std::ostream &ostr = response.send();
    ostr << "<html>";
    ostr << "<head>";
    ostr << "<title>WebSocketServer</title>";
    ostr << "<script type=\"text/javascript\">";
    ostr << "function WebSocketTest()";
    ostr << "{";
    ostr << "  if (\"WebSocket\" in window)";
    ostr << "  {";
    ostr << "    var ws = new WebSocket(\"ws://" << request.serverAddress().toString() << "/stream\");";
    ostr << "    ws.onmessage = function(evt)";
    ostr << "      { ";
    ostr << "        var msg = evt.data;";
    ostr << "        var objectURL = URL.createObjectURL(msg);";
    ostr << "        var image = document.getElementById('image');";
    ostr << "        image.src = objectURL;";
    ostr << "        ws.send(\"rcvd\");";
    ostr << "      };";
    ostr << "    ws.onclose = function()";
    ostr << "      { ";
    ostr << "        alert(\"WebSocket closed.\");";
    ostr << "      };";
    ostr << "  }";
    ostr << "  else";
    ostr << "  {";
    ostr << "     alert(\"This browser does not support WebSockets.\");";
    ostr << "  }";
    ostr << "}";
    ostr << "</script>";
    ostr << "</head>";
    ostr << "<body>";
    ostr << "  <h1>WebSocket Server</h1>";
    ostr << "  <img id=\"image\">";
    ostr << "  <p><a href=\"javascript:WebSocketTest()\">Run WebSocket Script</a></p>";
    ostr << "</body>";
    ostr << "</html>";
  } else if (URI.getPath() == "/snap" && Method == "GET") {
    response.setChunkedTransferEncoding(true);
    try {
      Picture picture;
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
  } else if (URI.getPath() == "/timelapse" && Method == "GET") {
    static ThreadVector threadVector;
    static int request = 0;
    response.setChunkedTransferEncoding(true);

    int start = 0;
    int intervalSnap = 0;
    int intervalCreate = 0;
    std::string path;
    int FPS = 0;
    Poco::URI::QueryParameters query = URI.getQueryParameters();
    for (auto &i : query) {
      if (Poco::toLower(i.first) == "invsnap") {
        intervalSnap = std::stoi(i.second);
      } else if (Poco::toLower(i.first) == "invcreate") {
        intervalCreate = std::stoi(i.second);
      } else if (Poco::toLower(i.first) == "fps") {
        FPS = std::stoi(i.second);
      } else {
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
    tempTimelapse->setName("webreq#" + std::to_string(request));
    tempTimelapse->start();
    request++;
    ThreadVector::addTimelapse(tempTimelapse);

    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_OK);
    response.send();
  } else {
    response.redirect(request.getHost(), Poco::Net::HTTPResponse::HTTP_TEMPORARY_REDIRECT);
    response.send();
  }
}