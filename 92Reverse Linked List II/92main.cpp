/*此题为将链表中的第m - n  的位置转换，我采用了投机取巧的方式
    并没有改变链表的节点，而是改变链表中的值
	利用栈，倒叙输出*/

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL)
			return head;
		ListNode * l = head;
		int count = 0;
		vector<int > vals;
		while (l != NULL)
		{
			count++;
			if (count >= m && count <= n)
				vals.push_back(l->val);
			l = l->next;
		}
		l = head;
		count = 0;
		int out = 0;
		while (l != NULL)
		{
			count++;
			if (count >= m && count <= n)
			{
				l->val = vals[n - m - out];
				out++;
			}
				
			l = l->next;
		}
		
		return head;
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
	ListNode *result = so.reverseBetween(l1,1, 5);

	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}
	system("pause");
	return 0;
}