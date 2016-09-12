set(TARGET_NAME openwcs)
project(${TARGET_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(PkgConfig REQUIRED)
pkg_check_modules(OPENCV opencv)

set(SOURCE_FILES main.cpp Overlay.cpp Picture.cpp DateTimeString.cpp Video.cpp MainApp.cpp timer/Timelapse.cpp MotionDetection.cpp ThreadVector.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin/)
link_directories(/usr/local/lib)
include_directories(/usr/local/opt/opencv3/include)
link_directories(/usr/local/opt/opencv3/lib)
add_executable(${TARGET_NAME} ${SOURCE_FILES})
add_compile_options(-pthread)
target_link_libraries(${TARGET_NAME} PocoUtil PocoXML PocoFoundation ${OPENCV_LIBRARIES})
target_include_directories(${TARGET_NAME} PUBLIC ${OPENCV_INCLUDE_DIRS})
target_compile_options(${TARGET_NAME} PUBLIC ${OPENCV_CFLAGS_OTHER})
