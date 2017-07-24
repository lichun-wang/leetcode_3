#include<iostream>
#include<algorithm>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == NULL)
			return head;
		if (head->next == NULL)
			return head;

		ListNode * ptr = head;
		ListNode * evenHead = ptr;
		ListNode * oddHead = ptr->next;
		ListNode * evenPtr = evenHead;
		ListNode * oddPtr = oddHead;
		ptr = ptr->next->next;
		int num = 3;
		while (ptr != NULL)
		{
			if (num % 2 == 1)
			{
				evenPtr->next = ptr;
				evenPtr = evenPtr->next;
			}
			else
			{
				oddPtr->next = ptr;
				oddPtr = oddPtr->next;
			}
			ptr = ptr->next;
			num++;
	 	}
		evenPtr->next = oddHead;
		oddPtr->next = NULL;
		return evenHead;
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
	
	ListNode * result = so.oddEvenList(l1);
	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}
	system("pause");
	return 0;
}