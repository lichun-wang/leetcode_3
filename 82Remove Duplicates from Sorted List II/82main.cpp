/*此题的关键点在于删除所有的重复，第一个也要删除
   所以比较的时候都采用 ->next 进行比较*/
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
		int count = 0;
		
		ListNode * newHead = new ListNode(0);
		newHead->next = head;
		ListNode * l = head;
		ListNode * ptr = newHead;

		
		while (l->next != NULL && l!=NULL)
		{
			if (l->next->val == ptr->next->val)
			{
				while (l->next != NULL && l->next->val == ptr->next->val)
				{
					ListNode * cur = l->next;
					l->next = l->next->next;
					delete [] cur;
				}
				ListNode * cur = ptr->next;
				
				ptr->next = l->next;
				if (ptr->next == NULL)   //如果结束了 返回
					break;
				l = ptr->next;
				delete[] cur;
			}
			else
			{
				ptr = ptr->next;
				l = ptr->next;
			}
		}
		return newHead->next;

	}
};

int main()
{
	ListNode * l1 = new ListNode(1);
	ListNode * l2 = new ListNode(1);
	ListNode * l3 = new ListNode(2);
	ListNode * l4 = new ListNode(3);
	ListNode * l5 = new ListNode(3);
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