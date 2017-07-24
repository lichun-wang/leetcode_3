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
	ListNode* deleteDuplicates(ListNode* head) {

		if (head == NULL)
			return head;
		ListNode * ptr = head;
		ListNode * l = head;
		

		while (l->next != NULL)
		{
			if (ptr->val == l->next->val)
			{
				ListNode * cur = l->next;
				l->next = l->next->next;
				delete[] cur;
			}
			else
			{
				ptr = l->next;
				l = l->next;
			}
		}

		return head;

	}
};


int main()
{
	ListNode * l1 = new ListNode(1);
	ListNode * l2 = new ListNode(1);
	ListNode * l3 = new ListNode(2);
	ListNode * l4 = new ListNode(2);
	ListNode * l5 = new ListNode(5);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = NULL;




	Solution so;
	ListNode *result = so.deleteDuplicates(l1);

	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}
	system("pause");
	return 0;
}