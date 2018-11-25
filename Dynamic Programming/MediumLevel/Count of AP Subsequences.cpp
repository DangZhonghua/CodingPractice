/*
https://practice.geeksforgeeks.org/problems/count-of-ap-subsequences/0
https://www.geeksforgeeks.org/count-arithmetic-progression-subsequences-array/

Count of AP Subsequences 
Given an array A[] of n positive integers. The task is to count the number of Arithmetic Progression subsequence in the array.

Note: Empty sequence or single element sequence is Arithmetic Progression. 

Examples:

Input : A[] = { 1, 2, 3 }
Output : 8
Arithmetic Progression subsequence from the 
given array are: {}, { 1 }, { 2 }, { 3 }, { 1, 2 },
{ 2, 3 }, { 1, 3 }, { 1, 2, 3 }.

Input : A[] = { 10, 20, 30, 45 }
Output : 12

Input : A[] = { 1, 2, 3, 4, 5 }
Output : 23

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer n denoting size of the array. Then in the next line are n space separated values of the array.

Output:
For each test case in a new line print the required output.

Constraints:
1<=T<=100
1<=n<=100
1<=A[]<=100

Example:
Input:
2
3
1 2 3
4
10 20 30 45
Output:
8
12

*/

/*

AP[i][d] = AP[i][d] + 1 if a[j]-a[i]==d if j>i

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int CountAP(vector<int>&a)
{
    long long count = 1; // 1 for empty set
    int d = 0;
    std::sort(a.begin(),a.end());
    d = (*(a.rbegin())) - (*(a.begin()));
    vector< vector<int> > AP(a.size(), vector<int>(d+1,-1));
    
    //For length == 2 AP.
    for(int i = 0; i<a.size(); ++i)
    {
        for(int j = 0; j<=i; ++j)
        {
            d = a[i]-a[j];
            
        }
    }
    
    return 0;
}
