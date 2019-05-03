/*
https://leetcode-cn.com/problems/reverse-linked-list-ii/
Reverse Linked List II
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//https://leetcode-cn.com/problems/baseball-game/

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        int s = 1;
        ListNode *nh = head;
        ListNode *pstart = nullptr;
        ListNode *pend = nullptr;
        ListNode* segHead = nullptr;
        ListNode* segTail = nullptr;

        while (head)
        {
            ListNode *pn = head->next;
            if (s + 1 == m)
            {
                pstart = head;
            }

            if (s >= m && s <= n)
            {
                if (segTail)
                {
                    head->next = segTail;
                    segTail = head;
                }
                else
                {
                    segHead = segTail = head;
                }
            }
            ++s;
            head = pn;
            if (s > n)
            {
                pend = head;
                break;
            }
        }

    // pay attention here, I forget the pstart = nullptr case at first time.
        if(pstart)
        {
            pstart->next = segTail;
        }
        else
        {
            nh = segTail;
        }
        
        segHead->next = pend;

        return nh;
    }
};