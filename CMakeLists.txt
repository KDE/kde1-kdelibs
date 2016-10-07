cmake_minimum_required (VERSION 3.0)

project (kdelibs)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

find_package(X11 REQUIRED)
find_package(Qt1 REQUIRED)

set(KDELIBS_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

include_directories(common)

add_definitions( -DHAVE_CONFIG_H )

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-fpermissive -Wno-write-strings -std=c++98)
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")
endif()

add_subdirectory(kdecore)
add_subdirectory(kdeui)
add_subdirectory(kfile)
add_subdirectory(kfmlib)
