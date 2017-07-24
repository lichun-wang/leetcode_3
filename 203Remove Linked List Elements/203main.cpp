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
	ListNode* removeElements(ListNode* head, int val) {
		if (head == NULL)
			return head;
		ListNode *ptr = head;
		if (head->val == val)
		{

			while (ptr != NULL &&ptr->val == val)
			{
				ListNode * l = ptr;
				ptr = ptr->next;
				delete [] l;
			}
			head = ptr;
		}
		if (ptr == NULL)
			return head;

		while (ptr->next!=NULL)
		{
			if (ptr->next->val != val)
			{
				ptr = ptr->next;
			}
			else
			{
				ListNode * l = ptr->next;
				ptr->next = ptr->next->next;
				delete[] l;
			}
			
			if (ptr == NULL)
				break;
		}

		return head;

	}
};


int main()
{
	ListNode * l1 = new ListNode(1);
	ListNode * l2 = new ListNode(2);
	ListNode * l3 = new ListNode(2);
	ListNode * l4 = new ListNode(3);
	ListNode * l5 = new ListNode(4);
	ListNode * l6 = new ListNode(5);
	ListNode * l7 = new ListNode(6);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = l7;
	l7->next = NULL;




	Solution so;
	ListNode *result = so.removeElements(l1, 2);

	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}
	system("pause");
	return 0;
}