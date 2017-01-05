//
// HTTPServerApplication.cpp
//
// Created by konstantin.
// Copyright 2017 ${ORGANIZATION_NAME}.
//
// Distributed under GNU GPL, Version 3.0.
// See the accompanying file LICENSE or http://www.gnu.org/licenses/.
//
#include "HTTPServerApplication.h"

#include "HandlerFactory.h"

HTTPServerApplication::HTTPServerApplication(Poco::UInt16 port)
{
    Poco::Net::ServerSocket socket(port);

    Poco::Net::HTTPServerParams *pParams = new Poco::Net::HTTPServerParams();
    pParams->setMaxQueued(100);
    pParams->setMaxThreads(16);

    server = new Poco::Net::HTTPServer(new HandlerFactory(), socket, pParams);
    server->start();
}
HTTPServerApplication::~HTTPServerApplication()
{
    server->stop();
}