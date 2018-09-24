/*
https://practice.geeksforgeeks.org/problems/ways-to-sum-to-n/0/?ref=self
Ways to sum to N 

Given a set of m distinct positive integers and a value ‘N’. The problem is to count the total number of ways we can form ‘N’ by doing sum of the array elements. Repetitions and different arrangements are allowed.

 

Input:

The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. The first line of each test case contains M and N where M denotes 
the size of the array and we have to find the answer for the number N.

The second line of each test case contains M space separated integers denoting elements of the array A[ ].


Output:

Print the answer for each test case in a new line. Since the answer can be quite large output the answer modulo 109+7.


Constraints:

1<= M <=1000

1<= N <=1000

1<= A[ ] <=1000


Example:

Input:

1
3 7
1 5 6
Output:
6
*/

#include<iostream>
#include<vector>
using namespace std;

int gmod = 1000000007;

int WaysSumToN(vector<int>& a, int N)
{
    vector<long long> vw(N+1, 0);
    vw[0] = 1;

    for(int n = 1; n<=N; ++n)
    {
        for(int i = 0; i<a.size(); ++i)
        {
            if(n>=a[i] && vw[n-a[i]])
            {
                vw[n] += vw[n-a[i]];
                vw[n] %=gmod;
            }
        }
    }
    cout<<vw[N]<<endl;


    return 0;
}

int main(int argc, char const *argv[])
{
    int t = 0;
    
    cin>>t;
    
    while(t--)
    {
        int c = 0;
        int N = 0;
        cin>>c>>N;
        int i = 0;
        vector<int> a(c,0);
        while(i<c)
        {
            int d = 0;
            cin>>d;
            a[i++] = d;
        }
        WaysSumToN(a,N);
    }


    return 0;
}
