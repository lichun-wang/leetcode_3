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
	ListNode* reverseKGroup(ListNode* head, int k) {
		int count = 0;
		ListNode *l = head;
		while (l != NULL)
		{
			count++;
			l = l->next;
		}
		if (count < k)
			return head;

		vector<int> stack;
		l = head;
		while (l != NULL)
		{
			int num = k;
			ListNode * l1 = l;
			while (num>0 && l!=NULL)
			{
				stack.push_back(l->val);
				l = l->next;
				num--;
			}
				
			if (num == 0)
			{
				num = k-1;
				while (num >= 0 && l1 != NULL)
				{
					l1->val = stack[num];
					l1 = l1->next;
					num--;
				}
				stack.clear();
			}
		
		}
		return head;
	}
};

int main()
{
	ListNode * l1 = new ListNode(1);
	ListNode * l2 = new ListNode(2);
	//ListNode * l3 = new ListNode(3);
	//ListNode * l4 = new ListNode(4);
	//ListNode * l5 = new ListNode(5);
	l1->next = l2;
	l2->next = NULL;
	//l2->next = l3;
	//l3->next = l4;
	//l4->next = l5;
	//l5->next = NULL;




	Solution so;
	ListNode *result = so.reverseKGroup(l1,2);

	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}
	system("pause");
	return 0;
}