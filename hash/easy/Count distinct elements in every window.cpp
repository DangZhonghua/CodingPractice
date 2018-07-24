/*
https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
https://www.geeksforgeeks.org/count-distinct-elements-in-every-window-of-size-k/bbbbbbbbb
Count distinct elements in every window
Given an array A[] of size n and an integer k, your task is to complete the function countDistinct which prints the count of distinct numbers in all windows of size k in the array A[].

Example

Input:  A[] = {1, 2, 1, 3, 4, 2, 3};
            k = 4
Output:
3 4 4 3
Explanation:
First window is {1, 2, 1, 3}, count of distinct numbers is 3
Second window is {2, 1, 3, 4} count of distinct numbers is 4
Third window is {1, 3, 4, 2} count of distinct numbers is 4
Fourth window is {3, 4, 2, 3} count of distinct numbers is 3



Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two integers n and k. Then in the next line are N space separated values of the array A[].

Output:
For each test case in a new line print the space separated values denoting counts of distinct numbers in all windows of size k in the array A[].

Constraints:
1<=T<=100
1<=n,k<=100
1<=A[]<=100

Example(To be used only for expected output):
Input:
2
7 4
1 2 1 3 4 2 3
3 2
4 1 1               .
Output:
3 4 4 3
2 1


*/