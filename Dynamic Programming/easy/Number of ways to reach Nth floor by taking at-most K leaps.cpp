/*
Number of ways to reach Nth floor by taking at-most K leaps
https://www.geeksforgeeks.org/number-of-ways-to-reach-nth-floor-by-taking-at-most-k-leaps/

Given N number of stairs. Also given the number of steps that one can cover at most in one leap (K). The task is to find the number of possible ways one (only consider combinations) can climb to the top of the building in K leaps or less from the ground floor.

Examples:

    Input: N = 5, K = 3
    Output: 5
    To reach stair no-5 we can choose following combination of leaps:
    1 1 1 1 1
    1 1 1 2
    1 2 2
    1 1 3
    2 3
    Therefore the answer is 5.

    Input: N = 29, K = 5
    Output: 603 

*/

/*

W[i] = W[i-1] + W[i-2] +...+W[i-k]

*/

#include<iostream>
#include<vector>
using namespace std;

int waysofLeaps(int N, int K)
{
    vector<int> w(N+1, 0);
    w[0] = 1;

    for(int k = 1; k<=K; ++k)
    {
        for(int n = k; n<=N; ++n)
        {
            w[n] += w[n-k];
        }
    }

    cout<<w[N]<<endl;

    return 0;
}


int main(int argc, char const *argv[])
{
    waysofLeaps(5,3);
    waysofLeaps(29,5);

    return 0;
}

