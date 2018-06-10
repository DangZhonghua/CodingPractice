/*
https://practice.geeksforgeeks.org/problems/pairs-with-positive-negative-values/0/?ref=self

Given an array of distinct integers, print all the pairs having positive value and negative value of a number that exists in the array.

NOTE: If there is no such pair in the array , print "0".

Input:
The first line consists of an integer T i.e number of test cases. The first line of each test case consists of an integer n.The next line of each test case consists of n spaced integers.

Output:
Print all the required pairs in the increasing order of their absolute numbers.

Constraints: 
1<=T<=100
1<=n<=1000
-1000<=a[i]<=1000

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int PairOfPosAndNeg(int*a, int N)
{
    vector< int > pos(1001, 0);
    vector< int > neg(1001, 0);
    vector<int>   c;
    int count = 0;
    
    for(int i = 0; i<N; ++i)
    {
        if(a[i]>0)
        {
            pos[a[i]] = 1;
            if(neg[a[i]])
            {
                c.push_back(a[i]);

            }
        }
        else
        {
            neg[-a[i]] = 1;
            if(pos[-a[i]])
            {
                c.push_back(-a[i]);
            }
        }
    }

   
    if(0==c.size())
    {
        cout<<0;
    }
    else
    {
        std::sort(c.begin(), c.end());
        
        for(int i = 0; i<c.size(); ++i)
        {
            cout<<-c[i]<<" "<<c[i]<<" ";
        }
    }
    cout<<endl;


    return 0;
}



int main()
{
    int t = 0;
    
    int a[1001];
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
        PairOfPosAndNeg(a,N);
    }



    return 0;
}