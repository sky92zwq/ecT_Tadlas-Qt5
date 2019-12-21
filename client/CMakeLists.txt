project(ECT_TDLAS_CLIENT)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
cmake_minimum_required( VERSION 3.1 )
set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_AUTOMOC ON )
set( CMAKE_BUILD_TYPE Release )
add_definitions ( -Wall )
find_package ( Qt5Widgets REQUIRED )
find_package ( Qt5Core REQUIRED )
find_package ( Qt5Gui REQUIRED )
find_package ( Qt5Network REQUIRED )

include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5Gui_INCLUDE_DIRS})
include_directories(${Qt5Network_INCLUDE_DIRS})


include_directories(${CMAKE_CURRENT_LIST_DIR}/../)

link_directories(${CMAKE_CURRENT_LIST_DIR}/../release/lib)


set ( ETClient_SRCS
	main.cpp
	mypaintPoints.cpp
	mainwindow.cpp
	tdlasdialog.cpp
	myshowwidget.cpp
	glwidget.cpp
	myTcpClient.cpp
	myClientCommand.cpp
	)

set ( ETClient_UIS
	mainwindow.ui
	tdlasdialog.ui
	)
QT5_WRAP_UI(UIS ${ETClient_UIS})

set ( ETClient_RSCS
	rsc.qrc
	)
QT5_ADD_RESOURCES(RSCS ${ETClient_RSCS})

set ( ETClient_MOCS
	mainwindow.h
	tdlasdialog.h
	mypaintPoints.h
	myshowwidget.h
	glwidget.h
	myTcpClient.h
	myClientCommand.h
	)
QT5_WRAP_CPP(MOCS ${ETClient_MOCS})
if(WIN32)
	add_executable ( ETClient WIN32 ${ETClient_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
elseif()
	add_executable ( ETClient ${ETClient_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
endif(WIN32)

target_link_libraries ( ETClient  Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network cbbmodesys )
# 指定安装路径
install (TARGETS ETClient DESTINATION bin)
# if(WIN32)
# 	include(DeployQt)
# 	windeployqt(ETClient)
# endif(WIN32)
