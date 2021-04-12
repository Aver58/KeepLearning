cmake_minimum_required (VERSION 2.8.11)
project (TestProject)

# find_package(Eigen3 REQUIRED)
# include_directories(EIGEN3_INCLUDE_DIR)

add_executable (TestProject main.cpp test.cpp test.h)
