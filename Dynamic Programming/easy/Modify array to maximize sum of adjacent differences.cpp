/*
Modify array to maximize sum of adjacent differences 
https://practice.geeksforgeeks.org/problems/modify-array-to-maximize-sum-of-adjacent-differences/0
https://www.geeksforgeeks.org/modify-array-to-maximize-sum-of-adjacent-differences/

Given an array, we need to modify values of this array in such a way that sum of absolute differences 
between two consecutive elements is maximized. 
If the value of an array element is X, then we can change it to either 1 or X.


Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains an integer N denoting the size of the array A.
The second line of each test case contains N space separated integers denoting elements of the array A[ ].


Output:
Print the maximum sum of adjacent differences after modifying the array for each test case in a new line.


Constraints:
1<= T <=100
1<= N <=100000
1<= A[ ] <=100000

Example:

Input:

1

5

3 2 1 4 5

Output:

8

Explanation:

Modified array: 3 1 1 4 1

ans = | 1 - 3 | + | 1 - 1 | + | 4 - 1 | + | 1 - 4 | = 8
*/