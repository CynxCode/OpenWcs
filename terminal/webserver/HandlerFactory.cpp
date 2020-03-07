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
#include "WSResponseHandler.h"

HandlerFactory::HandlerFactory()
= default;

Poco::Net::HTTPRequestHandler *HandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest &request) {
  if (request.find("Upgrade") != request.end() && Poco::icompare(request["Upgrade"], "websocket") == 0)
    return new WSResponseHandler;
  else
    return new ResponseHandler;
}