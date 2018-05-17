/*

https://practice.geeksforgeeks.org/problems/max-rope-cutting/0


Given a rope of length n meters, cut the rope in different parts of integer lengths 
in a way that maximizes product of lengths of all parts. You must make at least one cut.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is length of rope denoted by N.

Output:

Print the maximizes product of lengths of all parts.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 100

Example:

Input:
2
2
5

Output:
1
6

*/

/*

This is dynamic programming problem: optimal sub-structure and overlapped sub-problem.

C[1...N] = max{ C[1...j]*C[j+1...N]; } for j:2...N;


*/

#include<iostream>
#include<vector>
using namespace std;

int gm = 1000000007;
int MaxRopeCutting(int N)
{
    //vector<unsigned long long> r(N+1,0);
    unsigned long long r[10001] = {0};

    r[1] = 1;
    
    for(int i = 2; i<=N; ++i)
    {
        for(int j = 1; j<=i/2;++j)
        {
            unsigned long long p = ((r[j])*(r[i-j]));
            p %=gm;
            if(p>r[i])
            {
                r[i] = p;
            }
        }
        if(i<N)
        {
            if(r[i]<i)
            {
                r[i] = i;
            }
        }
    }
    cout<<r[N]<<endl;

    return 0;
}

int main()
{
    int t = 0;
    int N = 0;

    cin>>t;

    while(t>0)
    {
        --t;
        cin>>N;
        MaxRopeCutting(N);
    }
}

/*

Below is the accepted solution, but I think this not yield the optimal result(maximum product)
since it not check every possible choice, it looks like a geedy algorithm.

*/


/*

#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
typedef long long llint;
int n;
llint fun(int m)
{
    if(m==2 || m==3)
    return m-1;
    llint ans=1;
    while(m>4)
    {
        ans=(ans*3)%MAX;
        m-=3;
    }
    return (m*ans)%MAX;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cout<<fun(n)<<endl;
	}
	return 0;
}


*/