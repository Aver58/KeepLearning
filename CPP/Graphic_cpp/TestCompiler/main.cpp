#include "test.h"
#include<Eigen/Core>
#include<opencv.hpp>

int main(){
    testA t(1);
     // Example of vector
    std::cout << "Example of vector \n";
    // vector definition
    Eigen::Vector3f v(1.0f,2.0f,3.0f);
    Eigen::Vector3f w(1.0f,0.0f,0.0f);
    // vector output
    std::cout << "Example of output \n";
    std::cout << v << std::endl;
    // vector add
    std::cout << "Example of add \n";
    std::cout << v + w << std::endl;

    // cv::im
/*
GCC编译工作一般分为四个步骤：
（1）预处理（Preprocessing）。由预处理器cpp完成，将.cpp源文件预处理为.i文件。
g++  -E  test.cpp  -o  test.i    //生成预处理后的.i文件
（2）编译（Compilation）。将.i文件编译为.s的汇编文件。
g++ -S test.i -o test.s         //生成汇编.s文件
（3）汇编（Assembly）。由汇编器as完成，将.s文件汇编成.o的二进制目标文件。
g++  -c  test.s  -o  test.o    //生成二进制.o文件
（4）链接（Linking）。由链接器ld，将.o文件连接生成可执行程序。
g++ test.o  -o  test.out      //生成二进制.out可执行文件 

编译多个文件 要么直接把文件附加到g++.exe命令后面，
要么用cmake工具
可以把cmake集成到vscode使用https://oldpan.me/archives/use-vscode-cmake-tools-build-project
*/  
    return 0;
}