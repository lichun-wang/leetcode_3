#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		int sum = 0;
		if (root == NULL)
			return 0;
		if (root->left == NULL&&root->right == NULL)
			return 0;
		else if (root->left == NULL)
			dfs(root->right, 0, sum);
		else if (root->right == NULL)
			dfs(root->left, 1, sum);
		else
		{
			dfs(root->left, 1, sum);
			dfs(root->right, 0, sum);

		}
		
		return sum;

	}
	void dfs(TreeNode * root, bool leftLeaves, int &sum)
	{
		if(root->left == NULL && root->right == NULL && leftLeaves == 1)
		{
			sum += root->val;
			return;
		}

		if (root->left != NULL)
			dfs(root->left, 1, sum);
		if (root->right != NULL)
			dfs(root->right, 0, sum);

		return;
	}
};

int main()
{
	TreeNode * a1 = new TreeNode(1);
	TreeNode * a2 = new TreeNode(2);
	TreeNode * a3 = new TreeNode(3);
	TreeNode * a4 = new TreeNode(4);
	TreeNode * a5 = new TreeNode(5);
	TreeNode * a6 = new TreeNode(6);
	TreeNode * a7 = new TreeNode(7);
	TreeNode * a8 = new TreeNode(8);
	TreeNode * a9 = new TreeNode(9);
	TreeNode * a10 = new TreeNode(10);
	TreeNode * a11 = new TreeNode(11);

	a1->left = a2; a1->right = a3;
	a2->left = a4; a2->right = a5;
	a4->left = a8; a4->right = a9;
	a5->left = a10; a5->right = a11;
	a3->left = a6; a3->right = a7;

	Solution so;
	cout<<so.sumOfLeftLeaves(a1);
	system("pause");
	return 0;
}