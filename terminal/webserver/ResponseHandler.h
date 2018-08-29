//
// ResponseHandler.h
//
// Created by konstantin.
// Copyright 2017 ${ORGANIZATION_NAME}.
//
// Distributed under GNU GPL, Version 3.0.
// See the accompanying file LICENSE or http://www.gnu.org/licenses/.
//
#ifndef OPENWCS_RESPONSEHANDLER_H
#define OPENWCS_RESPONSEHANDLER_H

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

class ResponseHandler: public Poco::Net::HTTPRequestHandler
{
public:
    void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override;
};


#endif //OPENWCS_RESPONSEHANDLER_H
