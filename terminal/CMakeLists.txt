set(TARGET_NAME terminal)
project(${TARGET_NAME})

# set version number
set (openwcs_VERSION_MAJOR 0)
set (openwcs_VERSION_MINOR 2)
set (openwcs_VERSION_PATCH 0)
set (openwcs_COPYRIGHT_YEAR 2019)

# pass metadata to header
configure_file(
        "${PROJECT_SOURCE_DIR}/Config.h.in"
        "${PROJECT_BINARY_DIR}/Config.h"
)
include_directories("${PROJECT_BINARY_DIR}")

set(SOURCE_FILES main.cpp Overlay.cpp Picture.cpp DateTimeString.cpp Video.cpp MainApp.cpp timer/Timelapse.cpp MotionDetection.cpp ThreadVector.cpp webserver/HTTPServerApplication.cpp webserver/HTTPServerApplication.h webserver/HandlerFactory.cpp webserver/HandlerFactory.h webserver/ResponseHandler.cpp webserver/ResponseHandler.h mail.cpp mail.h CameraHandler.cpp CameraHandler.h ConfigHandler.cpp ConfigHandler.h camera.cpp camera.h webserver/WSResponseHandler.cpp webserver/WSResponseHandler.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin/)
add_executable(${TARGET_NAME} ${SOURCE_FILES})
add_compile_options(-pthread)
target_include_directories(${TARGET_NAME} PRIVATE ${Poco_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${TARGET_NAME} ${Poco_LIBRARIES} ${OpenCV_LIBRARIES})
target_compile_options(${TARGET_NAME} PUBLIC ${OPENCV_CFLAGS_OTHER})

install(TARGETS terminal EXPORT MyLibraryConfig
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        CONFIGURATIONS release)

# build a CPack driven installer package
include(InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
        "../LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${openwcs_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${openwcs_VERSION_MINOR}")
set(CPACK_PACKAGE_VENDOR "OpenWcs")
set(CPACK_RESOURCE_FILE_README
        "../README.md")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A webcam software")
set(CPACK_PACKAGE_ICON
        "../logo.png")
#set(CPACK_GENERATOR  "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Konstantin Papesh")
include(CPack)