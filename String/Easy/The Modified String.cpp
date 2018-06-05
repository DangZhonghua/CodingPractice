/*
The Modified String 
https://practice.geeksforgeeks.org/problems/the-modified-string/0/?ref=self
Ishaan is playing with strings these days. He has found a new string. He wants to modify it as per the following rule :
The string should not have three consecutive same characters (Refer example for explanation).
He can add any number of characters anywhere in the string. Find the minimum number of characters which Ishaan must insert in the string.

Input : 
First line of input contains a single integer T denoting the number of test cases.
The only line of each test case contains a string S consisting of lowercase English Alphabets.

Output : 
For each test case, print the required answer in a new line.

Constraints : 
1 <= T <= 100
1 <= Length of S <= 1000

Example : 
Input : 
3
aabbbcc
aaaaa
abcddee
Output : 
1
2
0

Explanation : 
Case 1 : 
aabbbcc
3 b's occur consecutively, we add a 'd',
aabbdbcc

Case 2 : 
aaaaa
5 a's occur consecutively, we need to add 2 'b',
aababaa

Case 3 : 
abcddee
No character occurs 3 times, so no need to add anything.


*/