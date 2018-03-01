cmake_minimum_required(VERSION 2.8.11)

project(main-GUI)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH /opt/Qt/5.10.1/gcc_64/lib/cmake)

# Find the QtWidgets library
find_package(Qt5Widgets)

qt5_wrap_cpp( MOC mainwindow.h)
qt5_wrap_ui( UIC mainwindow.ui)

# Tell CMake to create the helloworld executable
add_executable(helloworld WIN32 main.cpp mainwindow.cpp mainwindow.h mainwindow.ui ${RESOURCE_DIR})

# Use the Widgets module from Qt 5.
target_link_libraries(helloworld Qt5::Widgets)
