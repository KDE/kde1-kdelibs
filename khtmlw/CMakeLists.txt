include_directories(
    ${QT_INCLUDE_DIR}
    ${KDELIBS_SOURCE_DIR}/kdecore
    ${KDELIBS_SOURCE_DIR}/kdeui
    ${KDELIBS_SOURCE_DIR}/jscript
    ${KDELIBS_SOURCE_DIR}/kimgio
    )

set(KHTMLW_SRCS
    jscript.cpp html.cpp htmlobj.cpp htmlfont.cpp htmlform.cpp htmltoken.cpp
    htmlframe.cpp htmlview.cpp htmlclue.cpp debug.cpp htmldata.cpp htmltable.cpp
    htmliter.cpp htmlchain.cpp
    )

set(KHTMLW_MOC
    html.h htmlform.h htmlframe.h
	htmlobj.h htmlview.h
    )

QT1_WRAP_HEADER(MOC_FILES ${KHTMLW_MOC})

add_library(khtmlw SHARED ${KHTMLW_SRCS} ${MOC_FILES})
set_target_properties(khtmlw PROPERTIES VERSION 2.0.0 SOVERSION 2)
target_link_libraries(khtmlw kdecore kdeui jscript kimgio ${QT_LIBRARIES} ${X11_LIBRARIES})
install(TARGETS khtmlw LIBRARY DESTINATION ${KDE1_LIBRARIES})

install(FILES jscript.h html.h htmlobj.h htmlfont.h htmlform.h
    htmltoken.h htmlframe.h htmlview.h htmlclue.h htmldata.h
    htmltable.h htmliter.h
    DESTINATION ${KDE1_INCLUDES})

install(FILES khtmlw_dnd.xpm DESTINATION ${KDE1_DATADIR}/khtmlw/pics )
