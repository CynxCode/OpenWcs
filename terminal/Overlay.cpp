//
//  Overlay.cpp
//  terminal/src
//
//  Created by Konstantin Papesh and Lorenz Kofler.
//  Copyright 2016 OpenWcs.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#include <iostream>
#include "Poco/LocalDateTime.h"
#include "Poco/DateTimeFormatter.h"


using namespace Poco;


void putDateOnPicture()
{
    LocalDateTime now;
    DateTimeFormatter dateTimeFormatter;
    std::string stringDate = dateTimeFormatter.format(now, "%W%f%.%n.%Y %H:%M:%S");

}

