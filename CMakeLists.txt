cmake_minimum_required( VERSION "2.8.0" )
set( MAIN_EXECUTABLE sonicd )

project( ${MAIN_EXECUTABLE} CXX C )


# Path to additional CMake modules
SET( CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake ${CMAKE_MODULE_PATH} )


find_package( FCGI REQUIRED )
set( LIBS
    ${FCGI_LIBRARY}
)

set( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build )
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build )

include_directories( include )
include_directories( ${FCGI_INCLUDE_DIR} )

set( SONIC_LIBRARY_SOURCES
    src/server/SonicService.cc
)

add_library( sonic_static STATIC ${SONIC_LIBRARY_SOURCES} )
target_link_libraries( sonic_static ${LIBS} )

add_executable( ${MAIN_EXECUTABLE} src/main.cc )
target_link_libraries( ${MAIN_EXECUTABLE} sonic_static )


if( CMAKE_COMPILER_IS_GNUCXX )
    message( STATUS "GCC detected, adding compile flags" )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3 -std=gnu++0x -g -pg" )
    #set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3 -std=gnu++0x" )
endif( CMAKE_COMPILER_IS_GNUCXX )

