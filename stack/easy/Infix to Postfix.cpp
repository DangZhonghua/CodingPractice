/*

Infix to Postfix 
https://practice.geeksforgeeks.org/problems/infix-to-postfix/0
Given an infix expression. Conver the infix expression to postfix expression.

Infix expression:The expression of the form a op b. When an operator is in-between every pair of operands.

Postfix expression:The expression of the form a b op. When an operator is followed for every pair of operands.

Input:

The first line of input contains an integer T denoting the number of test cases.
The next T lines contains an infix expression.The expression contains all characters and ^,*,/,+,-.

Output:
Output the infix expression to postfix expression.

Constraints:
1<=T<=100
1<=length of expression<=30

Example:
Input:
2
a+b*(c^d-e)^(f+g*h)-i
A*(B+C)/D

Output:
abcd^e-fgh*+^*+i-
ABC+*D/


*/