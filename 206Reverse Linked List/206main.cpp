#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


struct ListNode {
     int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//class Solution {
//public:
//	ListNode* reverseList(ListNode* head) {
//		if (head == NULL)
//			return head;
//		ListNode * l = head;
//		vector<int > vals;
//		int count = 0;
//		while (l != NULL)
//		{
//			count++;
//			vals.push_back(l->val);
//			l = l->next;
//		}
//		l = head;
//		
//		while (l != NULL)
//		{
//			
//			l->val = vals[--count];
//			l = l->next;
//		}
//
//		return head;
//	}
//};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL)
			return head;
		
		ListNode * newHead = new ListNode(0);
		newHead->next = NULL;
		ListNode * ptr = head;
		ListNode * changePtr = ptr;

		while (ptr != NULL)
		{
			changePtr = ptr;
			ptr = ptr->next;

			ListNode * headNext = newHead->next;

			newHead->next = changePtr;
			changePtr->next = headNext;

		}

		return newHead->next;
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
	ListNode *result = so.reverseList(l1);

	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}
	system("pause");
	return 0;
}