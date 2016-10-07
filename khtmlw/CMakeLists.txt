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
set_target_properties(khtmlw PROPERTIES VERSION 1.1.2 SOVERSION 1)
target_link_libraries(khtmlw kdecore kdeui jscript kimgio ${QT_LIBRARIES} ${X11_LIBRARIES})
