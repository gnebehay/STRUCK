cmake_minimum_required(VERSION 2.6)

string(REGEX REPLACE "cmake$" "" struck_path ${CMAKE_CURRENT_LIST_FILE})

include_directories(${struck_path}/src)
include_directories(/usr/include/eigen3
                    /usr/local/include/eigen3)

if (NOT TARGET STRUCK)
  add_subdirectory(${struck_path} struck_build)
endif()
