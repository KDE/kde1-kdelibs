include_directories(
    ${QT_INCLUDE_DIR}
    )

set(KDECORE_SRCS
        kconfig.cpp
        kconfigbase.cpp
        ksimpleconfig.cpp
        kcolorgroup.cpp
        kapp.cpp
        kurl.cpp
        ksock.cpp
        drag.cpp
        kprocess.cpp
        kprocctrl.cpp
        klocale.cpp
        libintl.cpp
        fakes.cpp
        kiconloader.cpp
        kdebug.cpp
        kstdaccel.cpp
        kwm.cpp
        krootprop.cpp
        kcharsets.cpp
        kcharsetsdata.cpp
        kchartables.cpp
        kstring.cpp
        kpixmap.cpp
        dither.cpp
        kckey.cpp
        kaccel.cpp
        kglobalaccel.cpp
        kclipboard.cpp
        krect.cpp
        ksize.cpp
        kpoint.cpp
    )

set(KDECORE_MOC
    drag.h
    kapp.h
    kclipboard.h
    kconfig.h
    kconfigbase.h
    kdebugdialog.h
    kglobalaccel.h
    kiconloader.h
    kprocctrl.h
    kprocess.h
    ksimpleconfig.h
    ksock.h
   )

QT1_WRAP_HEADER(MOC_FILES ${KDECORE_MOC})

add_library(kdecore SHARED ${KDECORE_SRCS} ${MOC_FILES})
set_target_properties(kdecore PROPERTIES VERSION 2.0.0 SOVERSION 2)
target_link_libraries(kdecore ${QT_LIBRARIES} ${X11_LIBRARIES})
install(TARGETS kdecore LIBRARY DESTINATION ${KDE1_LIBRARIES})

install(FILES charsets.config DESTINATION ${KDE1_CONFDIR} RENAME "charsets")

install(FILES kdebug.areas DESTINATION "${KDE1_CONFDIR}")

install(FILES
	kconfig.h kconfigdata.h ksimpleconfig.h kconfigbase.h
    kcolorgroup.h kapp.h kcharsets.h
    kurl.h ksock.h drag.h  ckey.h kmisc.h
    kprocess.h kprocctrl.h klocale.h kiconloader.h kdebug.h
    kstdaccel.h kwm.h krootprop.h kstring.h kpixmap.h dither.h
    kaccel.h kglobalaccel.h kckey.h kclipboard.h krect.h ksize.h
    kpoint.h
	DESTINATION ${KDE1_INCLUDES})
