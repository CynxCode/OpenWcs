//
// Created by Lorenz Kofler on 07/03/2017.
//

#include "mail.h"
#include <iostream>
#include <Poco/Net/MailMessage.h>
#include <Poco/Net/MailRecipient.h>
#include <Poco/Net/SMTPClientSession.h>
#include <Poco/Net/NetException.h>
#include <Poco/Net/FilePartSource.h>

void mail::sendMail()
{

     std::string host = "mail.cynx.eu";
      Poco::UInt16 port = 25;
       std::string user = "notifications@cynx.eu";
         std::string password = "Lorenz0815";
        std::string to = "lorenz.kofler@gmail.com";
        std::string from = "lorenz.kofler@gmail.com";
        std::string subject = "Your first e-mail message sent using Poco Libraries";
        subject = Poco::Net::MailMessage::encodeWord(subject, "UTF-8");
        std::string content = "Well done! You've successfully sent your first message using Poco SMTPClientSession";
        Poco::Net::MailMessage message;
        message.setSender(from);
        message.addRecipient(Poco::Net::MailRecipient(Poco::Net::MailRecipient::PRIMARY_RECIPIENT, to));
        message.setSubject(subject);
        message.setContentType("text/plain; charset=UTF-8");
        message.setContent(content, Poco::Net::MailMessage::ENCODING_8BIT);
        Poco::Net::FilePartSource *image = new Poco::Net::FilePartSource("image.jpg", "image/jpeg");

        try {
            Poco::Net::SMTPClientSession session(host, port);
            session.open();
            try {
                session.login(Poco::Net::SMTPClientSession::AUTH_LOGIN, user, password);
                session.sendMessage(message);
                std::cout << "Message successfully sent" << std::endl;
                session.close();
            } catch (Poco::Net::SMTPException &e) {
                std::cerr << e.displayText() << std::endl;
                session.close();
               // return 0;
            }
        } catch (Poco::Net::NetException &e) {
            std::cerr << e.displayText() << std::endl;
            //return 0;
        }



}