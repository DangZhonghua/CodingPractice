/*
https://leetcode-cn.com/problems/partition-list/
Partition List

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
Example:
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5

*/


#include<iostream>
using namespace std;

 //Definition for singly-linked list.

  struct ListNode 
  {
      int val;
      ListNode * next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

class Solution 
{
public:
    ListNode* partition(ListNode* head, int x) 
    {

        ListNode* pLessHead = NULL;
        ListNode* pLessTail = NULL;
        ListNode* pGreatHead = NULL;
        ListNode* pGreatTail = NULL;
        ListNode* h = head;
        while(h)
        {
            if(h->val<x)
            {
                if(NULL == pLessHead)
                {
                    pLessHead = pLessTail = h;
                }
                else 
                {
                    pLessTail->next = h;
                    pLessTail = h;
                }
            }
            else
            {
                if( NULL == pGreatHead)
                {
                    pGreatHead = pGreatTail = h;
                }
                else
                {
                    pGreatTail->next = h;
                    pGreatTail = h;
                }
            }
            h = h->next;
        }

        if(pLessTail)
        {
            h = pLessHead;
            pLessTail->next = pGreatHead;
            if(pGreatTail)// for all less than x
            {
              pGreatTail->next = NULL;
            }
           
        }
        else
        {
            h = pGreatHead;
            if(pGreatTail) // for empty list
            {
                pGreatTail->next = NULL;
            }
        }
        return h;
    }
};