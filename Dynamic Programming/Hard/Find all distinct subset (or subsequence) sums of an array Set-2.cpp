/*
https://www.geeksforgeeks.org/find-all-distinct-subset-or-subsequence-sums-of-an-array-set-2/
Find all distinct subset (or subsequence) sums of an array | Set-2

Given an array of N positive integers write an efficient function to find the sum of all those integers 
which can be expressed as the sum of at least one subset of the given array i.e. 
calculate total sum of each subset whose sum is distinct using only O(sum) extra space.

Examples:

    Input: arr[] = {1, 2, 3}
    Output: 0 1 2 3 4 5 6
    Distinct subsets of given set are {}, {1}, {2}, {3}, {1, 2}, {2, 3}, {1, 3} and {1, 2, 3}. 
    Sums of these subsets are 0, 1, 2, 3, 3, 5, 4, 6. After removing duplicates, we get 0, 1, 2, 3, 4, 5, 6

    Input: arr[] = {2, 3, 4, 5, 6}
    Output: 0 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 20

    Input: arr[] = {20, 30, 50}
    Output: 0 20 30 50 70 80 100 

*/