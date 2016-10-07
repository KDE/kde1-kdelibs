include_directories(
    ${QT_INCLUDE_DIR}
    ${KDELIBS_SOURCE_DIR}/kdecore
    )

set(KFM_SRCS kfm.cpp kfmclient_ipc.cpp kfmclient_ipc2.cpp kfmipc.cpp)

set(KFM_MOC kfm.h kfmclient_ipc.h)

QT1_WRAP_HEADER(MOC_FILES ${KFM_MOC})

add_library(kfm SHARED ${KFM_SRCS} ${MOC_FILES})
set_target_properties(kfm PROPERTIES VERSION 1.1.2 SOVERSION 1)
target_link_libraries(kfm kdecore ${QT_LIBRARIES})
