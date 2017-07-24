/*讨巧的方法，记住地址
此题还可以用递归搜索做，没做，需要后面反思*/
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

	void reorderList(ListNode* head) {
		if (head == NULL)
			return;
		vector<ListNode *> adds;
		ListNode * ptr = head;
		while (ptr != NULL)
		{
			adds.push_back(ptr);
			ptr = ptr->next;
		}

		ListNode * newHead = head;
		ListNode * topPtr = head;
		int size = adds.size();
		int i = size-1;
		while (i > size / 2)
		{
			ListNode * tail = adds[i];
			
			tail->next = newHead->next;
			newHead->next = tail;
			newHead = newHead->next->next;
			i--;
		}
		if (size%2 == 1)
		   newHead->next = NULL;
		else
		   newHead->next->next = NULL;
	}
};

int main()
{
	ListNode * l1 = new ListNode(1);
	ListNode * l2 = new ListNode(2);
	ListNode * l3 = new ListNode(3);
	ListNode * l4 = new ListNode(4);
	ListNode * l5 = new ListNode(5);
	ListNode * l6 = new ListNode(6);
//	ListNode * l7 = new ListNode(7);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = NULL;//l7;
//	l7->next = NULL;


	Solution so;
	so.reorderList(l1);
	ListNode * result = l1;
	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}
	system("pause");
	return 0;
}