/*
https://www.geeksforgeeks.org/sequence-alignment-problem/
Sequence Alignment problem


Sequence Alignment problem
Given as an input two strings, X = x_{1} x_{2}... x_{m}, and Y = y_{1} y_{2}... y_{m}, 
output the alignment of the strings, character by character, 
so that the net penalty is minimised. The penalty is calculated as:
1. A penalty of p_{gap} occurs if a gap is inserted between the string.
2. A penalty of p_{xy} occurs for mis-matching the characters of X and Y.

Examples:

Input : X = CG, Y = CA, p_gap = 3, p_xy = 7
Output : X = CG_, Y = C_A, Total penalty = 6

Input : X = AGGGCT, Y = AGGCA, p_gap = 3, p_xy = 2
Output : X = AGGGCT, Y = A_GGCA, Total penalty = 5

Input : X = CG, Y = CA, p_gap = 3, p_xy = 5
Output : X = CG, Y = CA, Total penalty = 5

*/