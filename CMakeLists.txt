project(ECT_TADLAS)
set( CMAKE_PREFIX_PATH /home/zwq/Qt5.13.0/5.13.0/gcc_64/lib/cmake/ )

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/cbb)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/client)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/server/algorithm)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/server/measuresys)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/server/net)