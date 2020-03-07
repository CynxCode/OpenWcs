//
// Created by khp on 10.02.19.
//

#ifndef OPENWCS_WSRESPONSEHANDLER_H
#define OPENWCS_WSRESPONSEHANDLER_H

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

class WSResponseHandler : public Poco::Net::HTTPRequestHandler {
 public:
  void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) override;
};

#endif //OPENWCS_WSRESPONSEHANDLER_H
