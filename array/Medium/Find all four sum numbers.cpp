/*
https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers/0
Find all four sum numbers 

Given an array A of size N, find all combination of four elements in the array whose sum is equal to a given value K. For example, 
if the given array is {10, 2, 3, 4, 5, 9, 7, 8} and K = 23, one of the quadruple is “3 5 7 8” (3 + 5 + 7 + 8 = 23).

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains two integers N and K. Then in the next line are N space separated values of the array.

Output:
For each test case in a new line print all the quadruples present in the array separated by space which sums up to value of K. Each quadruple is unique which are separated by a delimeter "$" and are in increasing order.

Constraints:
1<=T<=100
1<=N<=100
-1000<=K<=1000
-100<=A[]<=100

Example:
Input:
2
5 3
0 0 2 1 1 
7 23
10 2 3 4 5 7 8
Output:
0 0 1 2 $
2 3 8 10 $2 4 7 10 $3 5 7 8 $

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findFourOfSum(int* a, int N, int K)
{
    vector< vector<int> > sumset;
    vector<int> s;

    std::sort(a,a+N);
    
    // for(int i = 0; i<N; ++i)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;

    for(int i = 0; i<N-3; ++i)
    {
        //for handle the case: duplicate of the first element.
        if(i != 0 && a[i] == a[i-1])
        {
            continue;
        }
        for(int j = i+1; j<N-2; ++j)
        {
            //for handle the case: duplicate of the second element.
            if(j - 1!= i && a[j] == a[j-1])
            {
             continue;      
            }
            int l = j+1;
            int r = N-1;
            while(l<r)
            {
                if(l == i || l == j)
                {
                    ++l;
                    continue;
                }
                if(r == i || r == j)
                {
                    --r;
                    continue;
                }

                if(l != j+1 && r != N-1)
                {
                    // for handle the case: duplicate of the third and fourth element.
                    if(a[l] == a[l-1] && a[r] == a[r+1])
                    {
                        ++l;
                        --r;
                        continue;
                    }
                }
                if(a[i]+a[j] + a[l] + a[r] == K) 
                {
                    s.clear();
                    s.push_back(a[i]);
                    s.push_back(a[j]);
                    s.push_back(a[l]);
                    s.push_back(a[r]);
                    sumset.push_back(s);
                    ++l;
                    --r;
                }
                else if(a[i]+a[j] + a[l] + a[r] < K)
                {
                    ++l;
                }
                else
                {
                    --r;
                }           
            }        
        }
    }

    for(int i = 0; i<sumset.size();++i)
    {
        for(int j = 0; j<sumset[i].size(); ++j)
        {
            cout<<sumset[i][j]<<" ";
        }
        cout<<"$";
    }
    if(sumset.size() == 0)
    {
        cout<<-1;
    }
 

    return 0;
}



int main(int argc, char const *argv[])
{
    int t = 0;
    int N = 0;
    int K = 0;
    int a[101];

    cin>>t;

    while(t>0)
    {
        --t;
        cin>>N>>K;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        findFourOfSum(a,N,K);
           cout<<endl;
    }

    return 0;
}
