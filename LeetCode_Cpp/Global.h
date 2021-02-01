#pragma once

using namespace std;
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <map>  
#include <algorithm>  
#include <cstring>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

//print it
void Dump(int *p, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << p[i] << " ";
	}
}

template <class T>
int GetArrayLen(T& array)
{
	return (sizeof(array) / sizeof(array[0]));
}

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

// 输入 n，打印 n 个 tab 缩进
void printIndent(int n) {
	for (int i = 0; i < n; i++) {
		printf("   ");
	}
}
//在递归函数的开头，调用 printIndent(count++) 并打印关键变量；
//然后在所有 return 语句之前调用 printIndent(--count) 并打印返回值。