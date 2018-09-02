/*
https://www.geeksforgeeks.org/sudo-placement-placement-tour/
Sudo Placement | Placement Tour
Given an array A of N positive integers and a budget B. 
Your task is to decide the maximum number of elements to be picked from the array such that 
the cumulative cost of all picked elements is less than or equal to budget B. 
Cost of picking the ith element is given by : A[i] + (i * K) 
where, K is a constant whose value is equal to the number of elements picked. 
The indexing(i) is 1 based. Print the maximum number and its respective cumulative cost.

Examples:

    Input : arr[] = { 2, 3, 5 }, B = 11
    Output : 2 11
    Explanation : Cost of picking maximum elements = {2 + (1 * 2) } + {3 + (2 * 2)} = 4 + 7 = 11 (which is equal to budget)

    Input : arr[] = { 1, 2, 5, 6, 3 }, B = 90
    Output : 4 54 

*/

/*
Binary search to decide the k value:
Approach: The idea here is to use binary search on all possible values of K 
i.e. the optimal number of elements to be picked. 
Start with zero as lower bound and End with total number of elements 
i.e. N as upper bound. Check if by setting K as current Mid, 
obtained cumulative cost is less than or equal to budget. 
If it satisfies the condition, then try to increase K by setting Start as (Mid + 1), 
otherwise try to decrease K by setting End as (Mid – 1).
Checking of the condition can be done in a brute force manner 
by simply modifying the array according to the given formula 
and adding the K (current number of elements to be picked) smallest modified values to get the cumulative cost.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int checkBuget(vector<int>&a, int K, int B, int& value)
{
    vector<int> bv(a.size(),0);
    for(int i = 0; i<a.size(); ++i)
    {
        bv[i] = a[i] + (i+1)*K;
    }
    std::sort(bv.begin(), bv.end());
    value = 0;
    for(int i = 0; i<K; ++i)
    {
        value += bv[i];
    }
    return 0;
}

int findMaximumLength(vector<int>a, int B)
{
    int M = a.size()-1;
    
    

    return 0;
}
