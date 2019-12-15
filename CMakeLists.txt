project(ECT_TADLAS)
set (Demo_VERSION_MAJOR 1)
set (Demo_VERSION_MINOR 0)

set( CMAKE_PREFIX_PATH D:/Programs/Qt5.14.0/5.14.0/mingw73_64/lib/cmake )
# SET( EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/release/)
# SET( LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/release/)
set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})


add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/cbb)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/client)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/server/algorithm)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/server/measuresys)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/server/net)

# 构建一个 CPack 安装包
include (InstallRequiredSystemLibraries)
if(WIN32 OR MINGW)
  list(APPEND CPACK_GENERATOR "NSIS")
  set(CPACK_NSIS_PACKAGE_NAME ${PROJECT_NAME})
  set(CPACK_NSIS_CONTACT "robertdr")
  set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
endif()
set (CPACK_PACKAGE_VERSION_MAJOR "${Demo_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Demo_VERSION_MINOR}")
include (CPack)