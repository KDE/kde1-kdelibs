include_directories(
    ${QT_INCLUDE_DIR}
    ${KDELIBS_SOURCE_DIR}/kdecore
    ${KDELIBS_SOURCE_DIR}/kdeui
    )

set(KSPELL_SRCS kspelldlg.cpp kspell.cpp ksconfig.cpp kprocio.cpp)
set(KSPELL_MOC kprocio.h ksconfig.h kspell.h kspelldlg.h)

QT1_WRAP_HEADER(MOC_FILES ${KSPELL_MOC})

add_library(kspell SHARED ${KSPELL_SRCS} ${MOC_FILES})
set_target_properties(kspell PROPERTIES VERSION 2.0.0 SOVERSION 2)
target_link_libraries(kspell kdecore kdeui ${QT_LIBRARIES} ${X11_LIBRARIES})
install(TARGETS kspell LIBRARY DESTINATION ${KDE1_LIBRARIES})

install(FILES kspell.h ksconfig.h kprocio.h kspelldlg.h DESTINATION ${KDE1_INCLUDES})
