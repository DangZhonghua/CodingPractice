/*
https://www.geeksforgeeks.org/minimum-cost-to-reach-the-top-of-the-floor-by-climbing-stairs/
Minimum cost to reach the top of the floor by climbing stairs
Given N non-negative integers which signifies the cost of the moving from each stair. 
Paying the cost at i-th step, you can either climb one or two steps. 
Given that one can start from the 0-the step or 1-the step, 
the task is to find the minimum cost to reach the top of the floor(N+1) by climbing N stairs.

Examples:

Input: a[] = { 16, 19, 10, 12, 18 }
Output: 31
Start from 19 and then move to 12. 

Input: a[] = {2, 5, 3, 1, 7, 3, 4}
Output: 9 
2->3->1->3

*/

/*

cost[i] = min{ cost[i-2] + a[i-2], cost[i-1] + a[i-1] }

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minimumCost2Top(vector<int>& a)
{
    vector<int> vc(a.size(),INT_MAX);
    vc[0] = 0;
    vc[1] = 0;
    
    for(int i = 2; i<a.size(); ++i)
    {
        if(vc[i]>vc[i-2]+a[i-2])
        {
            vc[i] = vc[i-2] + a[i-2];
        }
        if(vc[i]> vc[i-1] + a[i-1])
        {
            vc[i] = vc[i-1] + a[i-1];
        }
    }
    
    cout<<vc[a.size()-1]<<endl;
    
    return 0;
}

int main(int argc, char const *argv[])
{
    vector<int> a{ 16, 19, 10, 12, 18 };
    vector<int> b{2, 5, 3, 1, 7, 3, 4 };

    minimumCost2Top(a);
    minimumCost2Top(b);

    return 0;
}
