cmake_minimum_required(VERSION 2.8)
project(ratyrace)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/builds)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/libs)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules")
option(DEBUG_BUILD "generate debug binaries" ON)

if(DEBUG_BUILD)
  add_definitions(-DDEBUG_BUILD)
  message("Debug Build")
endif()

#Headers
include_directories(include)

#Sources
#set(SOURCES src/plot.cpp src/plotdata.cpp src/subplot.cpp src/test_tmp.cpp)
AUX_SOURCE_DIRECTORy(src/ ALL_SOURCES)
# set(SOURCES ALL_SOURCES)

set(EXEC_NAME raytrace)

set(SFML_DIR "F:/libs/SFML-2.5.1/lib/cmake/SFML")
#add_library(${EXEC_NAME} SHARED ${SOURCES})

find_package(OpenCL REQUIRED)
if(OpenCL_FOUND)
  message(STATUS "OpenCL includes: ${OpenCL_INCLUDE_DIRS}")
  message(STATUS "OpenCL libraries: ${OpenCL_LIBRARIES}")
  include_directories(${OpenCL_INCLUDE_DIRS})
endif()


find_package(SFML 2.5 COMPONENTS graphics window system)
if(SFML_FOUND)
  add_executable(${EXEC_NAME} ${ALL_SOURCES})
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXEC_NAME} sfml-window sfml-graphics sfml-system ${OpenCL_LIBRARIES})
endif()