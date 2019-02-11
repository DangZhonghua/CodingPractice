/*
https://www.geeksforgeeks.org/maximum-sum-lengths-non-overlapping-subarrays-k-max-element/
Maximum sum of lengths of non-overlapping subarrays with k as the max element.

Find the maximum sum of lengths of non-overlapping subarrays (contiguous elements) with k as the maximum element.
Examples:

 
Input : arr[] = {2, 1, 4, 9, 2, 3, 8, 3, 4} 
        k = 4
Output : 5
{2, 1, 4} => Length = 3
{3, 4} => Length = 2
So, 3 + 2 = 5 is the answer

Input : arr[] = {1, 2, 3, 2, 3, 4, 1} 
        k = 4
Output : 7
{1, 2, 3, 2, 3, 4, 1} => Length = 7

Input : arr = {4, 5, 7, 1, 2, 9, 8, 4, 3, 1}
        k = 4
Ans = 4
{4} => Length = 1
{4, 3, 1} => Length = 3
So, 1 + 3 = 4 is the answer



*/