/*
https://www.geeksforgeeks.org/length-largest-subarray-contiguous-elements-set-1/
https://www.geeksforgeeks.org/length-largest-subarray-contiguous-elements-set-2/
Length of the largest subarray with contiguous elements

Given an array of distinct integers, find length of the longest subarray which contains numbers 
that can be arranged in a continuous sequence. 
Examples: 
Input:  arr[] = {10, 12, 11};
Output: Length of the longest contiguous subarray is 3

Input:  arr[] = {14, 12, 11, 20};
Output: Length of the longest contiguous subarray is 2

Input:  arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
Output: Length of the longest contiguous subarray is 5

Given an array of integers, find length of the longest subarray which contains numbers that can be arranged in a continuous sequence. 
In the previous post, we have discussed a solution that assumes that elements in given array are distinct. 
Here we discuss a solution that works even if the input array has duplicates.
Examples: 
Input:  arr[] = {10, 12, 11};
Output: Length of the longest contiguous subarray is 3

Input:  arr[] = {10, 12, 12, 10, 10, 11, 10};
Output: Length of the longest contiguous subarray is 2

*/