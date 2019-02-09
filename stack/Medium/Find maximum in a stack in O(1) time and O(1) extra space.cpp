/*
https://www.geeksforgeeks.org/find-maximum-in-a-stack-in-o1-time-and-o1-extra-space/
Find maximum in a stack in O(1) time and O(1) extra space

Given a stack of integers. The task is to design a special stack such that maximum element can be found in O(1) time and O(1) extra space.

Examples:

Given Stack :
2
5
1
64   --> Maximum

So Output must be 64 when getMax() is called.

Below are the different functions designed to push and pop elements from the stack.
Push(x) : Inserts x at the top of stack.

    If stack is empty, insert x into the stack and make maxEle equal to x.
    If stack is not empty, compare x with maxEle. Two cases arise:
        If x is less than or equal to maxEle, simply insert x.
        If x is greater than maxEle, insert (2*x – maxEle) into the stack and make maxEle equal to x. 
        For example, let previous maxEle was 3. Now we want to insert 4. We update maxEle as 4 and insert 2*4 – 3 = 5 into the stack.

Pop() : Removes an element from top of stack.

    Remove element from top. Let the removed element be y. Two cases arise:
        If y is less than or equal to maxEle, the maximum element in the stack is still maxEle.
        If y is greater than maxEle, the maximum element now becomes (2*maxEle – y), so update (maxEle = 2*maxEle – y). This is where we retrieve previous maximum from current maximum and its value in stack. For example, let the element to be removed be 5 and maxEle be 4. We remove 5 and update maxEle as 2*4 – 5 = 3.


    Stack doesn’t hold actual value of an element if it is maximum so far.
    Actual maximum element is always stored in maxEle


*/