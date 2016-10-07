include_directories(
    ${QT_INCLUDE_DIR}
    ${KDELIBS_SOURCE_DIR}/kdecore
    ${KDELIBS_SOURCE_DIR}/kfile
    )

set(KDEUI_SRCS
        kledlamp.cpp kprogress.cpp kpanner.cpp kcolordlg.cpp
		kselect.cpp kdatepik.cpp kdatetbl.cpp
		kfontdialog.cpp kmsgbox.cpp kpopmenu.cpp ktabctl.cpp
		ktreelist.cpp kstatusbar.cpp ktopwidget.cpp ktmainwindow.cpp
		kmenubar.cpp ktoolbar.cpp kbutton.cpp kslider.cpp
		kseparator.cpp klined.cpp kcombo.cpp krestrictedline.cpp
		kintegerline.cpp kspinbox.cpp kcontrol.cpp
		kcolorbtn.cpp kiconloaderdialog.cpp kwmmapp.cpp
		kbuttonbox.cpp ktablistbox.cpp knewpanner.cpp
		keditcl1.cpp keditcl2.cpp ktoolboxmgr.cpp kled.cpp
		kdbtn.cpp knotebook.cpp ktabbar.cpp kwizard.cpp kcontainer.cpp
		kkeydialog.cpp kurllabel.cpp kruler.cpp kquickhelp.cpp kcursor.cpp)

set(KDEUI_MOC
    kbutton.h kbuttonbox.h kcolorbtn.h
	kcolordlg.h kcombo.h kcontainer.h kcontrol.h kdatepik.h
	kdatetbl.h kdbtn.h keditcl.h kfontdialog.h
	kiconloaderdialog.h kintegerline.h kkeydialog.h kled.h
	kledlamp.h klined.h kmenubar.h kmsgbox.h knewpanner.h
	knotebook.h kpanner.h kpopmenu.h kprogress.h
	kquickhelp.h krestrictedline.h kruler.h kselect.h
	kslider.h kspinbox.h kstatusbar.h ktabbar.h ktabctl.h
	ktablistbox.h ktmainwindow.h ktoolbar.h ktoolboxmgr.h
	ktopwidget.h ktreelist.h kurllabel.h kwizard.h kwmmapp.h)

QT1_WRAP_HEADER(MOC_FILES ${KDEUI_MOC})

add_library(kdeui SHARED ${KDEUI_SRCS} ${MOC_FILES})
set_target_properties(kdeui PROPERTIES VERSION 2.0.0 SOVERSION 2)
target_link_libraries(kdeui kdecore ${QT_LIBRARIES} ${X11_LIBRARIES})
install(TARGETS kdeui LIBRARY DESTINATION ${KDE1_LIBRARIES})

install(FILES
        kledlamp.h kprogress.h kpanner.h kcolordlg.h kselect.h
		kdatepik.h kdatetbl.h
		kfontdialog.h kmsgbox.h kpopmenu.h ktabctl.h
		ktreelist.h kstatusbar.h ktopwidget.h ktmainwindow.h
		ktoolbar.h kmenubar.h kbutton.h kslider.h kseparator.h
		klined.h kcombo.h krestrictedline.h kintegerline.h
		kspinbox.h kcolorbtn.h kiconloaderdialog.h
		kwmmapp.h kbuttonbox.h ktablistbox.h kcontainer.h
		knewpanner.h kcontrol.h keditcl.h ktoolboxmgr.h kled.h
		kdbtn.h knotebook.h ktabbar.h kwizard.h kkeydialog.h
		kurllabel.h kruler.h kquickhelp.h kcursor.h
        DESTINATION ${KDE1_INCLUDES})

install(FILES
    error.xpm exclamation.xpm info.xpm stopsign.xpm question.xpm
    arrow_up.xbm arrow_down.xbm arrow_left.xbm arrow_right.xbm
    DESTINATION ${KDE1_DATADIR}/kde/pics)
