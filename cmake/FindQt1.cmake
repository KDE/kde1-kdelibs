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

set(QT1_FOUND 0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

include(Qt1Macros)

if(UNIX)
  find_path(QT_INCLUDE_DIR qapp.h
    /opt/qt1/include
    /opt/qt1/include/qt
    ${QT1_INCLUDE_DIR}
    )

  find_library(QT_LIBRARIES qt
    /opt/qt1/lib64
    ${QT1_LIBRARY_DIR}
    )

endif()

# handle the QUIETLY and REQUIRED arguments and set MOTIF_FOUND to TRUE if
# all listed variables are TRUE
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Qt1 DEFAULT_MSG QT_LIBRARIES QT_INCLUDE_DIR)

mark_as_advanced(
  QT_INCLUDE_DIR
  QT_LIBRARIES
)

set(_LIBDIR_DEFAULT "lib")
if("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")
    set(_LIBDIR_DEFAULT "lib64")
endif()

set(KDE1_PREFIX /opt/kde1)
set(KDE1_APPSDIR ${KDE1_PREFIX}/share/applnk)
set(KDE1_BINDIR ${KDE1_PREFIX}/bin)
set(KDE1_CGIDIR ${KDE1_PREFIX}/cgi-bin)
set(KDE1_CONFDIR ${KDE1_PREFIX}/share/config)
set(KDE1_DATADIR ${KDE1_PREFIX}/share/apps)
set(KDE1_HTMLDIR ${KDE1_PREFIX}/share/doc/HTML)
set(KDE1_ICONDIR ${KDE1_PREFIX}/share/icons)
set(KDE1_INCLUDES ${KDE1_PREFIX}/include)
set(KDE1_LIBRARIES ${KDE1_PREFIX}/${_LIBDIR_DEFAULT})
set(KDE1_LOCALE ${KDE1_PREFIX}/share/locale)
set(KDE1_MIMEDIR ${KDE1_PREFIX}/share/mimelnk)
set(KDE1_MINIDIR ${KDE1_PREFIX}/share/icons/mini)
set(KDE1_PARTSDIR ${KDE1_PREFIX}/parts)
set(KDE1_SOUNDDIR ${KDE1_PREFIX}/share/sounds)
set(KDE1_TOOLBARDIR ${KDE1_PREFIX}/share/toolbar)
set(KDE1_WALLPAPERDIR ${KDE1_PREFIX}/share/wallpapers)

