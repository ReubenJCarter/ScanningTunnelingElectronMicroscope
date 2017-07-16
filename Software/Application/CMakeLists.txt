cmake_minimum_required(VERSION 2.6)
project(STMApp)
set(PROJECT_BRIEF "STM App")

set(CMAKE_AUTOMOC ON)

set(CMAKE_BUILD_TYPE RELEASE)
set(GCC_COMPILE_FLAGS "-std=c++11 -Wall -O3 -g -static")
set(GCC_LINK_FLAGS "")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_LINK_FLAGS}")


#qt
find_package(Qt5 COMPONENTS Core Widgets Gui OpenGL)
set(QT_INC_DIR "C:/Qt/5.9.1/msvc2015_64/include")
set(QT_LIB_DIR "C:/Qt/5.9.1/msvc2015_64/lib")
set(QT_BIN_DIR  "C:/Qt/5.9.1/msvc2015_64/bin")
include_directories(${QT_INC_DIR})
include_directories(${QT_INC_DIR}/QtCore)
include_directories(${QT_INC_DIR}/QtGui)
link_directories(${QT_LIB_DIR})


add_subdirectory(app)
