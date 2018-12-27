/*
Number of subsets with sum divisible by m
https://www.geeksforgeeks.org/number-of-subsets-with-sum-divisible-by-m/

Given an array of integers, find number of subsequence such that the sum of the subsequence is divisible by m. 
It is given that sum of array elements is small.
Examples:

Input : arr[] = {1, 2, 3};
        m = 3;
Output : 3
Subsequence of given set are
{1}, {2}, {3}, {1, 2}, {2, 3}, {1, 3} and {1, 2, 3}. 
And their sums are 1, 2, 3, 3, 5, 4 and 6.

Input : arr[] = {1, 2, 3, 4};
        m = 2;
Output : 7
{2}, {4}, {1, 3}, {2, 4}, {1, 2, 3}, {1, 3, 4} 
and {1, 2, 3, 4}



*/