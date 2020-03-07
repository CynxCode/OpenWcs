//
// Created by khp on 10.02.19.
//
#include <Poco/Net/MediaType.h>
#include <Poco/Net/WebSocket.h>
#include <Poco/Net/NetException.h>

#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <Poco/URI.h>

#include "WSResponseHandler.h"
#include "../Picture.h"

void WSResponseHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) {
  Poco::URI URI(request.getURI());
  const std::string &Method = request.getMethod();
  if (URI.getPath() == "/stream") {
    try {
      Poco::Net::MediaType mediaType("image/jpeg");
      response.setContentType(mediaType);
      Poco::Net::WebSocket ws(request, response);

      Picture picture;
      char buffer[1024];
      int params[3] = {0};
      params[0] = CV_IMWRITE_JPEG_QUALITY;
      params[1] = 80;

      int flags, n;
      do {
        picture.snap();
        cv::Mat tPicture = picture.get();
        std::vector<uchar> buf;
        cv::imencode(".jpg", tPicture, buf, std::vector<int>(params, params + 2));
        ws.sendFrame(buf.data(), buf.size(), Poco::Net::WebSocket::FRAME_BINARY);
        n = ws.receiveFrame(buffer, sizeof(buffer), flags);
      } while (n > 0 && (flags & Poco::Net::WebSocket::FRAME_OP_BITMASK) != Poco::Net::WebSocket::FRAME_OP_CLOSE);
    }
    catch (Poco::Net::WebSocketException &exc) {
      switch (exc.code()) {
        case Poco::Net::WebSocket::WS_ERR_HANDSHAKE_UNSUPPORTED_VERSION:
          response.set("Sec-WebSocket-Version",
                       Poco::Net::WebSocket::WEBSOCKET_VERSION);
          // fallthrough
        case Poco::Net::WebSocket::WS_ERR_NO_HANDSHAKE:
        case Poco::Net::WebSocket::WS_ERR_HANDSHAKE_NO_VERSION:
        case Poco::Net::WebSocket::WS_ERR_HANDSHAKE_NO_KEY:response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_BAD_REQUEST);
          response.setContentLength(0);
          response.send();
          break;
      }
    }
  } else {
    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_BAD_REQUEST);
    response.setContentLength(0);
    response.send();
  }
}
