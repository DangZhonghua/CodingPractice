/*
Optimal walk 
https://practice.geeksforgeeks.org/problems/optimal-walk/0/?ref=self
https://www.geeksforgeeks.org/minimum-positive-points-to-reach-destination/

Given a point on x axis, (N,0), you are standing at origin and you can only move on x-axis. 
Lets say you are at (x,0), at each step you can either move one step forward ie (x+1,0) or 
one step backwards (x-1,0) or make a jump to double your current position (2*x,0). 
One step movement costs you A while a jump costs you B. If your initial position is (0,0) , 
find the minimum cost to reach (N,0) .

Input:
First line of input consist of a single integer T denoting the total number of test case. Then T test cases follow. Each line of test case contains 3 space separated integers N, A, B as described in the problem statement.

Output:
For each test case, print a single line containing the minimum cost to reach (N,0).


Constraints:
1<=T<=30
1<=N<=10^5
1<=A,B<=10^9


Example:
Input:
1
7 1 100

Output:
7
*/


/*

move cost is A. jump cost is B

if j is even
OW[j] = min{ OW[j-1] + A, OW[j/2] + B }

if j is odd
OW[j] = min{ OW[j/2] + A + B, OW[j/2+1] + A + B, OW[j-1] + A }


*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int OptimalWalk(int N, int mc, int jc)
{
    vector<long long> ow(2*N+1,LLONG_MAX);

    ow[0] = 0;
    ow[1] = mc;
    
    for(int i = 2; i<=N; ++i)
    {
        if(0 == i%2)
        {
            ow[i] = ow[i/2] +  jc;
            if(ow[i]>ow[i-1] + mc)
            {
                ow[i] = ow[i-1] + mc;
            }
        }
        else
        {
            ow[i] = ow[i/2] + jc + mc;
            if(ow[i]> ow[i/2+1] + jc + mc)
            {
                ow[i] = ow[i/2 + 1] + jc + mc;
            }
            if(ow[i]>ow[i-1] + mc)
            {
                ow[i] = ow[i-1] + mc;
            }
        }
    }

    cout<<ow[N]<<endl;


    return 0;
}


int main()
{
    int t   = 0;
    int N   = 0;
    int mc  = 0;
    int jc  = 0;
    
    cin>>t;

    while(t--)
    {
        cin>>N;
        cin>>mc>>jc;
        OptimalWalk(N,mc,jc);
    }

    return 0;
}