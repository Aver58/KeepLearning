#pragma once

using namespace std;
#include<vector>
#include<queue>
#include<list>
#include <math.h>
//#include <unordered_map>
#include <iostream>

class Global
{
public:
	Global();
	~Global();
};

//* Definition for singly-linked list.

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};