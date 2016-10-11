cmake_minimum_required (VERSION 3.0)

project (kdelibs)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)

if (NOT CMAKE_BUILD_TYPE)
    #        set(CMAKE_BUILD_TYPE Release)
endif()

# additional cmake files
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(PNG REQUIRED)
find_package(JPEG REQUIRED)
find_package(TIFF REQUIRED)
find_package(X11 REQUIRED)
find_package(Qt1 REQUIRED)
find_package(Gettext REQUIRED)

include(CMakePackageConfigHelpers)
include(KDE1Macros)
include(KDE1InstallDirs)

set(KDELIBS_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

include_directories(common)

add_definitions( -DHAVE_CONFIG_H )

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wno-write-strings")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fpermissive -std=c++98")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")
endif()

install(FILES
    cmake/FindKDE1.cmake
    cmake/FindQt1.cmake
    cmake/KDE1Macros.cmake
    cmake/KDE1InstallDirs.cmake
    cmake/KDE1Macros.cmake
    cmake/Qt1Macros.cmake
    DESTINATION ${CMAKE_ROOT}/Modules)

add_subdirectory(doc)
add_subdirectory(kdecore)
add_subdirectory(kdeui)
add_subdirectory(kfile)
add_subdirectory(kfmlib)
add_subdirectory(jscript)
add_subdirectory(kimgio)
add_subdirectory(khtmlw)
add_subdirectory(mediatool)
add_subdirectory(kspell)
add_subdirectory(kab)
add_subdirectory(toolbar)
add_subdirectory(po)
