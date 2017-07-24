/*110. Balanced Binary Tree
此题关键在于深度优先搜索，进而求得每个节点是否平衡*/
#include <iostream>
#include <vector>
#include <set>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;
		int l = height(root->left);
		int r = height(root->right);

		if (abs(l - r) > 1)
			return false;
		else
			return isBalanced(root->left) && isBalanced(root->right);

	}
	int height(TreeNode * root)
	{
		if (root == NULL)
			return 0;
		int l = height(root->left) + 1;
		int r = height(root->right) + 1;

		return l > r ? l : r;
	}
};


TreeNode * dfs(vector<int >nums, int left, int right)
{
	if (left > right)
		return NULL;
	int mid = (left + right) / 2;
	TreeNode * newNode = new TreeNode(nums[mid]);
	newNode->left = dfs(nums, left, mid - 1);
	newNode->right = dfs(nums, mid + 1, right);
	return newNode;

}
/*新建平衡二叉树*/
TreeNode* sortedArrayToBST(vector<int>& nums) {
	TreeNode * result = NULL;
	if (nums.size() == 0)
		return result;
	result = dfs(nums, 0, nums.size() - 1);
	return result;
}
int main()
{
	int a[6] = { 0, 1, 2, 3, 4, 5 };
	vector<int> nums(a, a + 6);

	TreeNode * root = sortedArrayToBST(nums);
	Solution so;
	cout << so.isBalanced(root) << endl;
	system("pause");
	return 0;
}