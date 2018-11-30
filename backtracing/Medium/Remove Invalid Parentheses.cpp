/*
Remove Invalid Parentheses
https://www.geeksforgeeks.org/remove-invalid-parentheses/

An expression will be given which can contain open and close parentheses and optionally some characters, 
No other operator will be there in string. We need to remove minimum number of parentheses to make the input string valid. 
If more than one valid output are possible removing same number of parentheses then print all such output.
Examples:

Input  : str = “()())()” -
Output : ()()() (())()
There are two possible solutions
"()()()" and "(())()"

Input  : str = (v)())()
Output : (v)()()  (v())()

*/

/*
Are there: optimal substructure and overlapped problems?
Seems there are no substructure: from prefix or postfix  or range

What is the difference between DP and BT

*/