//
// Created by khp on 09.02.19.
//

#include "camera.h"

Camera::Camera(int index) : _index{index} {}

cv::Mat Camera::getPic() {
    _cap.open(_index);
    _cap.grab();
    _cap.retrieve(_lastPic);
    _cap.release();
    return _lastPic;
}
