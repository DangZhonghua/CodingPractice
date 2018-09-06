/*
Minimum number of single digit primes required whose sum is equal to N
https://www.geeksforgeeks.org/minimum-number-of-single-digit-primes-required-whose-sum-is-equal-to-n/
Find the minimum number of single-digit prime numbers required whose sum will be equal to N.

Examples:

Input: 11
Output: 3
Explanation: 5 + 3 + 3.
Another possibility is 3 + 3 + 3 + 2, but it is not
the minimal

Input: 12
Output: 2
Explanation: 7 + 5


*/

/*

2, 3, 5, 7
This is knapsack problem
*/

#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int prime[4] = {2,3,5,7};



int MinimumPrime(int N)
{
    vector<int> minic(N+1, INT_MAX);
    minic[0] = 0;

    for(int i = 0; i<4; ++i)
    {
        for(int n = 1; n<=N; ++n)
        {
            if(n>=prime[i] && INT_MAX != minic[n-prime[i]] && minic[n] > minic[n-prime[i]] + 1)
            {
                minic[n] = minic[n-prime[i]] + 1;
            }
        }
    }

    cout<<minic[N]<<endl;

    return 0;
}


int main(int argc, char const *argv[])
{
 MinimumPrime(11);
 MinimumPrime(12);

    return 0;
}
