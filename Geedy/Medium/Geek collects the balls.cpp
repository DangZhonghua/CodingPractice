/*
https://practice.geeksforgeeks.org/problems/geek-collects-the-balls/0

There are two parallel roads, each containing N and M buckets, respectively.
Each bucket may contain some balls. 
The buckets n both roads are kept in such a way that they are sorted according to the number of balls in them. 
Geek starts from the end of the road which has the bucket with lower number of balls
(i.e. if buckets are sorted in increasing order, then geek will start from the left side of road).
The geek can change the road only at the point of intersection
(whichmeans , buckets with the same number of balls on two roads). 
Now you need to help Geek to collect the maximum number of balls.

Input:
First line of input contains T denoting number of test cases. 
First line of each test case contains two integers N and M, 
denoting the number of buckets on road1 and road2 respectively. 
2nd line of each test case contains N integers, number of balls in buckets on first road. 
3rd line of each test case contains M integers, number of balls in buckets on second road.

Output:
For each test case output a single line containing the maximum possible balls that Geek can collect.

Constraints:
1<= T <= 1000
1<= N <= 10^3
1<= M <=10^3
0<= Ai,Bi <=10^6

Example:
Input:
1
5 5
1 4 5 6 8
2 3 4 6 9

Output:
29

Explanation:

The path with maximum sum is (2,3,4)[5,6](9). Integers in [] are the buckets of first road and in () are the buckets of second road. 
So, max balls geek can collect is 29.

*/

/*

This is geedy algorithm, but think it as dynamic programming: check every choice and find that
chose current,local optimal can yield overall solution.

*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binSearch(int*a, int s, int e, int t)
{
    int index = -1;
    while(s<=e)
    {
        int m = (s+e)/2;
        if(a[m] == t)
        {
            index = m;
            s = m+1;
        }
        else if(a[m]>t)
        {
            e = m-1;
        }
        else
        {
            s = m+1;
        }
    }

    return index;
}

int CollectBalls(int*a, int*b, int N, int M)
{
    vector< pair<int,int> > vj;
    int jt = -1;
    int sr = 0; 
    int se = M-1;
    std::sort(a,a+N);
    std::sort(b,b+M);

    for(int i = 0; i<N; ++i)
    {
        if(i == N-1 || a[i] != a[i+1])
        {
            jt = binSearch(b,sr,se,a[i]);
            if(-1 != jt)
            {
                vj.push_back(pair<int,int>(i,jt));
                sr = jt+1;
            }
        }
    }


    int max = 0;
    int il = 0;
    int ir = 0;
    int suml = 0;
    int sumr = 0;
    for(int i = 0; i<vj.size(); ++i)
    {
        suml = 0;
        sumr = 0;
        for(il; il<= vj[i].first; ++il)
        {
            suml += a[il];
        }
        for(ir; ir<=vj[i].second;++ir)
        {
            sumr += b[ir];
        }
        if(suml>sumr)
        {
            max += suml;
        }
        else
        {
            max += sumr;
        }        
    }
    suml = 0;
    sumr = 0;
    for(il; il<N;++il)
    {
        suml += a[il];
    }

    for(ir; ir<M; ++ir)
    {
        sumr += b[ir];
    }

    if(suml>sumr)
    {
        max += suml;
    }
    else
    {
        max += sumr;
    }  

    cout<<max<<endl;
    return 0;
}


int main()
{
    int t = 0;
    int N = 0;
    int M = 0;
    int a[10000];
    int b[10000];

    cin>>t;

    while(t>0)
    {
        --t;
        cin>>N>>M;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        i = 0;
        while(i<M)
        {
            cin>>b[i++];
        }

        CollectBalls(a,b,N,M);
    }


    return 0;
}