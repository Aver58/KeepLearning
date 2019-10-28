#pragma once

using namespace std;
#include<vector>
#include<list>
#include <iostream>

class Global
{
public:
	Global();
	~Global();
};

//* Definition for singly-linked list.

extern struct ListNode {
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