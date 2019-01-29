/*
https://leetcode-cn.com/problems/odd-even-linked-list/
Odd Even Linked List

Given a singly linked list, group all odd nodes together followed by the even nodes. 
Please note here we are talking about the node number and not the value in the nodes.
You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
Example 1:
Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:
Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...

给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
示例 1:
输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
示例 2:
输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL
说明:
应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。

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
    ListNode* oddEvenList(ListNode* head) 
    {
        ListNode* hOdd = NULL;
        ListNode* hEven = NULL;
        ListNode* hOddInsert = NULL;
        ListNode* hEvenInsert = NULL;
        
        int count = 0;
        while(head)
        {
            ++count;
            if(count&1)
            {
                if(NULL == hOdd)
                {
                    hOdd = hOddInsert = head;
                }
                else
                {
                    hOddInsert->next = head;
                    hOddInsert = head;
                }
            }
            else
            {
                if(NULL == hEven)
                {
                    hEven = hEvenInsert = head;
                }
                else
                {
                    hEvenInsert->next = head;
                    hEvenInsert = head;
                }
            }

            head = head->next;
            if(hEvenInsert)
            {
                hEvenInsert->next = NULL;
            }          
            if(hOddInsert)
            {
                hOddInsert->next = NULL;
            } 
        }

        if(hOddInsert)
        {
            hOddInsert->next = hEven;
        }     
        return hOdd;
    }
};