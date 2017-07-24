#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		
		ListNode *result = NULL;
		ListNode *first = NULL;
		ListNode *now;

		int carry = 0;  //代表进位
		int nowCal = 0;
		for (; l1 != NULL && l2 != NULL; l1 = l1->next, l2 = l2->next)
		{

			now = add(l1->val, l2->val, carry);
			
			if (first == NULL)
			{
				first = now;
				result = now;
			}
			else{
				result->next = now;
				result = result->next;
			}
				

		}
	

		if (l1 == NULL)
		{
			while (l2 != NULL)   //处理l2剩余部分
			{
				
				now = add( 0 , l2->val, carry);
				result->next = now;
				result = result->next;
				l2 = l2->next;
			}
			
		}
		else
		{

			while (l1 != NULL)   //处理l1剩余部分
			{

				now = add(0, l1->val, carry);
				result->next = now;
				result = result->next;
				l1 = l1->next;
			}

		}

		if (carry == 1)  //最后处理进位
		{
			now = new ListNode( 1 );
			result->next = now;
			result = result->next;
		}


		result->next = NULL;
		return first;
	}


	ListNode* add(int a , int b ,int &carry){

		int nowCal = a + b + carry;
		if (nowCal >= 10)
		{
			carry = 1;
			nowCal = nowCal % 10;
		}
		else{
			carry = 0;
		}

		ListNode* now = new ListNode(nowCal);

		return now;

	}

	
};

int main()
{
	ListNode * a = new ListNode(2);
	ListNode * b = new ListNode(4);
	ListNode * c = new ListNode(6);
	

	a->next = b;
	b->next = c;
//	c->next = s;
	c->next = NULL;

	ListNode * d = new ListNode(5);
	ListNode * e = new ListNode(6);
	ListNode * f = new ListNode(4);
	ListNode * s = new ListNode(9);

	d->next = e;
	e->next = f;
	f->next = s;
	s->next = NULL;

	ListNode * r;
	Solution so;

	r = so.addTwoNumbers(a, d);

	return 0;

}