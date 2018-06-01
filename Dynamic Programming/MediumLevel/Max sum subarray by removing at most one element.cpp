/*
Max sum subarray by removing at most one element
https://practice.geeksforgeeks.org/problems/max-sum-subarray-by-removing-at-most-one-element/1

Given an array, the task is to complete the function which  finds the maximum sum subarray, 
where you may remove atmost one element to get the maximum sum.

Examples:

Input  : A[] = {1, 2, 3, -4, 5}
Output : 11
Explanation : We can get maximum sum subarray by
removing -4.

Input  : A[] = [-2, -3, 4, -1, -2, 1, 5, -3]
Output : 9
Explanation : We can get maximum sum subarray by
removing -2 as, [4, -1, 1, 5] summing 9, which is 
the maximum achievable sum.


Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
For each test case in a new line output will be the maximum sum subarray.

Constraints:
1<=T<=100
1<=N<=100
-1000<=A[]<=1000

Example(To be used only for expected output):
Input:
2
5
1 2 3 -4 5
8
-2 -3 4 -1 -2 1 5 -3

Output:
11
9
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int CalcMaxsumofSubArray(int*a, int N)
{
    int max = INT_MIN;
    vector< vector<int> > m(N+1, vector<int>(N+1, 0));
    for(int i = 0; i<N; ++i)
    {
        m[i][i] = a[i];
        if(max<a[i])
        {
            max = a[i];
        }
    }

    for(int l = 2; l<=N; ++l)
    {
        for(int i = 0; i<=N-l; ++i)
        {
            int j = i+l-1;
            m[i][j] = (a[i] + m[i+1][j]);
            if(max<m[i][j])
            {
                max = m[i][j];
            }
            for(int k = i; k<=j; ++k)
            {
              if( ( m[i][j]-a[k] )> max)
              {
                  max = ( m[i][j]-a[k] );
              }
            }
        }
    }

    cout<<max<<endl;
    return 0;
}



int main(int argc, char const *argv[])
{   
    int t = 0;
    int N = 0;
    int a[101];

    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        CalcMaxsumofSubArray(a,N);        
    }


    return 0;
}
