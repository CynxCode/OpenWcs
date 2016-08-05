set(TARGET_NAME OpenWcs)
project(${TARGET_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(PkgConfig REQUIRED)
pkg_check_modules(OPENCV opencv)

set(SOURCE_FILES main.cpp Overlay.cpp Picture.cpp DateTimeString.cpp)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(${TARGET_NAME} ${SOURCE_FILES})
target_link_libraries(${TARGET_NAME} PocoUtil PocoJSON PocoXML PocoFoundation ${OPENCV_LIBRARIES})
target_include_directories(${TARGET_NAME} PUBLIC ${OPENCV_INCLUDE_DIRS})
target_compile_options(${TARGET_NAME} PUBLIC ${OPENCV_CFLAGS_OTHER})