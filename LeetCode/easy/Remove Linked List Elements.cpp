/*
https://leetcode-cn.com/problems/remove-linked-list-elements/
Remove Linked List Elements
Remove all elements from a linked list of integers that have value val.
Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5


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



class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* h = NULL;
        ListNode* tail = NULL;
        
        while(head)
        {
            if(val == head->val)
            {
                head = head->next;
            }
            else
            {
                if(h == NULL)
                {
                    h = tail = head;
                }
                else
                {
                    tail->next = head;
                    tail = head;
                }
                head = head->next;
            }
        }
        if(tail)
        {
            tail->next = NULL;
        }
        return h;
    }
};