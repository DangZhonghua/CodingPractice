/*
Subset with sum divisible by m
https://practice.geeksforgeeks.org/problems/subset-with-sum-divisible-by-m/0/?ref=self

Given a set of non-negative distinct integers, and a value m, determine if there is a 
subset of the given set with sum divisible by m.

 

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. The first line of each test case 
contains an integer N and M where N denotes the size of the array and M is the number 
for which we have to check the divisibility.
The second line of each test case contains N space separated integers denoting elements of the array A[ ].

Output:
If there is a subset which is divisible by M print '1' else print '0'. 

Constraints:

1<= T <=100
1<= N,M <=1000
1<= A[ ] <=1000

Example:

Input:
1
4 6
3 1 7 5
Output:
1

*/

/*

This is 0-1 knapsack problem.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int divisibleBy(vector<int>&a, int M)
{
    int T          = 0;
    bool bDivide    = false;
   // std::sort(a.begin(), a.end());

    for(auto e: a)
    {
        T += e;
    }
    vector<int> vs(T+1,0);
    vs[0] = 1;
    
    for(int i = 0; i<a.size() && !bDivide;++i)
    {
        for(int v = a[i]; v<=T; ++v)
        {
            if(vs[v-a[i]])
            {
                vs[v] = vs[v-a[i]];
                if(0 == v%M && v/M)
                {
                    bDivide = true;
                    break;
                }
                break;
            }
        }
    }
    cout<<(bDivide?1:0)<<endl;

    return 0;
}


int main(int argc, char const *argv[])
{
    int t = 0;
    cin>>t;
    
    while(t--)
    {
        int N,M;
        cin>>N>>M;
        vector<int> a(N,0);
        int i = 0;
        while(i<N)
        {
            cin>>a[i];
            ++i;
        }
        divisibleBy(a,M);

    }
    return 0;
}
