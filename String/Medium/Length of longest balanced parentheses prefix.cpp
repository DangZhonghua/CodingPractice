/*
https://www.geeksforgeeks.org/length-longest-balanced-parentheses-prefix/
Length of longest balanced parentheses prefix

Given a string of open bracket ‘(‘ and closed bracket ‘)’. The task is to find the length of longest balanced prefix.

Examples:

Input : S = "((()())())((" 
Output : 10
From index 0 to index 9, they are forming 
a balanced parentheses prefix.

Input : S = "()(())((()"
Output : 6


*/

/*
find parenthesis range, then concatenation if possbile: if previous range is continuous

*/

#include<iostream>
#include<stack>
#include<string>

using namespace std;


