//
// Created by Lorenz Kofler on 16.08.16.
//

#include <Poco/Exception.h>
#include "generalFunctions.h"
#include "Picture.h"

void timelapseSnapPicture(const std::string value)
{
    try {
        Picture picture;
        picture.snap();
        picture.displayDate();
        picture.save(value);
    }

    catch (Poco::Exception &exc) {
        std::cerr << exc.displayText() << std::endl;
    }

}
