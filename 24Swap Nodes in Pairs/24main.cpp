/*24. Swap Nodes in Pairs
  此题考查的关键点在于链表中，节点的交换*/

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL)
			return head;

		int count = 0;
		ListNode * l = head;
		for (count = 0; l != NULL; count++)
		{
			l = l->next;
		}
		if (count <= 1)
			return head;

		ListNode *l1;
		ListNode *l2;
		l1 = head;
		l2 = l1->next;

		l1->next = l2->next;
		l2->next = l1;
		head = l2;     //处理头

		l2 = l1->next;

		for (; l1->next != NULL && l2->next != NULL;)
		{
			ListNode * l11 = l1->next;
			ListNode * l22 = l2->next;

			l11->next = l22->next;
			l22->next = l11;
			l1->next = l22;
			

			
			l1 = l1->next;
			l1 = l1->next;
			l2 = l1->next;
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
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = NULL;

	
		
	
	Solution so;
	ListNode *result = so.swapPairs(l1);

	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}
	system("pause");
	return 0;
}