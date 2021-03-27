// ToOffer_Cpp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "_07_ConstructBinaryTree.h"
#include "_12_StringPathInMatrix.h"
#include "_14_CuttingRope.h"
#include "_15_NumberOf1InBinary.h"
#include "_16_Power.h"
#include "_17_Print1ToMaxOfNDigits.h"
#include "_19_RegularExpressionsMatching.h"
#include "_22_KthNodeFromEnd.h"
#include "_32_PrintTree.h"
#include "Sort\BubbleSort.h"
#include <ctime>

#include <iostream>
using namespace std;

void TestTime() {
   // 基于当前系统的当前日期/时间
   time_t now = time(0);
   tm *ltm = localtime(&now);
 
   // 输出 tm 结构的各个组成部分
   cout << "年: "<< 1900 + ltm->tm_year << endl;
   cout << "月: "<< 1 + ltm->tm_mon<< endl;
   cout << "日: "<<  ltm->tm_mday << endl;
   cout << "时间: "<< ltm->tm_hour << ":";
   cout << ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;
}

struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book,book2;

void TestReference() {
    int i;
    double d;

    // 声明引用变量
    int& r = i;
    int r1 = i;
    double& s = d;

    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference : " << r << endl;
    cout << "Value of r1 reference : " << r1 << endl;
}

void TestGoto() {
    int a = 10;

    LOOP:do
    {
        if (a == 15)
        {
            // 跳过迭代
            a = a + 1;
            goto LOOP;
        }
        cout << "a 的值：" << a << endl;
        a = a + 1;
    } while (a < 20);
}

int main()
{
    std::cout << "Hello World! \n";
	// BubbleSort0();

    TestTime();

    std::cout << "Hello World! \n";
}