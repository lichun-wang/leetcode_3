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
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL)
			return head;
		ListNode * lessPtr = new ListNode(0);
		ListNode * less = lessPtr;
		ListNode * morePtr = new ListNode(0);
		ListNode * more = morePtr;
		ListNode * l = head;
		if (head->val < x)
		{
			lessPtr->next = head;
			lessPtr = lessPtr->next;
		}
		else
		{
			morePtr->next = head;
			morePtr = morePtr->next;
		}

		while (l->next != NULL)
		{
			if (l->next->val < x)
			{
				lessPtr->next = l->next;
				lessPtr = lessPtr->next;
			}
			else
			{
				morePtr->next = l->next;
				morePtr = morePtr->next;
			}
			l = l->next;
		}
		lessPtr->next = more->next;
		morePtr->next = NULL;
		return less->next;
	}
};

int main()
{
	ListNode * l1 = new ListNode(1);
	ListNode * l2 = new ListNode(4);
	ListNode * l3 = new ListNode(3);
	ListNode * l4 = new ListNode(2);
	ListNode * l5 = new ListNode(5);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = NULL;




	Solution so;
	ListNode *result = so.partition(l1,3);

	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}
	system("pause");
	return 0;
}