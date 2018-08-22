/*
https://www.geeksforgeeks.org/count-unique-subsequences-of-length-k/
Count unique subsequences of length K

Given an array of N numbers and an integer K. The task is to print the number of unique subsequences possible of length K.

Examples:

Input : a[] = {1, 2, 3, 4}, k = 3 
Output : 4. 
Unique Subsequences are: 
{1, 2, 3}, {1, 2, 4}, {1, 3, 4}, {2, 3, 4}

Input: a[] = {1, 1, 1, 2, 2, 2 }, k = 3
Output : 4 
Unique Subsequences are 
{1, 1, 1}, {1, 1, 2}, {1, 2, 2}, {2, 2, 2} 

Recommended: Please try your approach on {IDE} first, before moving on to the solution.

Approach: There is a well-known formula how many subsequences of fixed length K can be chosen from N unique objects. 
But the problem here has several differences. One among them is the order 
in subsequences is important and must be preserved as in the original sequence. 
For such a problem there can be no ready combinatorics formula 
because the results depend on the order of the original array.
The main idea is to deal recurrently by the length of the subsequence. 
On each recurrent step, move from the end to the beginning and count the unique combinations 
using the count of shorter unique combinations from the previous step. 
More strictly on every step j we keep an array of length N and every element 
in the place p means how many unique subsequences with length j 
we found to the right of the element in place i, including i itself.

*/