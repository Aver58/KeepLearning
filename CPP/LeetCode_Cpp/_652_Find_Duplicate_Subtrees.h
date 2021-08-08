/*
Given the root of a binary tree, return all duplicate subtrees.
For each kind of duplicate subtrees, you only need to return the root node of any one of them.
Two trees are duplicate if they have the same structure with the same node values.

Example 1:
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

Example 2:
Input: root = [2,1,1]
Output: [[1]]

Example 3:
Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]
*/

#include "Global.h"
#include <string>

class _652_Find_Duplicate_Subtrees
{ 
public:
	void Test() {
		TreeNode* head = new TreeNode(3);
		TreeNode* head1 = new TreeNode(1);
		TreeNode* head2 = new TreeNode(4);
		TreeNode* head3 = new TreeNode(3);
		TreeNode* head4 = new TreeNode(2);
		head->left = head1;
		head->right = head2;
		head1->left = head3;
		head1->right = head4;
		findDuplicateSubtrees(head);
	}

	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		unordered_map<string, int> strMap;
		vector<TreeNode*> result;
		findSubtrees(root, strMap, result);
		return result;
	}

    // 序列化字符串，做map
	string findSubtrees(TreeNode* root, unordered_map<string, int>& strMap, vector<TreeNode*>& result) {
		if (root == nullptr)
			return "#";

		string L = findSubtrees(root->left, strMap, result);
		string R = findSubtrees(root->right, strMap, result);
		//后序位置，综合得结果
		string code = to_string(root->val) + "," + L + "," + R;
		if (strMap[code] == 1)
			result.push_back(root);
		strMap[code]++;

		return code;
    }
};