include_directories(
    ${QT_INCLUDE_DIR}
    ${PNG_INCLUDE_DIR}
    )

set(KIMGIO_SRCS jpeg.cpp xview.cpp kimgio.cpp eps.cpp tiffr.cpp pngr.cpp)

add_library(kimgio SHARED ${KIMGIO_SRCS})
set_target_properties(kimgio PROPERTIES VERSION 2.0.0 SOVERSION 2)
target_link_libraries(kimgio kdecore ${PNG_LIBRARY} ${JPEG_LIBRARY} ${TIFF_LIBRARY})
install(TARGETS kimgio LIBRARY DESTINATION ${KDE1_LIBRARIES})

install(FILES kimgio.h DESTINATION ${KDE1_INCLUDES})
