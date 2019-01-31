/*
https://leetcode-cn.com/problems/swap-nodes-in-pairs/
Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.
Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:
Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
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
    ListNode* swapPairs(ListNode* head) 
    {
        //insert at head during traverse the list.
        ListNode* nh    = NULL;
        ListNode* nt    = NULL;
        ListNode* h     = NULL;
        ListNode* tail  = NULL;

        int K = 2;

        int count = 0;
        while(head)
        {
            ListNode* t = head;
            head = head->next;

            ++count;
            if(count == K)
            {
                count = 0;
                if(NULL == tail)
                {
                    tail = t;
                    h = t;
                }
                else
                {
                    t->next = h;
                    h = t;
                }
                tail->next = NULL;
                
                if(NULL == nh)
                {
                    nh = h;
                    tail->next = NULL;
                    nt = tail;
                }
                else
                {
                    nt->next = h;
                    tail->next = NULL;
                    nt = tail;
                }
                h = tail = NULL;
            }
            else
            {
                if(NULL == tail)
                {
                    tail = t;
                    h = t;
                }
                else
                {
                    t->next = h;
                    h = t;
                }
            }    
        }

        // Does need handle the list length is K multiple case
        if(count)
        {
            if( nh)
            {
                nt->next = h;
                h->next= NULL;
            }
            else
            {
                nh = h;
                h->next = NULL;
            }      
        }

        return nh;
    }
};