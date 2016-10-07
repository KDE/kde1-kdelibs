#
# This file is included by FindKDE11.cmake, don't include it directly.

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


######################################
#
#       Macros for building KDE1 files
#
######################################

function (install_gmo)
    foreach (it ${ARGN})
        get_filename_component(language ${it} NAME_WE)
        set(infile "${CMAKE_CURRENT_SOURCE_DIR}/${language}.po")
        add_custom_command(
            OUTPUT ${language}.gmo
            COMMAND ${GETTEXT_MSGFMT_EXECUTABLE}
            ARGS ${infile} -o ${language}.gmo
            MAIN_DEPENDENCY ${infile} VERBATIM)
        add_custom_target(gmo_${language} ALL DEPENDS ${language}.gmo)
        install(FILES ${language}.gmo
            DESTINATION ${KDE1_LOCALE}/${language}/LC_MESSAGES
            RENAME kde.mo)
    endforeach ()
endfunction ()

function (install_charsets)
    foreach (it ${ARGN})
        get_filename_component(language ${it} NAME_WE)
        install(FILES ${it}
            DESTINATION ${KDE1_LOCALE}/${language}/
            RENAME charset)
    endforeach ()
endfunction ()

