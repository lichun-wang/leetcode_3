/*142. Linked List Cycle II
返回循环链表的开始节点
利用set找到重复的即可*/
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
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL)
			return NULL;
		set<ListNode*> sets;
		ListNode * p = head;
		while (p != NULL)
		{
			if (sets.find(p) != sets.end())
				return p;
			sets.insert(p);
			p = p->next;
		}
		if (p == NULL)
			return NULL;
	}
};


int main()
{
	ListNode * l1 = new ListNode(1);
	//ListNode * l2 = new ListNode(2);
	//ListNode * l3 = new ListNode(3);
	//ListNode * l4 = new ListNode(4);
	//ListNode * l5 = new ListNode(5);
	//l1->next = l2;
	//l2->next = l3;
	//l3->next = l4;
	//l4->next = l5;
	//l5->next = l1;
	l1->next = NULL;



	Solution so;
	ListNode *result = so.detectCycle(l1);

//	while (result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}

	system("pause");
	return 0;
}