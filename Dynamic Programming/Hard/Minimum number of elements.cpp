/*
Minimum number of elements
https://practice.geeksforgeeks.org/problems/minimum-number-of-elements-which-are-not-part-of-increasing-or-decreasing-subsequence/0
https://www.geeksforgeeks.org/minimum-number-of-elements-which-are-not-part-of-increasing-or-decreasing-subsequence-in-array/


Given an array of n elements. Make strictly increasing and strictly decreasing subsequences 
from the array such that each array element belongs to increasing subsequence or 
decreasing subsequence, but not both, or can be part of none of the subsequence. 
Minimize the number of elements which are not part of any of the subsequences and find the count of such elements.

Input:
First line consists of T test cases. First line of every test case consists of N, 
denoting the number of elements of array. Second line of every test case consists of elements of array.

Output:
Single line output i.e minimum number of element which is not part of increasing or decreasing subsequence in the array.

Constraints:
1<=T<=100
1<= N <=100
1 <= arr[i] <= 100

Example:
Input :
1
12
 7 8 1 2 4 6 3 5 2 1 8 7
Output :
2

Explanation:
Increasing sequence can be { 1, 2, 4, 5, 8 }. Decreasing sequence can be { 7, 6, 3, 2, 1 }. 
So, only 2 (8, 7) element is left which are not part of either of the subsequences.


*/