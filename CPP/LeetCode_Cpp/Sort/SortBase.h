#pragma once

//当数组作为形参调用函数时，需要连同数组长度一起传进来！
//数组在作为函数参数传递过程中，会退化成指针。这也是为什么指针作为参数传递时，经常要一个长度。

/// 交换数组两个值
void Swap(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}