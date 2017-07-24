#include<iostream>
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
	void dfs(TreeNode * root, vector<TreeNode *>& adds)
	{
		if (root == NULL)
			return;
		if (root != NULL)
		{
			adds.push_back(root);
			dfs(root->left, adds);
			dfs(root->right, adds);
		}
	}
	void flatten(TreeNode* root) {
		if (root == NULL)
			return;
		vector<TreeNode *> adds;
		dfs(root, adds);
		//root = adds[0];
		TreeNode *root_v = root;
		for (int i = 1; i< adds.size(); i++)
		{
			root_v->left = NULL;
			root_v->right = adds[i];
			root_v = root_v->right;
		}
		root_v = NULL;
	}
};


int main()
{
	TreeNode * a1 = new TreeNode(1);
	TreeNode * a2 = new TreeNode(2);
	//TreeNode * a3 = new TreeNode(3);
	//TreeNode * a4 = new TreeNode(4);
	//TreeNode * a5 = new TreeNode(5);
	//TreeNode * a6 = new TreeNode(6);

	a1->left = a2;
	//a1->right = a5;
	//a2->left = a3;
	//a2->right = a4;
	//a5->right = a6;

	Solution so;

	so.flatten(a1);

	TreeNode * aa = a1;
	while (aa != NULL)
	{
		cout << aa->val<<endl;
		aa = aa->right;
	}

	int a;
	cin >> a;
	return 0;
}