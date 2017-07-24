/*按照层次输出树的节点
  此题的关键点在于如何判断访问节点在第几层
  这里采用的方法是，利用queue的size来判断，每层根据大小来处理
*/

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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		vector<int> temp;
		if (root == NULL)
			return result;
		queue<TreeNode *> tree_qu;

		tree_qu.push(root);

		while (!tree_qu.empty())
		{
			temp.clear();
			int size = tree_qu.size();
			while (size > 0)
			{
				TreeNode * top = tree_qu.front();
				tree_qu.pop();

				temp.push_back(top->val);

				if (top->left != NULL)
					tree_qu.push(top->left);
				if (top->right != NULL)
					tree_qu.push(top->right);
				size--;
			}

			result.push_back(temp);
		}
		return result;

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
	so.levelOrder(a1);
	system("pause");
	return 0;
}
