/*此题
  利用深度优先搜索，先左后右 与先右后左结果是否相同*/
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//	bool isSymmetric(TreeNode* root) {
//		if (root == NULL)
//			return false;
//		return dfs(root->left, root->right);
//	}
//	bool  dfs(TreeNode *root1 , TreeNode *root2)
//	{
//		if (root1 == NULL && root2 == NULL)
//			return true;
//		if (root1 == NULL || root2 == NULL)
//			return false;
//		if (root1->val == root2->val)
//			return true;
//		else
//			return false;
//
//		return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
//
//	}
//};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		queue <TreeNode *> left_first;
		queue <TreeNode *> right_first;

		bool isSy = true;
		
		left_first.push(root);
		right_first.push(root);
		while (!left_first.empty() && !right_first.empty())
		{
			TreeNode * left = left_first.front();
			left_first.pop();
			TreeNode * right = right_first.front();
			right_first.pop();

			if (left->val != right->val)
			{
				isSy = false;
				break;
			}

			if (!(left->left == NULL && right->right == NULL))
			{
				if (left->left == NULL || right->right == NULL)
				{
					isSy = false;
					break;
				}
				else
				{
					left_first.push(left->left);
					right_first.push(right->right);
				}
			}
	


			if (!(left->right == NULL && right->left == NULL))
			{
				if (left->right == NULL || right->left == NULL)
				{
					isSy = false;
					break;
				}
				else
				{
					left_first.push(left->right);
					right_first.push(right->left);
				}
			}

		}
		
		return isSy;
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
	cout<<so.isSymmetric(a1);
	system("pause");
	return 0;
}