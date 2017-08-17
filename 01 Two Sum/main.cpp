#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include "solution.hpp"

using namespace std;

int main()
{	
	//sum two list
	solution lst;
	ListNode* l1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* l2 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* l3 = (ListNode*)malloc(sizeof(ListNode));
	
	cout << "input list1('-1' end):" << endl;
	l1 = lst.input(l1);
	cout << "input list2('-1' end):" << endl;
	l2 = lst.input(l2);
	
	l3 =  lst.addTwoNumbers(l1, l2);
	cout << "output list3 = list1 + list2:" << endl;
	for (ListNode* l = l3->next; l != NULL; l = l->next)
	{
		cout << l->val << " ";
	}
	return 0;
}
