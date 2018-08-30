/*
Stack using two queues 
https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1

Implement a Stack using 2 queue q1 and q2 .

Input (To be used for Expected Output):

The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries . 
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the stack)
(ii) 2     (a query of this type means to pop element from stack and print the poped element)

The second line of each test case contains Q queries seperated by space.

Output:
The output for each test case will  be space separated integers having -1 if the stack is empty else the element poped out from the stack . 
You are required to complete the two methods push which take one argument an integer 'x' to be pushed into the stack  and pop which returns a integer poped out from the stack.

Constraints:
1<=T<=100
1<=Q<=100
1<=x<=100

Example:
Input
1
5
1 2 1 3 2 1 4 2   

Output
3 4

Explanation:

In the first test case for query 
1 2    the stack will be {2}
1 3    the stack will be {2 3}
2       poped element will be 3 the stack will be {2}
1 4    the stack will be {2 4}
2       poped element will be 4  


*/

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */
/* The method push to push element into the stack */
void QueueStack::push(int x)
{
	// Your Code
	q1.push(x);

}
/*The method pop which return the element poped out of the stack*/
int QueueStack::pop()
{
	// Your Code

	int x = -1;

	if (q1.empty())
	{
		while (q2.size()>1)
		{
			q1.push(q2.front());
			q2.pop();
		}
		if (!q2.empty())
		{
			x = q2.front();
			q2.pop();
		}
	}
	else
	{
		while (q1.size() > 1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		if (!q1.empty())
		{
			x = q1.front();
			q1.pop();
		}
	}
	return x;
}