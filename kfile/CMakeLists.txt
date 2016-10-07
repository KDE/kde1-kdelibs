include_directories(
    ${QT_INCLUDE_DIR}
    ${KDELIBS_SOURCE_DIR}/kdecore
    ${KDELIBS_SOURCE_DIR}/kdeui
    ${KDELIBS_SOURCE_DIR}/kfmlib
    )

set(KFILE_SRCS
    kfilebookmark.cpp kfiledialogconf.cpp kcombiview.cpp
	kdir.cpp kfileinfo.cpp kremotefile.cpp kdirlistbox.cpp
	kfiledetaillist.cpp kfiledialog.cpp booktoken.cpp
	kfileinfocontents.cpp kfilesimpleview.cpp kpreview.cpp
	kfilepreview.cpp xview.cpp kfilefilter.cpp
    )

set(KFILE_MOC
    kcombiview.h kdir.h kdirlistbox.h
	kfilebookmark.h kfiledetaillist.h kfiledialog.h
	kfiledialogconf.h kfilefilter.h kfileinfocontents.h
	kfilepreview.h kfilesimpleview.h kpreview.h
    )

QT1_WRAP_HEADER(MOC_FILES ${KFILE_MOC})

add_library(kfile SHARED ${KFILE_SRCS} ${MOC_FILES})
set_target_properties(kfile PROPERTIES VERSION 1.1.2 SOVERSION 1)
target_link_libraries(kfile kdecore kdeui kfm ${QT_LIBRARIES} ${X11_LIBRARIES})
install(TARGETS kfile LIBRARY DESTINATION ${KDE1_LIBRARIES})
