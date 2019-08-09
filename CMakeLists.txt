project( untitled1 )
cmake_minimum_required( VERSION 3.1 )
set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_AUTOMOC ON )
set( CMAKE_BUILD_TYPE Release )
add_definitions ( -Wall )
find_package ( Qt5Widgets REQUIRED )
find_package ( Qt5Core REQUIRED )
find_package ( Qt5Gui REQUIRED )
set ( untitled1_HDRS
	cs_ftfunction.h
	ftd2xx.h
	ectclass.h
	mode.h
	matlab/calderon_circle_12_electrodes_ssj.h
	matlab/calderon_circle_12_electrodes_ssj_types.h
	matlab/calderon_circle_16_electrodes_ssj.h
	matlab/calderon_circle_16_electrodes_ssj_types.h
	matlab/calderon_circle_32_electrodes_ssj.h
	matlab/calderon_circle_32_electrodes_ssj_types.h
	matlab/LBP_Circular_ECT_16.h
	matlab/LBP_Circular_ECT_16_types.h
	matlab/mat.h
	matlab/matrix.h
	matlab/rt_defines.h
	matlab/rt_nonfinite.h
	matlab/rtwtypes.h
	matlab/tmwtypes.h
	matlabdynamic/calderon_circle_16_electrodes_ssjwq.h
	matlabdynamic/calderon_circle_16_electrodes_ssjwq_types.h
	matlabdynamic/rt_defines.h
	matlabdynamic/rt_nonfinite.h
	matlabdynamic/rtwtypes.h
	tdlasclass.h
	rwhelper.h
	)

set ( untitled1_SRCS
	main.cpp
	cs_ftfunction.cpp
	ectclass.cpp
	mypaintusb.cpp
	mainwindow.cpp
	mythreads.cpp
	tdlasdialog.cpp
	myshowwidget.cpp
	glwidget.cpp
	matlabhelper.cpp
	mode.cpp
	tdlasclass.cpp
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
	mythreads.h
	mypaintusb.h
	myshowwidget.h
	glwidget.h
	matlabhelper.h
	)
QT5_WRAP_CPP(MOCS ${untitled1_MOCS})

add_executable ( untitled1 ${untitled1_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
target_link_libraries ( untitled1  Qt5::Core Qt5::Gui Qt5::Widgets )
