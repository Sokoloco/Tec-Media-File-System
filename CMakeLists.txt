cmake_minimum_required(VERSION 3.8)
project(TEC_Media_File)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ImageProcessing/Processing.cpp ImageProcessing/Processing.h)
find_package( OpenCV REQUIRED )
add_executable(TEC_Media_File ${SOURCE_FILES})
target_link_libraries( TEC_Media_File ${OpenCV_LIBS} )