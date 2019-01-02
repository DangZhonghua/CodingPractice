/*

Minimum cost to buy N kilograms of sweet for M persons
https://www.geeksforgeeks.org/minimum-cost-to-buy-n-kilograms-of-sweet-for-m-persons/

Given an array of n size contains the cost of sweets in such a way that that sweet[i] is the cost of i sweets. 
The task is to find the minimum cost to spend to buy exactly ‘n’ kilograms of sweet for the ‘m’ persons.

Since sweets are available in the packets, you have to buy at most ‘m’ packet of sweets for your ‘m’ relatives. 
You cannot buy more than ‘m’ packet of sweets. 
Also cost[i] = 0, represents that the sweet with packet size i is unavailable. 
Also, there is an infinite number of packets with i size of sweets. 

    Input: m = 3, n = 6, arr[] = {2, 1, 3, 0, 4, 10}
    Output: 3
    We can choose at most 3 packets. We choose 3 packets of size 2 having cost 1 each.Thus output is 3.

    Input: m = 2, n = 7, arr[] = {1, 3, 0, 5, 0, 0, 0}
    Output : 0
    We can choose at most 2 packets. 7 can be formed by 1 2 and 4 index but since you require at most 
    2 packets to obtain the 7 sweets packets answer which is not possible. 
    Hence the answer is 0 as it is formed by 3 packets, not 2.

*/



/*

this is 2D complete knapsack problems. There are two ressource need to consume: kilogram and the package count.
f[i][K][M]

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int CalcMinimumSpent(vector<int>&a, int M, int N)
{
    int ret = 0;
    vector<int> vc;
    vector<int> vw;
    
    for(int i = 0; i<a.size(); ++i)
    {
        if(a[i])
        {
            vc.push_back(a[i]);
            vw.push_back(i+1);
        }
    }

    vector< vector< vector<int> > > dp(vc.size()+1,vector< vector<int> >(M+1, vector<int>(N+1,INT_MAX)));
    //Pay attention to the initialization of matrix.
    dp[0][0][0] = 0;

    for(int i = 0; i<vc.size(); ++i)
    {
        for(int m = 1; m<M; ++m)
        {
            for(int n = 1; n< N; ++n)
            {
                dp[i][m][n] = dp[i-1][m][n];
                if(n>=vw[i] && INT_MAX != dp[i-1][m-1][n-vw[i]] && dp[i][m][n]< dp[i-1][m-1][n-vw[i]] + vc[i])
                {
                   dp[i][m][n] = dp[i-1][m-1][n-vw[i]] + vc[i];
                }
            }
        }
    }

    cout<<dp[vc.size()-1][M][N]<<endl; 

    return ret;
}


int main(int argc, char const *argv[])
{
    vector<int> a{2, 1, 3, 0, 4, 10};
    int M = 3;
    int N = 6;
    CalcMinimumSpent(a,M,N);


    
    return 0;
}
