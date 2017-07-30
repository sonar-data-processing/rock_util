cmake_minimum_required (VERSION 2.6)
project (rock_util)

list(APPEND CMAKE_MODULE_PATH $ENV{SONAR_TOOLKIT_PREFIX}/base/cmake)
list(APPEND CMAKE_MODULE_PATH ${rock_util_SOURCE_DIR}/cmake)

include ( FindPkgConfig )
include ( BoostTest )
include ( FindRock )

find_package ( Boost COMPONENTS system unit_test_framework REQUIRED )
find_package ( Eigen3 REQUIRED )
find_package ( OpenCV REQUIRED )

pkg_check_modules(pocolog_cpp pocolog_cpp)

include_directories (
    ${ROCK_ROBOTICS_INCLUDE_DIR}
    ${EIGEN3_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/src
    ${CMAKE_INSTALL_PREFIX}/include/sonar_toolkit
)

file ( GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp )
file ( GLOB HEADERS ${PROJECT_SOURCE_DIR}/src/*.hpp )

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
    ${CMAKE_INSTALL_PREFIX}/lib/sonar_toolkit
)

install(
    FILES ${HEADERS}
    DESTINATION include/sonar_toolkit/${PROJECT_NAME}
)

install(
    TARGETS rock_util
    DESTINATION lib/sonar_toolkit
)

## Unit Tests ##
boost_test_init()

add_boost_test (
    test_rock_util
    SOURCES test/test_rock_util.cpp
    LIBRARIES rock_util sonar_util ${Boost_LIBRARIES} ${OpenCV_LIBS} ${pocolog_cpp_LIBRARIES}
)

install(
    FILES cmake/FindRock.cmake
    DESTINATION share/sonar_toolkit/${PROJECT_NAME}/cmake
)
