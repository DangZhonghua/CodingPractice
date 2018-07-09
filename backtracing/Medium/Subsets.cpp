/*
Subsets 
https://practice.geeksforgeeks.org/problems/subsets/0

Given an array of integers that might contain duplicates, return all possible subsets.

Note Output:

        Elements in a subset must be in non-descending order.
        The solution set must not contain duplicate subsets.
        The subsets must be sorted lexicographically.

Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]

Input:
First is T , no of test cases. 1<=T<=500
Every test case has two lines.
First line is N, size of array. 1<=N<=12
Second line contains N space seperated integers(x). 1<=x<=9.

Output:
One line per test case, every subset enclosed in () and in every set intergers should be space seperated.(See example)

Example:
Input:
2
3
1 2 2
4
1 2 3 3

Output:
()(1)(1 2)(1 2 2)(2)(2 2)
()(1)(1 2)(1 2 3)(1 2 3 3)(1 3)(1 3 3)(2)(2 3)(2 3 3)(3)(3 3)

 


*/