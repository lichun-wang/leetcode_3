/*此题为求根节点到叶子节点的最小距离
  跟求最大距离不同
  我采用的方法是，对叶子节点进行判断
  只有当左右节点都是NULL的时候，才返回1
  否则不反回，继续进行判断*/

#include <iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		return dfs(root);
	}

	int dfs(TreeNode * root)
	{
		if (root->left == NULL && root->right == NULL)
			return 0;
		else if (root->left == NULL || root->right == NULL)
		{
			if (root->left == NULL)
				return dfs(root->right) + 1;
			if (root->right == NULL)
				return dfs(root->left) + 1;
		}
		else
			return min( dfs(root->left), dfs(root->right) ) + 1;
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
	cout<<so.minDepth(a1);
	system("pause");
	return 0;
}