/*109. Convert Sorted List to Binary Search Tree
�������ã�����������ת��Ϊ���飬Ȼ���108��һ���������鴦��
��������Ҫע�����dfs�� vector<int > & "&"������ӣ��ᳬ���ռ䣬���Ϻ󲻻ᳬ���ռ�
ֵ��ע��
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