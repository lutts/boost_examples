cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project("Boost Examples")

enable_testing()
add_definitions(-std=c++11 -g)

#if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
#    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#    set(warnings "-Wall -Wextra -Werror")
#elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
#    set(warnings "/W4 /WX /EHsc")
#endif()
if (NOT CONFIGURED_ONCE)
    set(CMAKE_CXX_FLAGS "${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
    set(CMAKE_C_FLAGS   "${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(Boost REQUIRED
  locale
  system
  thread
  log-mt
  log_setup
  unit_test_framework)

include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

add_definitions(-DBOOST_LOG_DYN_LINK)

SET(BoostCommonLibs ${Boost_LIBRARIES} pthread)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL
  "A flag showing that CMake has configured at least once.")

add_subdirectory(ptr_container)
add_subdirectory(log)
