/*
https://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced/
Minimum number of bracket reversals needed to make an expression balanced
Given an expression with only ‘}’ and ‘{‘. The expression may not be balanced. 
Find minimum number of bracket reversals to make the expression balanced.

Examples:

Input:  exp = "}{"
Output: 2
We need to change '}' to '{' and '{' to
'}' so that the expression becomes balanced, 
the balanced expression is '{}'

Input:  exp = "{{{"
Output: Can't be made balanced using reversals

Input:  exp = "{{{{"
Output: 2 

Input:  exp = "{{{{}}"
Output: 1 

Input:  exp = "}{{}}{{{"
Output: 3



*/