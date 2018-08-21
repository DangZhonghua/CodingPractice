/*
https://www.geeksforgeeks.org/sudo-placement-placement-tour/
Sudo Placement | Placement Tour
Given an array A of N positive integers and a budget B. Your task is to decide the maximum number of elements to be picked from the array such that the cumulative cost of all picked elements is less than or equal to budget B. Cost of picking the ith element is given by : A[i] + (i * K) where, K is a constant whose value is equal to the number of elements picked. The indexing(i) is 1 based. Print the maximum number and its respective cumulative cost.

Examples:

    Input : arr[] = { 2, 3, 5 }, B = 11
    Output : 2 11
    Explanation : Cost of picking maximum elements = {2 + (1 * 2) } + {3 + (2 * 2)} = 4 + 7 = 11 (which is equal to budget)

    Input : arr[] = { 1, 2, 5, 6, 3 }, B = 90
    Output : 4 54 

*/