/*
Largest Sum Contiguous Subarray
https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

Given an array containing both negative and positive integers. Find the contiguous sub-array with maximum sum.
 
Input:
The first line of input contains an integer T denoting the number of test cases. 
The description of T test cases follows. The first line of each test case contains a single 
integer N denoting the size of array. 
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
 
Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.
 
Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 1000
-100 ≤ A[i] <= 100
 
Example:
Input
2
3
1 2 3
4
-1 -2 -3 -4
Output
6
-1


*/


/*

Simple idea of the Kadane’s algorithm is to look for all positive contiguous segments of the array 
(max_ending_here is used for this). And keep track of maximum sum 
 segment among all positive segments (max_so_far is used for this). 
Each time we get a positive sum compare it with max_so_far and update max_so_far 
if it is greater than max_so_far

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int largestSumSubarray(vector<int>& a)
{
    int max_so_far = a[0];
    int max_ending_here = a[0];
    for(int i = 1; i< a.size();++i)
    {
        if(max_ending_here >0)
        {
            max_ending_here += a[i];
        }
        else
        {
            max_ending_here = a[i];
        }

        if(max_ending_here>max_so_far)
        {
            max_so_far = max_ending_here;    
        }
    }

    cout<<max_so_far<<endl;

   return 0;
}

int main()
{
    int t = 0;
    int N = 0;
    
    cin>>t;
    
    while(t--)
    {
        cin>>N;
        vector<int> a(N,0);
        int i = 0;
        while(i<N)
        {
            int d = 0;
            cin>>d;
            a[i++] = d;
        }
        largestSumSubarray(a);
    }
    return 0;
}