#=============================================================================
# Copyright 2016 Helio Chissini de Castro <helio@kde.org>
#
# Distributed under the OSI-approved BSD License (the "License");
# see accompanying file Copyright.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================
# (To distribute this file outside of CMake, substitute the full
#  License text for the above reference.)

set(KDE1_FOUND 0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(X11 REQUIRED)
find_package(Qt1 REQUIRED)
find_package(Gettext REQUIRED)

include(CMakePackageConfigHelpers)
include(KDE1Macros)
include(KDE1InstallDirs)

if(UNIX)
    message(STATUS "Looking for KDE1 headers and libraries")
    find_path(KDE1_INCLUDE_DIR kapp.h ${KDE1_INCLUDES})
    find_library(KDE1_KDECORE kdecore ${KDE1_LIBRARIES})
    find_library(KDE1_KDEUI kdeui ${KDE1_LIBRARIES})
    find_library(KDE1_KFILE kfile ${KDE1_LIBRARIES})
    find_library(KDE1_KFM kfm ${KDE1_LIBRARIES})
    find_library(KDE1_KIMGIO kimgio ${KDE1_LIBRARIES})
    find_library(KDE1_KHTMLW khtmlw ${KDE1_LIBRARIES})
    find_library(KDE1_JSCRIPT jscript ${KDE1_LIBRARIES})
    find_library(KDE1_MEDIATOOL mediatool ${KDE1_LIBRARIES})
    find_library(KDE1_KSPELL kspell ${KDE1_LIBRARIES})
endif()

mark_as_advanced(
    KDE1_INCLUDE_DIR
    KDE1_KDECORE
    KDE1_KDEUI
    KDE1_KFILE
    KDE1_KFM
    KDE1_KIMGIO
    KDE1_KHTMLW
    KDE1_JSCRIPT
    KDE1_MEDIATOOL
    KDE1_KSPELL
)
