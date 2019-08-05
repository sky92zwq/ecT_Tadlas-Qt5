find_package(Qt5Core REQUIRED)
find_package(Qt5Widget REQUIRED)

set(SOURCES
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

set(MOC_SRCS 
    mainwindow.h    
)

qt_wrap_cpp(MOCS ${MOC_SRCS})


include_directory(.)
add_executable(qtECT_TDLAS ${SOURCES} )
target_link_libraries(qtECT_TDLAS ftd2xx)