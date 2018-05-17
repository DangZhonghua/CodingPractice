/*
Water Connection Problem
https://practice.geeksforgeeks.org/problems/water-connection-problem/0

Every house in the colony has at most one pipe going into it and at most one pipe going out of it. Tanks and taps are to be installed in a manner such that every house with one outgoing pipe but no incoming pipe gets a tank installed on its roof and every house with only an incoming pipe and no outgoing pipe gets a tap. Find the efficient way for the construction of the network of pipes.

Input:
The first line contains an integer T denoting the number of test cases. For each test case, the first line contains two integer n & p denoting the number of houses and number of pipes respectively. Next, p lines contain 3 integer inputs a, b & d, d denoting the diameter of the pipe from the house a to house b.  

Output:
For each test case, the output is the number of pairs of tanks and taps installed i.e n followed by n lines that contain three integers: house number of tank, house number of tap and the minimum diameter of pipe between them.  

Constraints:
1<=T<=50
1<=n<=20
1<=p<=50
1<=a,b<=20
1<=d<=100

Example:
Input:
1
9 6
7 4 98
5 9 72
4 6 10
2 8 22
9 7 17
3 1 66
Output:
3
2 8 22
3 1 66
5 6 10

Explanation:
Connected components are 3->1, 5->9->7->4->6 and 2->8.
Therefore, our answer is 3 followed by 2 8 22, 3 1 66, 5 6 10.

*/