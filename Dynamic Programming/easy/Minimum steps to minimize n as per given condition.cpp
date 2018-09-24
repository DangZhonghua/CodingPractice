/*
Minimum steps to minimize n as per given condition
https://practice.geeksforgeeks.org/problems/minimum-steps-to-minimize-n-as-per-given-condition/0/?ref=self

Given a number n, count minimum steps to minimise it to 1 according to the following criteria:

    If n is divisible by 2 then we may reduce n to n/2.
    If n is divisible by 3 then you may reduce n to n/3.
    Decrement n by 1.

 

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the number n.

 

Output:

Output the minimum steps to minimise the number in a new line for each test case.


Constraints:

1<= T <=1000

1<= N <=10000


Example:

Input:

2

10
6

Output:
3
2

*/

/*


f[n] = min{
            f[n/2],
            f[n/3],
            f[n-1]
            } + 1;

f[n] = min{
    f[2n],
    f[3n],
    f[n-1]
}+1

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minimizeStep(int N)
{
    vector<int> vs(N+1,INT_MAX);
    vs[N] = 0;
    for(int i = N; i>=1; --i)
    {
        if(vs[i-1]> vs[i] + 1)
        {
            vs[i-1] = vs[i] + 1;
        }
        if(i%2 ==0 && vs[i/2]>vs[i]+1)
        {
            vs[i/2] = vs[i] + 1;
        }
        if(i%3 == 0 && vs[i/3]> vs[i] + 1)
        {
            vs[i/3] = vs[i] + 1;
        }
    }
    cout<<vs[1]<<endl;

    return 0;

}

int main(int argc, char const *argv[])
{
    int t = 0;
    cin>>t;
    
    while(t--)
    {
        int N = 0;
        cin>>N;
        minimizeStep(N);
    }

    return 0;
}
