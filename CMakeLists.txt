cmake_minimum_required(VERSION 2.8)
project(Snake)

set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH})

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY                "${CMAKE_BINARY_DIR}/../bin" )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG          "${CMAKE_BINARY_DIR}/../bin/debug" )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE        "${CMAKE_BINARY_DIR}/../bin/release" )


if(CMAKE_VERSION VERSION_LESS "3.3") 
  message(WARNING "CMake version less than 3.3\n"
    "using local FindMatlab module extracted from v3.3")
  # Where we keep FindMatlab module
  set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    ${PROJECT_SOURCE_DIR}/cmake-compat)
endif()

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
if(NOT OPENGL_FOUND)
  message(FATAL_ERROR "OPENGL not found.")
else()
  message("OPENGL found.")
endif()
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
#find_package(GTK REQUIRED)
if (NOT GTK3_FOUND)
	message(FATAL_ERROR "GTK not found.")
else()
	message("GTK found.")
    include_directories( ${GTK3_INCLUDE_DIRS}  )
endif (GTK3_FOUND)


include_directories(
  "/usr/include/"
  "/usr/include/gtk-3.0"
  "/usr/include/glib-2.0"
  "/usr/lib/x86_64-linux-gnu/glib-2.0/include/"
  "/usr/include/pango-1.0/"
  "/usr/include/cairo/"
  "/usr/include/gdk-pixbuf-2.0/"
  "/usr/include/atk-1.0"
  )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O3 -march=native -openmp -lgtk-3 -lgdk-3")

add_subdirectory("src")
