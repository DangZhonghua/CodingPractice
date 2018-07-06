/*
High-effort vs. Low-effort
https://practice.geeksforgeeks.org/problems/high-effort-vs-low-effort/0/?ref=self

You are given n days and for each day (di) you could either perform a high effort tasks (hi) or a low effort tasks (li) or no task with the constraint that you can choose a high-effort tasks only if you chose no task on the previous day. Write a program to find the maximum amount of tasks you can perform within these n days.

Input:

 

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the number of days

The second line of each test case contains N space separated integers denoting elements of the array hi[ ].

The third line of each test case contrains N space separated integers denoting elements of the array li[ ].


Output:

Print the maximum amount of task that can be performed under the given constraint for each test case in a new line.


Constraints:

1<= T <=100

1<= N <=100000

1<= li[ ]


Example:

Input:

1

5

3 6 8 7 6

1 5 4 5 3

Output:

20

*/