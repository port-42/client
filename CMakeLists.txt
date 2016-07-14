cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(Client)

# Instruct CMake to look for brewed qt5 files on OSX
if (${APPLE})
  set(CMAKE_PREFIX_PATH /usr/local/opt/qt5)
endif(${APPLE})

#COMPILE WITH C++ 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Instruct CMake to run uic automatically when needed.
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
set(CLIENT_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/apicommunicator.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/apicommunicator.h
  ${CMAKE_CURRENT_SOURCE_DIR}/connectwidget.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/connectwidget.h
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.h
  ${CMAKE_CURRENT_SOURCE_DIR}/requests.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/requests.h
  ${CMAKE_CURRENT_SOURCE_DIR}/summarywidget.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/summarywidget.h
)

add_executable(client ${CLIENT_SRC})
target_link_libraries(client Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network)

# GENERATION OF THE INSTALLERS FOR DEBIAN
INSTALL(TARGETS client DESTINATION port)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Samir AHAMADA") #required

INCLUDE(CPack)
