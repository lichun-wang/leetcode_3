/*树的广度优先，利用队列*/
#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	void treeWidthFirst(TreeNode * root)
	{
		if (root == NULL)
			return;
		queue <TreeNode *> qu;
		qu.push(root);
		while (!qu.empty())
		{
			TreeNode * root = qu.front();
			qu.pop();
			cout << root->val << endl;

			if (root->left != NULL)
				qu.push(root->left);
			if (root->right != NULL)
				qu.push(root->right);
		}
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
	so.treeWidthFirst(a1);
	system("pause");
	return 0;
}