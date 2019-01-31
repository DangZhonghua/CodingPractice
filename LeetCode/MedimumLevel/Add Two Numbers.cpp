/*
https://leetcode-cn.com/problems/add-two-numbers/
Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* h = NULL;
        ListNode* tail = NULL;
        int s = 0;
        int sum = 0;
        while(l1 && l2)
        {
            sum = (l1->val+l2->val+s);
            l1 = l1->next;
            l2 = l2->next;
            s = (sum/10);
            ListNode* n = new ListNode(sum%10);
            if(NULL == h)
            {
                h = tail = n;
            }
            else
            {
                tail->next = n;
                tail = n;
            }
        }
        while(l1)
        {
            sum = (l1->val+s);
            l1 = l1->next;
            s = (sum/10);
            ListNode* n = new ListNode(sum%10);
            if(NULL == h)
            {
                h = tail = n;
            }
            else
            {
                tail->next = n;
                tail = n;
            }
        }
        while(l2)
        {
            sum = (l2->val+s);
            l2 = l2->next;
            s = (sum/10);
            ListNode* n = new ListNode(sum%10);
            if(NULL == h)
            {
                h = tail = n;
            }
            else
            {
                tail->next = n;
                tail = n;
            }
        }
        if(s)
        {
            ListNode* n = new ListNode(s);
            if(NULL == h)
            {
                h = tail = n;
            }
            else
            {
                tail->next = n;
                tail = n;
            }
        }
        return h;
    }
};