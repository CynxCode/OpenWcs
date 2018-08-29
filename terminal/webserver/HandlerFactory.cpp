//
// HandlerFactory.cpp
//
// Created by konstantin.
// Copyright 2017 ${ORGANIZATION_NAME}.
//
// Distributed under GNU GPL, Version 3.0.
// See the accompanying file LICENSE or http://www.gnu.org/licenses/.
//
#include "HandlerFactory.h"
#include "ResponseHandler.h"

HandlerFactory::HandlerFactory()
= default;

Poco::Net::HTTPRequestHandler *HandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest &request)
{
    return new ResponseHandler();
}