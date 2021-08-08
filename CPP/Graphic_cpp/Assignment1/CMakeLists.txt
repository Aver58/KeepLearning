cmake_minimum_required(VERSION 3.10)
project(Rasterizer)

set(CMAKE_CXX_STANDARD 17)

# set EIGEN_DIR variable to Eigen Library Path
set(EIGEN_DIR "C:/src/vcpkg/installed/x64-windows/include/eigen3")
set(OpenCV_DIR "C:/src/vcpkg/installed/x64-windows/include/opencv2")
include_directories(${EIGEN_DIR})
include_directories(${OpenCV_DIR})

add_executable(Rasterizer main.cpp rasterizer.hpp rasterizer.cpp Triangle.hpp Triangle.cpp)
# target_link_libraries(Rasterizer ${EIGEN_DIR})
target_link_libraries(Rasterizer ${OpenCV_DIR})
