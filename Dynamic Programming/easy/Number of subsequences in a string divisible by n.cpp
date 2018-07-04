/*
Number of subsequences in a string divisible by n 
https://practice.geeksforgeeks.org/problems/number-of-subsequences-in-a-string-divisible-by-n/0
https://www.geeksforgeeks.org/number-subsequences-string-divisible-n/

Given a string consisting of digits 0-9, count the number of subsequences in it divisible by n.

 
Input:

The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. 
The first line of each test case contains an integer M and N where M denotes the length of the numeric string.

The second line of each test case contains the numeric string.


Output:

Output the number of subsequences dicisible by N. Since the number can be quite large print the answer modulo 10^9+7.


Constraints:

1<= T <=100

1<= M <=1000

1<= N <=1000


Example:

Input:

2

4 4

1234

3 6

330

Output:

4

4

*/

/*

This problem can be recursively defined. Let remainder of a string with value x be ‘r’ when divided with n. 
Adding one more character to this string changes its remainder to (r*10 + newdigit) % n. 
For every new character, we have two choices, either add it in all current subsequences or ignore it. 
Thus, we have an optimal substructure. Following shows the brute force version of this.


C[N] = C[N-1][nth selected] + C[N-1][nth not selected]
C[N][reminder]

*/