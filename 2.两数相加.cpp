/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (32.76%)
 * Total Accepted:    88K
 * Total Submissions: 268.7K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int s = 0;
        int step = 0;
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(NULL != l1 && NULL != l2)
        {
            s = step + l1->val + l2->val;
            step = s/10;
            s = s%10;
            if(NULL == tail)
            {
                head = tail = new ListNode(s);
            }
            else
            {
                tail->next = new ListNode(s);
                tail = tail->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while( NULL != l1)
        {
            s = step + l1->val;
            step = s/10;
            s = s%10;
            if(NULL == tail)
            {
                head = tail = new ListNode(s);
            }
            else
            {
                tail->next = new ListNode(s);
                tail = tail->next;
            }
            l1 = l1->next;
        }
        while( NULL != l2)
        {
            s = step + l2->val;
            step = s/10;
            s = s%10;
            if(NULL == tail)
            {
                head = tail = new ListNode(s);
            }
            else
            {
                tail->next = new ListNode(s);
                tail = tail->next;
            }
            l2 = l2->next;
        } 
        if(step) // This is important case.
        {
            if(NULL == tail)
            {
                head = tail = new ListNode(step);
            }
            else
            {
                tail->next = new ListNode(step);
                tail = tail->next;
            }
        }

        return head;     
    }

};

