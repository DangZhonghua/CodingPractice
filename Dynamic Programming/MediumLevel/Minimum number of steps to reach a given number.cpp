/*
Minimum number of steps to reach a given number
https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number/0

Given a number line from -infinity to +infinity. You start at 0 and can go either to the left or to the right. 
The condition is that in i’th move, you take i steps. You are given a Destination , 
you have to print the minimum number of steps required to reach that destination.

Input:
The first line of the input contains the number of test cases T, 
then T lines follow and each lines contains an integer D specifying the destination.


Output:
Corresponding to each test case print in a new line the minimum number of steps required to reach that destination.

Constraints:
1<=T<=100
0<=D<=1000

Example:
Input:
2
2
10

Output:
3
4

Explanation:

In the first test case we can go from 0 to 1 (1 step) and then from 1 to -1 (2 steps) and 
then from -1 to 2 (3 steps). So in 3 steps we have reached our destination by taking i steps in ith turn.

*/