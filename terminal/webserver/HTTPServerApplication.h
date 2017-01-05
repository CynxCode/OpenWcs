//
// HTTPServerApplication.h
//
// Created by konstantin.
// Copyright 2017 ${ORGANIZATION_NAME}.
//
// Distributed under GNU GPL, Version 3.0.
// See the accompanying file LICENSE or http://www.gnu.org/licenses/.
//
#ifndef OPENWCS_HTTPSERVERAPPLICATION_H
#define OPENWCS_HTTPSERVERAPPLICATION_H

#include <Poco/Net/HTTPServer.h>

class HTTPServerApplication
{
public:
    HTTPServerApplication(Poco::UInt16);
    ~HTTPServerApplication();
private:
    Poco::SharedPtr<Poco::Net::HTTPServer> server;
};


#endif //OPENWCS_HTTPSERVERAPPLICATION_H
