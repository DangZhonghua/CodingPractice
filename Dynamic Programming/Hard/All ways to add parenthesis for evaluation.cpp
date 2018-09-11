/*
All ways to add parenthesis for evaluation
https://www.geeksforgeeks.org/all-ways-to-add-parenthesis-for-evaluation/

Given a string that represents an expression constituting numbers and binary operator +, – and * only. We need to parenthesize the expression in all possible way and return all evaluated values.

Input : expr = “3-2-1”
Output : {0, 2}
((3-2)-1) = 0 
(3-(2-1)) = 2

Input : expr = "5*4-3*2"
Output : {-10, 10, 14, 10, 34}
(5*(4-(3*2))) = -10
(5*((4-3)*2)) = 10
((5*4)-(3*2)) = 14
((5*(4-3))*2) = 10
(((5*4)-3)*2) = 34


*/