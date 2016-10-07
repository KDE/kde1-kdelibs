include_directories(
    ${QT_INCLUDE_DIR}
    )

set(JSCRIPT_SRCS t1.c t2.c cpp2bison.cpp jstree.cpp jsexec.cpp builtin.cpp)

add_library(jscript SHARED ${JSCRIPT_SRCS})
set_target_properties(jscript PROPERTIES VERSION 2.0.0 SOVERSION 2)
target_link_libraries(jscript ${QT_LIBRARIES})

install(TARGETS jscript LIBRARY DESTINATION ${KDE1_LIBRARIES})

install(FILES bison2cpp.h jstree.h jsexec.h jserror.h builtin.h DESTINATION ${KDE1_INCLUDES})
