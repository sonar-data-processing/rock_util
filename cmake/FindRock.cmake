
if ( NOT DEFINED ENV{AUTOPROJ_CURRENT_ROOT} )
    MESSAGE ( SEND_ERROR "Rock-robotics directory not found." )
else()
    set ( ROCK_ROBOTICS_DIR $ENV{AUTOPROJ_CURRENT_ROOT} CACHE INTERNAL "Rock Robotics Directory" )
    set ( ROCK_ROBOTICS_LIBRARY_DIR "${ROCK_ROBOTICS_DIR}/install/lib/x86_64-linux-gnu" "${ROCK_ROBOTICS_DIR}/install/lib" CACHE INTERNAL "Rock Robotics Library Directory")
    set ( ROCK_ROBOTICS_INCLUDE_DIR "${ROCK_ROBOTICS_DIR}/install/include" CACHE INTERNAL "Rock Robotics Include Directory")

    message ( STATUS "Rock-robotics root directory:" )
    message ( STATUS "  ${ROCK_ROBOTICS_DIR}" )
    message ( STATUS "Rock-robotics include directory: " )
    message ( STATUS "  ${ROCK_ROBOTICS_INCLUDE_DIR}" )
    message ( STATUS "Rock-robotics library directories:" )

    foreach ( DIR ${ROCK_ROBOTICS_LIBRARY_DIR} )
        message ( STATUS "  ${DIR}" )
    endforeach()
endif()
