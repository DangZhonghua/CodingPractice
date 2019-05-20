/*
https://leetcode-cn.com/problems/path-sum-iii/

http://www.cnblogs.com/grandyang/p/6007336.html
Path Sum III

You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
Example:
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

	  10
	 /  \
	5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;


struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*

use preOrder to traverse the tree.

*/


class Solution
{
public:
	int pathSum(TreeNode* root, int sum)
	{
		m_sum = sum;
		m_count = 0;
		mapValue2Count.clear();
		if (root)
		{
			mapValue2Count[0] = 1; // Initialize the base case.
			preOrderTraversal(root, 0);
		}
		return m_count;
	}
private:
	void preOrderTraversal(TreeNode* root, int nPathSum)
	{
		nPathSum += root->val;

		m_count += mapValue2Count.count[nPathSum - m_sum];

		mapValue2Count[nPathSum] += 1;

		if (root->left)
		{
			preOrderTraversal(root->left, nPathSum);
		}
		if (root->right)
		{
			preOrderTraversal(root->right, nPathSum);
		}
		mapValue2Count[nPathSum] -= 1;
	}
private:
	int m_sum;
	int m_count{ 0 };
	unordered_map<int, int> mapValue2Count;
};


class Solution2 {
public:
	int pathSum(TreeNode* root, int sum) {
		unordered_map<int, int> m;
		m[0] = 1;
		return helper(root, sum, 0, m);
	}
	int helper(TreeNode* node, int sum, int curSum, unordered_map<int, int>& m) {
		if (!node) return 0;
		curSum += node->val;
		int res = m[curSum - sum];
		++m[curSum];
		res += helper(node->left, sum, curSum, m) + helper(node->right, sum, curSum, m);
		--m[curSum];
		return res;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);

	root->left = new TreeNode(-2);

	root->right = new TreeNode(-3);

	Solution sol;

	sol.pathSum(root, -1);

	return 0;
}