/*
https://leetcode-cn.com/problems/add-two-numbers-ii/
Add Two Numbers II

You are given two non-empty linked lists representing two non-negative integers. 
The most significant digit comes first and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed. 
Example: 
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7


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
#include<stack>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* h = NULL;
        ListNode* tail = NULL;
        stack<ListNode*> s1;
        stack<ListNode*> s2;
        
        while(l1)
        {
            s1.push(l1);
            l1 = l1->next;
        }
        
        while(l2)
        {
            s2.push(l2);
            l2 = l2->next;
        }
        int s = 0;
        int sum = 0;
        
        while(!s1.empty()&&!s2.empty())
        {
            sum = (s1.top()->val+s2.top()->val+s);
            s = sum/10;
            ListNode* n = new ListNode(sum%10);
            if(NULL == h)
            {
                h = tail = n;
            }
            else
            {
                n->next = tail;
                tail = n;
            }
            s1.pop();
            s2.pop();           
        }
        while(!s1.empty())
        {
            sum = (s1.top()->val+s);
            s = sum/10;
            ListNode* n = new ListNode(sum%10);
            if(NULL == h)
            {
                h = tail = n;
            }
            else
            {
                n->next = tail;
                tail = n;
            }
            s1.pop(); 
        }
        while(!s2.empty())
        {
            sum = (s2.top()->val+s);
            s = sum/10;
            ListNode* n = new ListNode(sum%10);
            if(NULL == h)
            {
                h = tail = n;
            }
            else
            {
                n->next = tail;
                tail = n;
            }
            s2.pop(); 
        }
        if(s)
        {
              ListNode* n = new ListNode(s);
              n->next = tail;
              tail = n;
        }
        
        return tail;
    }
};