cmake_minimum_required(VERSION 3.8)
project(Tec_Media_File_System)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ImageProcessing/Processing.cpp ImageProcessing/Processing.h Server/ControllerNode.cpp Cliente/cliente.cpp Cliente/cliente.h TECMFS-DISK/TECMFS-DISK-main.cpp ceRobot/ceRobot-main.cpp)
find_package( OpenCV REQUIRED )
add_executable(Tec_Media_File_System ${SOURCE_FILES} Server/ControllerNode.cpp Cliente/cliente.cpp Cliente/cliente.h TECMFS-DISK/TECMFS-DISK-main.cpp ceRobot/ceRobot-main.cpp)
target_link_libraries( Tec_Media_File_System ${OpenCV_LIBS} )
