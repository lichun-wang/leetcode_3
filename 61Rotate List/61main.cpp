/* 61. Rotate List
   此题的关键在于建立循环链表*/
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {

		if (head == NULL)
			return head;

		ListNode * ll = head;
		int count = 1;
		while (ll->next != NULL)
		{
			count++;
			ll = ll->next;
		}
		int step = 0;
		if (count < k)
		{
			k = k % count;
			step = count - k;
		}
		else
		{
			step = count - k;
		}
	
		ll->next = head;
		
		while (step > 0)
		{
			ll = ll->next;
			step--;
		}
		head = ll->next;
		ll->next = NULL;
		
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
	ListNode *result = so.rotateRight(l1, 6);

	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}
	system("pause");
	return 0;
}