//
// Created by khp on 09.02.19.
//

#include "camera.h"

Camera::Camera(int index) : _index{index} {
    _cap.open(_index);
}

Camera::~Camera(){
    _cap.release();
}

cv::Mat Camera::getPic() {
    _cap.grab();
    _cap.retrieve(_lastPic);
    return _lastPic;
}

