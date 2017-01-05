//
// HandlerFactory.h
//
// Created by konstantin.
// Copyright 2017 ${ORGANIZATION_NAME}.
//
// Distributed under GNU GPL, Version 3.0.
// See the accompanying file LICENSE or http://www.gnu.org/licenses/.
//
#ifndef OPENWCS_HANDLERFACTORY_H
#define OPENWCS_HANDLERFACTORY_H

#include <Poco/Net/HTTPRequestHandlerFactory.h>

class HandlerFactory: public Poco::Net::HTTPRequestHandlerFactory
{
public:
    HandlerFactory();
    Poco::Net::HTTPRequestHandler *createRequestHandler(const Poco::Net::HTTPServerRequest &request);
};


#endif //OPENWCS_HANDLERFACTORY_H
