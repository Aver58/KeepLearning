cmake_minimum_required (VERSION 2.8.11)
project (TestProject)

# find_package(Eigen3 REQUIRED)
# include_directories(EIGEN3_INCLUDE_DIR)

include_directories("C:/src/vcpkg/installed/x64-windows/include")

set(EIGEN_DIR "C:/src/vcpkg/installed/x64-windows/include/eigen3")
include_directories(${EIGEN_DIR})

set(OpenCV_DIR "C:/src/vcpkg/installed/x64-windows/include/opencv2")
include_directories(${OpenCV_DIR})

add_executable (TestProject main.cpp test.cpp test.h)
# target_link_libraries(TestProject ${EIGEN_DIR})
target_link_libraries(TestProject ${OpenCV_DIR})
