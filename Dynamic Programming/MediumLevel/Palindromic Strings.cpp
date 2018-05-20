/*
https://practice.geeksforgeeks.org/problems/palindromic-strings/0
Palindromic Strings 

Given a string you have to transform it into a palindrome . In order to acheive that you have to perform exactly 
k insertion of characters(you cannot perform any more or less number of insertions).
Now you have to report whether the string can be converted to a palindrome by making exactly k insertions.
 
Input :
The first line contains the number of test cases T. For each test case the first line 
contains the length of the string N and the number of insertions k. The second line contains the string S.
 
Output :
For each test case, print "YES"(without quotes) if the string can be converted to 
a palindrome making exactly k insertions otherwise "NO"(without quotes).
 
Constraints :
1 ≤ T ≤ 100
0<=k<=100000
The string consists of only lower case English Alphabets (a-z).
 
Example:
Input : 
2
4 2
abac
5 3
abcde

Output :
YES
NO
 
Explanation : 

For the first test case abac can be transformed to cabbac (which is palindrome) adding two characters c and b.
For the second test case abcde cannot be transformed to palindrome using 3 insertions.
For the third test case ab can be transformed to cabac (which is palindrome) adding three characters a, c and c.


*/