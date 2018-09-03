/*
https://www.geeksforgeeks.org/find-ith-index-character-in-a-binary-string-obtained-after-n-iterations-set-2/

Find i’th index character in a binary string obtained after n iterations | Set 2

Given a decimal number m, convert it into a binary string and apply n iterations, in each iteration 0 becomes “01” and 1 becomes “10”. Find ith(based indexing) index character in the string after nth iteration.

Examples:

Input: m = 5 i = 5 n = 3
Output: 1
Explanation
In the first case m = 5, i = 5, n = 3. 
Initially, the string is  101  ( binary equivalent of 5 )
After 1st iteration -   100110
After 2nd iteration - 100101101001
After 3rd iteration -   100101100110100110010110 
The character at index 5 is 1, so 1 is the answer

Input: m = 11 i = 6 n = 4
Output: 1

*/