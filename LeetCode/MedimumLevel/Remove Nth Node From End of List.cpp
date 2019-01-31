/*
https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
Remove Nth Node From End of List

Given a linked list, remove the n-th node from the end of list and return its head.
Example:
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Follow up:
Could you do this in one pass?

Maintain two pointers and update one with a delay of n steps.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<iostream>
using namespace std;

 struct ListNode 
 {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* pre = NULL;
		int count = 0;
		while (fast)
		{
			++count;
			fast = fast->next;
			if (count >= n&& fast)
			{
				pre = slow;
				slow = slow->next;
			}
		}
		if (pre)
		{
			pre->next = slow->next;
		}
		else
		{
			head = head->next;
		}

		return head;
	}
};
