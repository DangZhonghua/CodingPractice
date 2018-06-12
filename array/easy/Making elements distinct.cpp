/*
Making elements distinct
https://practice.geeksforgeeks.org/problems/making-elements-distinct/0/?ref=self

Given a sorted integer array. We need to make array elements distinct by increasing values and keeping array sum minimum possible. We need to print the minimum possible sum as output.

Input:
The first line of the input contains a single integer T denoting the number of test cases. The first line of each test case contains N. followed by N separate integers. 

Output:
For each test caseprint the minimum possible sum.

Constraints:
1 ≤ T ≤ 100
2 ≤ N ≤ 10^4
1 ≤ A[i] ≤ 10^3

Example:
Input:
2
5
2 2 3 5 6
2
20 20
Output:
20
41

Explanation :
Test Case 1: We make the array as {2, 3, 4, 5, 6}. Sum becomes 2 + 3 + 4 + 5 + 6 = 20

Test Case2 : We make the array as  {20, 21 } .sum = 41


*/

#include<iostream>
using namespace std;

int makeDistinct(int*a, int N)
{
    int base = a[0];
    int sum  = a[0];

    for(int i = 1; i<N; ++i )
    {
        if(base == a[i])
        {
            base = (a[i]+1);
            sum += base;
        }
        else
        {
            if(base >a[i])// since element is changed, so may be changed the sorted property. this will handle this.
            {
                a[i] = (base+1);
                base = a[i];
                sum += base;
            }
            else
            {
                sum += a[i];
                base = a[i];
            }

        }
    }

    cout<<sum<<endl;

    return 0;
}

int main()
{
    int  t =0;
    int  N = 10;
    int  a[10001];

    cin>>t;

    while(t--)
    {
        cin>>N;
        
        int i = 0;
        
        while(i<N)
        {
            cin>>a[i++];
        }
        makeDistinct(a,N);
    }

    return 0;
}