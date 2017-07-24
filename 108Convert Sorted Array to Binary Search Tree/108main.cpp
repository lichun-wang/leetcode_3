/*108. Convert Sorted Array to Binary Search Tree
  此题的关键点在于利用递归建立一颗二叉树
  此为本题的难点，需要经常过来反思
*/
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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		TreeNode * result = NULL;
		if (nums.size() == 0)
			return result;
		result = dfs(nums, 0, nums.size() - 1);
		return result;
	}
	TreeNode * dfs(vector<int >nums,int left,int right)
	{
		if (left > right)
			return NULL;
		int mid = (left + right) / 2;
		TreeNode * newNode = new TreeNode(nums[mid]);
		newNode->left = dfs(nums, left, mid - 1);
		newNode->right = dfs(nums, mid + 1, right);
		return newNode;

	}
};

int main()
{
	int a[6] = { 0, 1, 2, 3, 4, 5 };
	vector<int> nums(a, a + 6);
	Solution so;
	so.sortedArrayToBST(nums);
	system("pause");
	return 0;
}