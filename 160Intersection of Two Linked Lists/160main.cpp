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

class Solution {
public:
	int calLength(ListNode * head)
	{
		int len = 0;
		while (head != NULL)
		{
			len++;
			head = head->next;
		}
		return len;
	}
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

		if (headA == NULL || headB == NULL)
		{
			return NULL;
		}
		int lenA = calLength(headA);
		int lenB = calLength(headB);
		ListNode *ptrA = headA;
		ListNode *ptrB = headB;

		if (lenA > lenB)
		{
			int minus = lenA - lenB;
			while (minus > 0)
			{
				minus--;
				ptrA = ptrA->next;
			}
		}
		if (lenA < lenB)
		{
			int minus = lenB - lenA;
			while (minus > 0)
			{
				minus--;
				ptrB = ptrB->next;
			}
		}

		while (ptrA != NULL && ptrB != NULL)
		{
			if (ptrA == ptrB)
				return ptrA;
			else
			{
				ptrA = ptrA->next;
				ptrB = ptrB->next;
			}
		}

		return NULL;
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
	cout << so.getIntersectionNode(l1,l2)->val << endl;

	system("pause");
	return 0;
}