/*
https://practice.geeksforgeeks.org/problems/geek-collects-the-balls/0

There are two parallel roads, each containing N and M buckets, respectively. Each bucket may contain some balls. The buckets n both roads are kept in such a way that they are sorted according to the number of balls in them. Geek starts from the end of the road which has the bucket with lower number of balls(i.e. if buckets are sorted in increasing order, then geek will start from the left side of road).
The geek can change the road only at the point of intersection(whichmeans , buckets with the same number of balls on two roads). Now you need to help Geek to collect the maximum number of balls.

Input:
First line of input contains T denoting number of test cases. First line of each test case contains two integers N and M, denoting the number of buckets on road1 and road2 respectively. 2nd line of each test case contains N integers, number of balls in buckets on first road. 3rd line of each test case contains M integers, number of balls in buckets on second road.

Output:
For each test case output a single line containing the maximum possible balls that Geek can collect.

Constraints:
1<= T <= 1000
1<= N <= 103
1<= M <=103
0<= Ai,Bi <=109

Example:
Input:
1
5 5
1 4 5 6 8
2 3 4 6 9

Output:
29

Explanation:

The path with maximum sum is (2,3,4)[5,6](9). Integers in [] are the buckets of first road and in () are the buckets of second road. 
So, max balls geek can collect is 29.


*/