cmake_minimum_required(VERSION 3.10)

project(oving4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
pkg_check_modules(GLIBMM REQUIRED glibmm-2.4)

include_directories(
  ${GTKMM_INCLUDE_DIRS}
  ${GLIBMM_INCLUDE_DIRS}
)

link_directories(
  ${GTKMM_LIBRARY_DIRS}
  ${GLIBMM_LIBRARY_DIRS}
)

add_definitions(
  ${GTKMM_CFLAGS_OTHER}
  ${GLIBMM_CFLAGS_OTHER}
)

add_executable(oving4 main.cpp)

target_link_libraries(oving4
  ${GTKMM_LIBRARIES}
  ${GLIBMM_LIBRARIES}
)
