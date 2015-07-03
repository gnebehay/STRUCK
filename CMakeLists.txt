project(STRUCK)

cmake_minimum_required(VERSION 2.6)

find_package(OpenCV REQUIRED)

set(CMAKE_BUILD_TYPE Release)

INCLUDE_DIRECTORIES ( src/GraphUtils
            /usr/local/include/eigen3
            /usr/include/eigen3
            ${OpenCV_INCLUDE_DIRS})

add_library(STRUCK STATIC
    src/struck/Config.cpp
    src/struck/Features.cpp
    src/struck/HaarFeature.cpp
    src/struck/HaarFeatures.cpp
    src/struck/HistogramFeatures.cpp
    src/struck/ImageRep.cpp
    src/struck/LaRank.cpp
    src/struck/main.cpp
    src/struck/MultiFeatures.cpp
    src/struck/RawFeatures.cpp
    src/struck/Sampler.cpp
    src/struck/Tracker.cpp
    src/struck/GraphUtils/GraphUtils.cpp
    )

target_link_libraries(STRUCK ${OpenCV_LIBS})
