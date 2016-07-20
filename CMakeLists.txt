cmake_minimum_required (VERSION 2.6)
project (rock_util)

include ( "${WORKSPACE_DIR}/base/cmake/Dependencies.cmake"  )

add_project_dependency (base       ${WORKSPACE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
add_project_dependency (sonar_util ${WORKSPACE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

setup_headers ( ${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/src" )

set ( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake" )

include ( FindRock )
include ( FindPkgConfig )
include ( BoostTest )

find_package ( Boost COMPONENTS system unit_test_framework REQUIRED )
find_package ( Eigen3 REQUIRED )
find_package ( OpenCV REQUIRED )

pkg_check_modules(pocolog_cpp pocolog_cpp)

## Main Project ##
set (
    ${PROJECT_NAME}_INCLUDE_DIR
    ${PROJECT_SOURCE_DIR}/src
    ${CMAKE_BINARY_DIR}/include
    CACHE INTERNAL "Rock Util Include Directory"
    FORCE
)

include_directories (
    ${rock_util_INCLUDE_DIR}
    ${base_INCLUDE_DIR}
    ${sonar_util_INCLUDE_DIR}
    ${ROCK_ROBOTICS_INCLUDE_DIR}
    ${EIGEN3_INCLUDE_DIR}
)

file ( GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp )

add_library (
    rock_util STATIC
    ${SOURCES}
)

target_link_libraries (
    rock_util
    sonar_util
)

link_directories (
    ${ROCK_ROBOTICS_LIBRARY_DIR}
)

## Unit Tests ##
boost_test_init()

add_boost_test (
    test_rock_util
    SOURCES test/test_rock_util.cpp
    LIBRARIES rock_util sonar_util ${Boost_LIBRARIES} ${OpenCV_LIBS} ${pocolog_cpp_LIBRARIES}
)
