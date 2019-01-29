/*
https://leetcode-cn.com/problems/split-linked-list-in-parts/
Split Linked List in Parts

Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".
The length of each part should be as equal as possible: no two parts should have a size differing by more than 1.
This may lead to some parts being null.
The parts should be in order of occurrence in the input list,
and parts occurring earlier should always have a size greater than or equal parts occurring later.
Return a List of ListNode's representing the linked list parts that are formed.
Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
Example 1:
Input:
root = [1, 2, 3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The input and each element of the output are ListNodes, not arrays.
For example, the input root has root.val = 1, root.next.val = 2, \root.next.next.val = 3, and root.next.next.next = null.
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but it's string representation as a ListNode is [].

Example 2:
Input:
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.

Note:
The length of root will be in the range [0, 1000].
Each value of a node in the input will be an integer in the range [0, 999].
k will be an integer in the range [1, 50].

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<vector>
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k)
	{
		int Len = 0;
		ListNode* h = root;
		vector<ListNode*> vr(k, NULL);
		vector<ListNode*> vi(k, NULL);
		vector<int> vc(k, 0);
		while (h)
		{
			++Len;
			h = h->next;
		}

		int p = Len / k;
		int m = Len % k;
		int i = 0;
		int curCount = 0;

		if (0 == p)
		{
			for (int j = 0; j < Len; ++j)
			{
				vc[j] = 1;
			}
		}
		else
		{
			for (int j = 0; j < k; ++j)
			{
				vc[j] = p;
				if (j < m)
				{
					vc[j] += 1;
				}
			}
		}

		h = root;
		i = 0;
		while (h)
		{
			ListNode* t = h;
			h = h->next;
			t->next = NULL;
			++curCount;

			if (curCount == vc[i])
			{
				if (vr[i] == NULL)
				{
					vr[i] = t;
					vi[i] = t;
				}
				else
				{
					vi[i]->next = t;
				}
				curCount = 0;
				++i;
			}
			else
			{
				if (vr[i] == NULL)
				{
					vr[i] = vi[i] = t;
				}
				else
				{
					vi[i]->next = t;
					vi[i] = t;
				}
			}
		}
		return vr;
	}
};

ListNode* BuildList(int N)
{
	ListNode* head = new ListNode(1);
	ListNode* insert = head;
	
	for (int i = 2; i <= N; ++i)
	{
		ListNode* t = new ListNode(i);
		insert->next = t;
		insert = t;
	}
	
	return head;
}


int main()
{
	ListNode* head = BuildList(10);
	Solution sol;
	sol.splitListToParts(head, 3);


	return 0;
}