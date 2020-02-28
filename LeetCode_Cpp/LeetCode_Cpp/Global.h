#pragma once

using namespace std;
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include <math.h>
#include <unordered_map>
#include <iostream>
#include <map>  
#include <algorithm>  
#include <cstring>

//* Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
