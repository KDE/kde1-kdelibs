include_directories(
    ${QT_INCLUDE_DIR}
    ${KDELIBS_SOURCE_DIR}/kdecore
    )

set(MEDIATOOL_SRCS
    chunk.c eventcounter.c connect.c filename.c playlist.c kaudio.cpp
    )

set(MEDIATOOL_MOC
    kaudio.h
    )

QT1_WRAP_HEADER(MOC_FILES ${MEDIATOOL_MOC})

add_library(mediatool SHARED ${MEDIATOOL_SRCS} ${MOC_FILES})
set_target_properties(mediatool PROPERTIES VERSION 1.1.2 SOVERSION 1)
target_link_libraries(mediatool kdecore ${QT_LIBRARIES} ${X11_LIBRARIES})
install(TARGETS mediatool LIBRARY DESTINATION ${KDE1_LIBRARIES})
