/*
https://www.geeksforgeeks.org/longest-possible-chunked-palindrome/
Longest Possible Chunked Palindrome

Given a string, the task is to return the length of its longest possible chunked palindrome. 
It means a palindrome formed by substring in the case when it is not formed by characters of the string. 
For better understanding look at the example

Examples:

Input : ghiabcdefhelloadamhelloabcdefghi 
Output : 7
(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)

Input : merchant
Output : 1
(merchant)

Input : antaprezatepzapreanta
Output : 11
(a)(nt)(a)(pre)(za)(tpe)(za)(pre)(a)(nt)(a)

Input : geeksforgeeks
Output : 3
(geeks)(for)(geeks)

*/

/*
this can be solved by greedy algorithm since DP is too complicated.
this problem has greedy choice property.

LPS[i,j] = LPS[i+k, j-k] + 1, the prefix and postfix which the length K is block palindrome.

else increase the k and try again.
the greedy choice is with the minimum k, the chunked palindrome is longest. So greedy algorithm can slove this problem.
*/