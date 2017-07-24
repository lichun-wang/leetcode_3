#include <iostream>
#include <stack>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		int sizeL1 = 0;
		int sizeL2 = 0;
		
		ListNode * ptr1 = l1;
		ListNode * ptr2 = l2;

		while (ptr1 != NULL)
		{
			sizeL1++;
			ptr1 = ptr1->next;
		}

		while (ptr2 != NULL)
		{
			sizeL2++;
			ptr2 = ptr2->next;
		}


		stack<int> stack_l1;
		stack<int> stack_l2;

		if (sizeL1 > sizeL2)
		{
			int i = 0;
			while (i < sizeL1 - sizeL2)
			{
				stack_l2.push(0);
				i++;
			}
			
		}
		else if (sizeL1 < sizeL2)
		{
			int i = 0;
			while (i < sizeL2 - sizeL1)
			{
				stack_l1.push(0);
				i++;
			}

		}
		ptr1 = l1;
		ptr2 = l2;

		while (ptr1 != nullptr)
		{
			stack_l1.push(ptr1->val);
			ptr1 = ptr1->next;
		}

		while (ptr2 != nullptr)
		{
			stack_l2.push(ptr2->val);
			ptr2 = ptr2->next;
		}

		
		ListNode * newHead = new ListNode(1);
		newHead->next = nullptr;
		int step = 0;

		while (!stack_l1.empty() && !stack_l2.empty() )
		{
			int a1 = stack_l1.top();
			stack_l1.pop();
			int a2 = stack_l2.top();
			stack_l2.pop();

			int add = (a1 + a2 + step)%10;
			step = (a1 + a2 + step) / 10;

			ListNode * node = new ListNode(add);

			node->next = newHead->next;
			newHead->next = node;
		}

		if (step == 0)
			return newHead->next;
		else
		    return newHead;
	}
};

int main()
{
	ListNode * a1 = new ListNode(7);
	ListNode * a2 = new ListNode(2);
	ListNode * a3 = new ListNode(4);
	ListNode * a4 = new ListNode(3);

	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = nullptr;


	ListNode * b1 = new ListNode(5);
	ListNode * b2 = new ListNode(6);
	ListNode * b3 = new ListNode(4);

	b1->next = b2;
	b2->next = b3;
	b3->next = nullptr;

	Solution so;
	ListNode * res = so.addTwoNumbers(a1, b1);

	while (res != nullptr)
	{
		cout << res->val << endl;
		res = res->next;
	}

	system("pause");
	return 0;
}


