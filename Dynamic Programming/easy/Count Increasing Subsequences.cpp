/*
Count Increasing Subsequences 

https://practice.geeksforgeeks.org/problems/two-repeated-elements/0/?ref=self
https://www.geeksforgeeks.org/count-all-increasing-subsequences/


Given an array of digits (values lie in range from 0 to 9). The task is to count all the sub sequences possible in array such that in each subsequence every digit is greater than its previous digits in the subsequence.

Examples:

Input : arr[] = {1, 2, 3, 4}
Output: 15
There are total increasing subsequences
{1}, {2}, {3}, {4}, {1,2}, {1,3}, {1,4}, 
{2,3}, {2,4}, {3,4}, {1,2,3}, {1,2,4}, 
{1,3,4}, {2,3,4}, {1,2,3,4}

Input : arr[] = {4, 3, 6, 5}
Output: 8
Sub-sequences are {4}, {3}, {6}, {5}, 
{4,6}, {4,5}, {3,6}, {3,5}

Input : arr[] = {3, 2, 4, 5, 4}
Output : 14
Sub-sequences are {3}, {2}, {4}, {3,4},
{2,4}, {5}, {3,5}, {2,5}, {4,5}, {3,2,5}
{3,4,5}, {4}, {3,4}, {2,4}

Input:

The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the number of digits.
The second line contains N space-separated digits.

Output:

Count of all increasing subsequences in given array of digits.

Constraints: 

1 ≤ T ≤ 30
1 ≤ N ≤ 500

Example: 

Input:
2
5
3 2 4 5 4
3
1 2 4
Output:
14
7 
*/

/*
this problem likes LIS. But only 0...9 ten number, so there is more optimal LIS
*/

#include<iostream>
using namespace std;

int CLIS(int*a, int N)
{
    long long count[10] = {0};
    long long c = 0;
    for(int i = 0; i<N; ++i)
    {
        for(int j = a[i]-1; j>=0; --j)
        {
            count[a[i]] += count[j];
        }
        ++count[a[i]];
    }

    for(int i = 0; i< 10; ++i)
    {
        c += count[i];
    }
    
    cout<<c<<endl;

    return 0;
}

int main()
{
    int t = 0;
    int N = 0;
    int a[500];

    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        CLIS(a,N);        
    }

    return 0;
}