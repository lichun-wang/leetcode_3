/*138. Copy List with Random Pointer
  A linked list is given such that each node contains an additional random pointer 
  which could point to any node in the list or null.
  Return a deep copy of the list.
  
  此题的关键点在于对于随机指针的复制，如果采用传统的扫描全部的话，比较浪费时间
  这里采用的方法是，复制后将所有的加入到map中，然后利用map进行查找，比较快速
  
  法二； 将每一个复制插入到链表的后面，这样做便于修改，这里没有做*/

#include <iostream>
#include <vector>
#include <map>
#include<algorithm>
using namespace std;


struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode * result_ptr = NULL;
		RandomListNode * result_head = result_ptr;
		if (head == NULL)
			return result_head;
		map<RandomListNode *, RandomListNode *> ptr_add;

		RandomListNode * ptr = head;
		RandomListNode * newNode = new RandomListNode(ptr->label);
		result_ptr = result_head = newNode;
		ptr_add.insert(make_pair(ptr, newNode));
		ptr = ptr->next;
		
		while (ptr != NULL)
		{
			newNode = new RandomListNode(ptr->label);
			result_ptr->next = newNode;
			ptr_add.insert(make_pair(ptr,newNode));
			result_ptr = result_ptr->next;
			ptr = ptr->next;
		}

		result_ptr->next = NULL;

		ptr = head;
		result_ptr = result_head;
		while (ptr != NULL && result_ptr != NULL)
		{
			if (ptr->random != NULL)
			{
				RandomListNode * random_ptr = ptr_add[ptr->random];
				result_ptr->random = random_ptr;
			}
			ptr = ptr->next;
			result_ptr = result_ptr->next;
		}

		return result_head;


	}
};

int main()
{
	RandomListNode * l1 = new RandomListNode(1);
	RandomListNode * l2 = new RandomListNode(2);
	RandomListNode * l3 = new RandomListNode(3);
	RandomListNode * l4 = new RandomListNode(4);
	RandomListNode * l5 = new RandomListNode(5);
	RandomListNode * l6 = new RandomListNode(6);
	//	RandomListNode * l7 = new RandomListNode(7);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = NULL;//l7;
	//	l7->next = NULL;


	Solution so;
	RandomListNode * result = so.copyRandomList(l1);
	while (result != NULL)
	{
		cout << result->label << endl;
		result = result->next;
	}
	system("pause");
	return 0;
}