/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Follow up:?Can you solve it with time complexity O(height of tree)?

?

Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []
?

Constraints:

The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-node-in-a-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#pragma once
#include "Global.h"

class _450_Delete_Node_in_a_BST
{
public:
	static void Test() {
	}

	// 删除节点就比较复杂
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (key == root->val)
		{
			// 1.没有子节点，直接删除；2.只有一个子节点，直接子节点替换自己；
			if (root->left == nullptr) return root->right;
			if (root->right == nullptr) return root->left;
			// 3.有两个子节点，要找到左子树最大值或者右子树最小值替代自己
			TreeNode* miniNode = root->right;
			while (miniNode->left)
				miniNode = miniNode->left;
			miniNode->right = deleteNode(root->right,key);
			miniNode->left = root->left;
		}
		else if(key < root->val)
			root->left = deleteNode(root->left,key);
		else
			root->right = deleteNode(root->right,key);
    }
};

