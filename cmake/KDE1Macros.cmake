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
# Macros for building KDE1 files
#
######################################

function (install_kdegmo)
    foreach (it ${ARGN})
        get_filename_component(language ${it} NAME_WE)
        set(infile "${CMAKE_CURRENT_SOURCE_DIR}/${language}.po")
        add_custom_command(
            OUTPUT ${language}.gmo
            COMMAND ${GETTEXT_MSGFMT_EXECUTABLE}
            ARGS ${infile} -o ${language}.gmo
            MAIN_DEPENDENCY ${infile} VERBATIM)
        add_custom_target(gmo_${language} ALL DEPENDS ${language}.gmo)
        install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${language}.gmo"
            DESTINATION ${KDE1_LOCALE}/${language}/LC_MESSAGES
            RENAME kde.mo)
    endforeach ()
endfunction ()

function (install_gmo)
    set(language ${ARGV0})
    set(list_var "${ARGN}")
    list(REMOVE_AT list_var 0)
    foreach (it IN LISTS list_var)
        get_filename_component(module ${it} NAME_WE)
        set(infile "${CMAKE_CURRENT_SOURCE_DIR}/${module}.po")
        add_custom_command(
            OUTPUT ${module}.gmo
            COMMAND ${GETTEXT_MSGFMT_EXECUTABLE}
            ARGS ${infile} -o ${module}.gmo
            MAIN_DEPENDENCY ${infile} VERBATIM)
        list(APPEND elements ${module}.gmo)
        install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${module}.gmo"
            DESTINATION ${KDE1_LOCALE}/${language}/LC_MESSAGES
            RENAME ${module}.mo)
    endforeach ()
    add_custom_target(gmo_${language}_${module} ALL DEPENDS ${elements})
endfunction ()

function (install_charsets)
    foreach (it ${ARGN})
        get_filename_component(language ${it} NAME_WE)
        install(FILES ${it}
            DESTINATION ${KDE1_LOCALE}/${language}/
            RENAME charset)
    endforeach ()
endfunction ()

function (install_potfiles languages potfiles)
    foreach(pot "${potfiles}")
        foreach(ln "${languages}")
            get_filename_component(potfile ${pot} NAME_WE)
            set(infile "${CMAKE_CURRENT_SOURCE_DIR}/${pot}.pot")
            set(basefile "${CMAKE_CURRENT_SOURCE_DIR}/i${ln}/${pot}.po")
            if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${basefile}")
                add_custom_command(
                    OUTPUT ${pot}.po
                    COMMAND ${GETTEXT_MSGMERGE_EXECUTABLE}
                    ARGS ${infile} -o ${pot}.po ${basefile} ${infile}
                    MAIN_DEPENDENCY ${infile} VERBATIM)
                add_custom_target(pot_${pot} ALL DEPENDS ${pot}.po)
            endif()
    endforeach ()
endfunction ()

function (install_icon)
    set(icon_list ${ARGN})
    list(LENGTH icon_list SIZE)
    set(icon ${ARGV0})
    if( "${SIZE}" EQUAL 2 )
        install(FILES ${icon} DESTINATION ${ARGV1})
    else()
        if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${icon}")
            install(FILES ${icon} DESTINATION ${KDE1_ICONDIR}/${targetdir})
        endif()
        if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/mini-${icon}")
            install(FILES mini-${icon} DESTINATION ${KDE1_MINIDIR}/${targetdir} RENAME ${icon})
        endif()
        if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/large-${icon}")
            install(FILES large-${icon} DESTINATION ${KDE1_ICONDIR}/${targetdir}/large/ RENAME ${icon})
        endif()
    endif()
endfunction ()
