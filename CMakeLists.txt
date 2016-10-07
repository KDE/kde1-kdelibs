cmake_minimum_required (VERSION 3.0)

project (kdelibs)

include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Qt1Macros.cmake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(
    common
    /opt/qt1/include/qt
    )

link_directories(/opt/qt1/lib64)

add_definitions( -DHAVE_CONFIG_H )

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-fpermissive -Wno-write-strings -std=c++98)
endif()

add_subdirectory(kdecore)
