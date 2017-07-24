/*141. Linked List Cycle
判断链表是否含有环
法一： 设置两个指针，一个慢，一个快，然后如果能追上，则证明存在环，如果追不上则不存在环
法二： 利用set*/
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
	/*bool hasCycle(ListNode *head) {

		if (head == NULL)
			return false;
		ListNode *start1 = head;
		ListNode *start2 = head;
		bool flag = false;
		while (start1->next != NULL && start2->next!=NULL)
		{
			start1 = start1->next;
			start2 = start2->next;
			if (start1->next != NULL)
				start1 = start1->next;
			else
				break;
			
			if (start1 == start2)
			{
				flag = true;
				break;
			}
		}
		return flag;
	}*/

	bool hasCycle(ListNode *head) {
		if (head == NULL)
			return false;
		set<ListNode *> sets;
		ListNode *p = head;
		while (p != NULL)
		{
			if (sets.find(p) != sets.end())
				return true;
			sets.insert(p);
		}
	
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
	l5->next = l1;




	Solution so;
	cout<<so.hasCycle(l1)<<endl;

	system("pause");
	return 0;
}