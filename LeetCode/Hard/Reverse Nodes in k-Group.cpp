
#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


//basic idea: insert the node at head during traverse origin list.

//basic idea: insert the node at head during traverse origin list.
class Solution
{
public:
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		ListNode* nh = NULL;
		ListNode* nt = NULL;

		ListNode* h = NULL;
		ListNode* tail = NULL;

		int count = 0;

		while (head)
		{
			ListNode* t = head;
			head = head->next;
			++count;
			if (k == count) //has form the k unit
			{
				count = 0;
				if (NULL == tail)
				{
					tail = h = t;
					tail->next = NULL;
				}
				else
				{
					t->next = h;
					h = t;
				}

				if (NULL == nh)
				{
					nh = h;
					nt = tail;
					nt->next = NULL;
				}
				else
				{
					nt->next = h;
					nt = tail;
					nt->next = NULL;
				}
				h = tail = NULL;
			}
			else
			{
				if (NULL == tail)
				{
					tail = h = t;
					tail->next = NULL;
				}
				else
				{
					t->next = h;
					h = t;
				}
			}
		}
		if (count) // there are less k nodes which can't form unit.
		{
			//do insert at head again.
			ListNode* hk = NULL;
			ListNode* tk = NULL;
			while (h != tail)
			{
				ListNode* t = h;
				h = h->next;
				if (NULL == hk)
				{
					hk = t;
					tk = t;
					tk->next = NULL;
				}
				else
				{
					t->next = hk;
					hk = t;
				}
			}
			h->next = hk;
			hk = h;
			if (NULL == nt)
			{
				nh = nt = hk;
			}
			else
			{
				nt->next = hk;
			}
		}

		return nh;
	}
};


ListNode* BuildList(int count)
{
	ListNode* head = new ListNode(1);
	ListNode* tail = head;
	for (int i = 2; i <= count; ++i)
	{
		tail->next = new ListNode(i);
		tail = tail->next;
	}
	
	return head;
}


int main()
{
	ListNode* head = BuildList(1);
	int K = 1;
	Solution sol;
	ListNode* h = sol.reverseKGroup(head, K);


	return 0;
}