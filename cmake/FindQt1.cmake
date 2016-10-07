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

set(KDE1_PREFIX /opt/kde1)
set(KDE1_APPSDIR ${KDE1_PREFIX}/share/applnk)
set(KDE1_BINDIR ${KDE1_PREFIX}/bin)
set(KDE1_CGIDIR ${KDE1_PREFIX}/cgi-bin)
set(KDE1_CONFDIR ${KDE1_PREFIX}/share/config)
set(kde_datadir ${KDE1_PREFIX}/share/apps)
set(kde_htmldir ${KDE1_PREFIX}/share/doc/HTML)
set(kde_icondir ${KDE1_PREFIX}/share/icons)
set(kde_includes ${KDE1_PREFIX}/include)
set(kde_libraries ${KDE1_PREFIX}/lib64)
set(kde_locale ${KDE1_PREFIX}/share/locale)
set(kde_mimedir ${KDE1_PREFIX}/share/mimelnk)
set(kde_minidir ${KDE1_PREFIX}/share/icons/mini)
set(kde_partsdir ${KDE1_PREFIX}/parts)
set(kde_sounddir ${KDE1_PREFIX}/share/sounds)
set(kde_toolbardir ${KDE1_PREFIX}/share/toolbar)
set(kde_wallpaperdir ${KDE1_PREFIX}/share/wallpapers)

