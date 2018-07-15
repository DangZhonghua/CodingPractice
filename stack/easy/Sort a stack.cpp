/*
Sort a stack 
https://practice.geeksforgeeks.org/problems/sort-a-stack/1

https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/

Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Input:
The first line of input will contains an integer T denoting the no of test cases . 
Then T test cases follow. Each test case contains an integer N denoting the size of the stack. 
Then in the next line are N space separated values which are pushed to the the stack. 

Output:
For each test case output will be the popped elements from the sorted stack.

Constraints:
1<=T<=100
1<=N<=100

Example(To be used only for expected output):
Input:
2
3
3 2 1
5
11 2 32 3 41

Output:
3 2 1
41 32 11 3 2

Explanation:
For first test case stack will be
1
2
3
After sorting 
3
2 
1

When elements  popped : 3 2 1


*/

//Sort a stack using a temporary stack


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
/* The below method sorts the stack s 
you are required to complete the below method */

#include<stack>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void SortedStack :: sort()
{
   //Your code here
    stack<int> ts;

    while(!s.empty())
    {
        int t = s.top();
        s.pop();
        // let small value, push into ts first: util find the proper postiion.
        while(!ts.empty())
        {
            int tt = ts.top();
            if(tt>t)
            {
                ts.pop();
                s.push(tt);
            }
            else
            {
                break;
            }
        }
        ts.push(t);
    }

    s = ts;
}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
