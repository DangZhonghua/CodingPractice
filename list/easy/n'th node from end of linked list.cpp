/*
n'th node from end of linked list

Given a linked list, the task is to find the n'th node from the end.  It is needed to complete a method that takes two argument, head of linked list and an integer n. There are multiple test cases. For each test case, this method will be called individually.


Input:
The first line of input contains number of test cases.  Every test case cntains two lines.  First line of every test case contains two space separated values, number of nodes  in linked list followed by value of n.  Second line of every test case contains data items of linked list.


Output:
Corresponding to each test case, output a single integer that is the nth integer in the linked list from the end. Print -1 if the value of n is greater than the number of elements in the linked list.

Constraints:
1 <= T <= 50
0 <= No of Nodes <= 1000
0 <= Data in Nodes <= 1000


Example:
Input:
2
9 2
1 2 3 4 5 6 7 8 9
4 5
10 -5 -100 5
 

Output:
8
-1


*/

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

 struct Node
 {
   int data;
   Node* next;
 }; 
/* Should return data of n'th node from the end of linked list */

#include<iostream>
#include<stack>
using namespace std;

int getNthFromLast(Node *head, int n)
{
       // Your code here
    stack<Node*> s;
    int data = -1;
    while(head)
    {
        s.push(head);
        head = head->next;
    }
    if(s.size()>=n)
    {
        int i = 0;
        while(i<n)
        {
            ++i;
            if(i == n)
            {
                Node* node = s.top();
                data = node->data;
                break;
            }
            s.pop();
        }
    }

    return data;

}