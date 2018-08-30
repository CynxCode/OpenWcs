cmake_minimum_required(VERSION 3.0)
project(openwcs)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}")

include(GNUInstallDirs)
find_package(OpenCV REQUIRED)
find_package(Poco REQUIRED Util Net XML Foundation)

add_subdirectory(terminal)