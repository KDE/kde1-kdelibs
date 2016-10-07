include_directories(
    ${QT_INCLUDE_DIR}
    ${KDELIBS_SOURCE_DIR}/kdecore
    ${KDELIBS_SOURCE_DIR}/kdeui
    ${KDELIBS_SOURCE_DIR}/kfmlib
    ${KDELIBS_SOURCE_DIR}/kfile
    )

set(KAB_SRCS
	kabapi.cc
	AssertDialog.cpp
	AssertDialogData.cpp
	DialogBase.cpp
	DialogBaseData.cpp
	PrintDialog.cpp
	PrintDialogData.cpp
	SearchDialog.cpp
	StringListEditWidget.cpp
	StringListEditWidgetData.cpp
	StringListEditDialog.cpp
	addressbook.cc
	businesscard.cc
	datepickerdialog.cc
	editentry.cc
	searchresults.cc
	widget.cc
	configDB.cc
	sections.cc
	keyvaluemap.cc
	functions.cc
	StringListSelectOneDialog.cpp
	StringListSelectOneDialogData.cpp
	StringListSelectSetDialog.cpp
	StringListSelectAndReorderSet.cpp
	StringListSelectAndReorderSetData.cpp
	widgets.cc
	SearchDialogMainWidget.cpp
	SearchDialogMainWidgetData.cpp
    )

set(KAB_MOC
    AssertDialog.h AssertDialogData.h DialogBase.h
	DialogBaseData.h PrintDialog.h PrintDialogData.h
	SearchDialog.h SearchDialogMainWidget.h
	SearchDialogMainWidgetData.h StringListEditDialog.h
	StringListEditWidget.h StringListEditWidgetData.h
	StringListSelectAndReorderSet.h
	StringListSelectAndReorderSetData.h
	StringListSelectOneDialog.h
	StringListSelectOneDialogData.h
	StringListSelectSetDialog.h
	businesscard.h datepickerdialog.h editentry.h
	kab.h kabapi.h searchresults.h
    )

QT1_WRAP_HEADER(MOC_FILES ${KAB_MOC})

add_library(kab SHARED ${KAB_SRCS} ${MOC_FILES})
set_target_properties(kab PROPERTIES VERSION 1.1.2 SOVERSION 1)
target_link_libraries(kab kdecore kdeui kfm kfile ${QT_LIBRARIES} ${X11_LIBRARIES})
