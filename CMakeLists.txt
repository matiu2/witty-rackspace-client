cmake_minimum_required( VERSION 2.8 )

project (witty-rackspace)

add_definitions(-std=c++11)

# Boost libraries
find_package( Boost COMPONENTS system signals program_options filesystem unit_test_framework )
include_directories(${Boost_INCLUDE_DIRS})
SET( BOOST_LIBS ${Boost_PROGRAM_OPTIONS_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SIGNALS_LIBRARY} ${Boost_SYSTEM_LIBRARY} )

include_directories(${Boost_INCLUDE_DIRS})

# Load the wt libraries, search for debug ones if appropriate
find_library( WT NAMES wtd wt )
find_library( WT_HTTP NAMES wthttpd wthttp )

add_library(wtrs src/main.cpp)
TARGET_LINK_LIBRARIES(wtrs ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${WT} ${WT_HTTP})

file(COPY doc-root DESTINATION .)
file(COPY app-root DESTINATION .)

enable_testing()
