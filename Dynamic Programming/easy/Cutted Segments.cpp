/*
Cutted Segments
https://practice.geeksforgeeks.org/problems/cutted-segments/0/?ref=self
Given an integer N denoting the Length of a line segment. 
you need to cut the line segment in such a way 
that the cut length of a line segment each time is integer either x , y or z. 
and after performing all cutting operation the total number of cutted segments must be maximum. 


Input
first line of input contains of an integer 'T' denoting number of test cases
first line of each testcase contains N .
second line of each testcase contains 3 space separated integers x , y and z.

Output
For each test case print in a new line an integer corresponding to the answer .


Constraints
1<=t<=70
1<=N,x,y,z<=4000
 

Example

Input

2
4
2 1 1
5
5 3 2


Output
4
2

*/

#include<iostream>
#include<vector>
using namespace std;

int MaxCutSeg(int N, int a[3])
{
    vector<int> vSeg(N+1, -1);
    vSeg[0] = 0; // for 0 there is No segement

    for(int i = 1; i<=N; ++i)
    {
        for(int s = 0; s<3; ++s)
        {
            if(i>=a[s])
            {
                if(vSeg[i-a[s]] != -1)
                {
                    if(vSeg[i]<vSeg[i-a[s]]+1)
                    {
                        vSeg[i]= vSeg[i-a[s]]+1; // 1 for adding current seg.
                    }
                }
            }
        }
    }

    cout<<vSeg[N]<<endl;

    return 0;
}


int main()
{
    int t = 0;
    int N = 0;
    int a[3];

    cin>>t;
    
    while(t--)
    {
        cin>>N;
        cin>>a[0];
        cin>>a[1];
        cin>>a[2];
        MaxCutSeg(N,a);
    }

    return 0;
}