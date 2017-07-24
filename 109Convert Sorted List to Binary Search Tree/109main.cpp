/*109. Convert Sorted List to Binary Search Tree
此题利用，将链表首先转换为数组，然后跟108题一样按照数组处理
不过，需要注意的是dfs中 vector<int > & "&"如果不加，会超出空间，加上后不会超出空间
值得注意
*/
#include <iostream>
#include <vector>
#include <set>
#include<algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};





class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		TreeNode * result = NULL;
		vector<int > nums;
		ListNode * p = head;
		while (p != NULL)
		{
			nums.push_back(p->val);
			p = p->next;
		}
			
		result = dfs(nums, 0, nums.size()-1);
		return result;
	}
	TreeNode * dfs(vector<int> &nums, int left, int right)
	{
		if (left > right)
			return NULL;
		int mid = (left + right) / 2;
		TreeNode * root = new TreeNode(nums[mid]);
		root->left = dfs(nums, left, mid - 1);
		root->right = dfs(nums, mid + 1, right);
		return root;
	}
};

int main()
{
	ListNode * l1 = new ListNode(1);
	ListNode * l2 = new ListNode(2);
	ListNode * l3 = new ListNode(3);
	ListNode * l4 = new ListNode(4);
	ListNode * l5 = new ListNode(5);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = NULL;
	Solution so;
	so.sortedListToBST(l1);
	system("pause");
	return 0;
}