//检测链表中是否有环
#include<stdio.h>

bool CirLink(LinkNode *head)
{
	if(head == NULL || head.next == NULL)     //判断链表是否为空或者只有一个数
	{
		return false;
	}
	LinkNode *fast=head;
	LinkNode *slow=head->next;
	while(slow != fast )
	{
		if(fast == null || fast.next ==null)    //判断快指针能否到终点
		{
			return false;
		}
	*slow = slow->next;
	*fast = fast->next->next;
	}
	return true;
}
