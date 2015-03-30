cmake_minimum_required( VERSION 2.8 )

project (witty-rackspace)

add_definitions(-std=c++11)

# Boost libraries
find_package( Boost COMPONENTS system signals program_options filesystem unit_test_framework )
include_directories(${Boost_INCLUDE_DIRS})
SET( BOOST_LIBS ${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SIGNALS_LIBRARY} ${Boost_SYSTEM_LIBRARY} )

include_directories(${Boost_INCLUDE_DIRS})

# Load the wt libraries, search for debug ones if appropriate
if ( ${DEBUG} )
    find_library( WT NAMES wtd wt )
    find_library( WT_HTTP NAMES wthttpd wthttp )
    find_library( WT_TEST NAMES wttestd wttest )
else()
    find_library( WT NAMES wt )
    find_library( WT_HTTP NAMES wthttp )
    find_library( WT_TEST NAMES wttest )
endif()

add_library(test_base empty.cpp)
TARGET_LINK_LIBRARIES(test_base ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${WT_TEST} ${SQLITE_LIBS})

file(COPY doc-root DESTINATION .)
file(COPY app-root DESTINATION .)

enable_testing()
