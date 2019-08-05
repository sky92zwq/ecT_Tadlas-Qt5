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

include_directory(.)
add_executable(qtECT_TDLAS ${SOURCES} )