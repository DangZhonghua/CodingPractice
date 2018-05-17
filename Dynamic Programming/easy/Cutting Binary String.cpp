/*
Cutting Binary String
https://practice.geeksforgeeks.org/problems/cutting-binary-string/0

Given a string s containing 0's and 1's. You have to return a smallest positive integer C, such that the binary string can be cut into C pieces and each piece should be of the power of 5  with no leading zeros.

Input:
The first line of the input contains T denoting the number of test cases. For each test case, there is a string s.

Output:
For each test case, the output is an integer C. If no such cuts are possible then return -1. 

Constraints:
1<=s.length()<=50
Note: The string s is a binary string.

Example:
Input
3
101101101
1111101
00000
Output:
3
1
-1

Explanation:
1.We can split the given string into three “101”s, where 101 is the binary representation of 5.
2."1111101 " is 125 which is 5^3.
3.0 is not a power of 5.


*/