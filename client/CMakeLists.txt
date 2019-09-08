set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project( ETClient )
cmake_minimum_required( VERSION 3.1 )
set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_AUTOMOC ON )
set( CMAKE_BUILD_TYPE Release )
set( CMAKE_PREFIX_PATH /home/zwq/Qt5.13.0/5.13.0/gcc_64/lib/cmake/ )
add_definitions ( -Wall )
find_package ( Qt5Widgets REQUIRED )
find_package ( Qt5Core REQUIRED )
find_package ( Qt5Gui REQUIRED )

include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5Gui_INCLUDE_DIRS})


include_directories(${CMAKE_SOURCE_DIR}/../)

link_directories(${CMAKE_SOURCE_DIR}/../cbb/release/lib)
link_libraries(cbbmodesys)

set ( untitled1_SRCS
	main.cpp
	mypaintusb.cpp
	mainwindow.cpp
	tdlasdialog.cpp
	myshowwidget.cpp
	glwidget.cpp
	)

set ( untitled1_UIS
	mainwindow.ui
	tdlasdialog.ui
	)
QT5_WRAP_UI(UIS ${untitled1_UIS})

set ( untitled1_RSCS
	rsc.qrc
	)
QT5_ADD_RESOURCES(RSCS ${untitled1_RSCS})

set ( untitled1_MOCS
	mainwindow.h
	tdlasdialog.h
	mypaintusb.h
	myshowwidget.h
	glwidget.h
	)
QT5_WRAP_CPP(MOCS ${untitled1_MOCS})

add_executable ( ETClient ${untitled1_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
target_link_libraries ( ETClient  Qt5::Core Qt5::Gui Qt5::Widgets  )
