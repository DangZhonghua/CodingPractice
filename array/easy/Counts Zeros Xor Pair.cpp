/*
Counts Zeros Xor Pair
https://practice.geeksforgeeks.org/problems/counts-zeros-xor-pairs/0/?ref=self

Given an array A[] of size N. Find the number of pairs (i, j) such that A_i XOR A_j = 0, and 1 <= i < j <= N.

Input:
The first line of the input contains a single integer T denoting the number of test cases. The first line of each test case contains N. followed by N separate integers. 

Output:
For each test case, output a single integer i.e counts of Zeros Xors Pairs

Constraints
1 ≤ T ≤ 200
2 ≤ N ≤ 10^5
1 ≤ A[i] ≤ 10^5

Example:
Input :
2
5
1 3 4 1 4

3
2 2 2

Output :

2
3

Explanation :

Test Case 1: Index( 0, 3 ) and (2 , 4 ) are only pairs whose xors is zero so count is 2.


*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

unsigned long long Calcfactorial(int c)
{
    unsigned long long f = 1;
    f = ((c+1)*c)/2;

    return f;
}

unsigned long long CalcPairCount(int count)
{
    unsigned long long t = Calcfactorial(count-1);
    //unsigned long long l = Calcfactorial(count-2);
    
    return t ;
}
int CountXorZeroPairs(int*a, int N)
{
    std::sort(a,a+N);
    int base    = a[0];
    int count   = 1;
    unsigned long long total = 0;
    for(int i = 1; i<N; ++i)
    {
        if(base == a[i])
        {
            ++count;
        }
        else
        {
            if(count>=2)
            {
                total += CalcPairCount(count);
            }
            base    = a[i];
            count   =1;
        }
    }
    if(count>=2)
    {
        total += CalcPairCount(count);
    }
    cout<<total<<endl;

    return 0;
}

int main()
{
    int t = 0;
    int a[10001];
    int N = 0;

    cin>>t;
    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        CountXorZeroPairs(a,N);
    }

    return 0;
}