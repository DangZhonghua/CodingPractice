/*

https://www.geeksforgeeks.org/minimum-cost-to-reach-a-point-n-from-0-with-two-different-operations-allowed/

Minimum cost to reach a point N from 0 with two different operations allowed
Given integers N, P and Q where N denotes the destination position. 
The task is to move from position 0 to position N with minimum cost possible and print the calculated cost. 
All valid movements are:

    From position X you can go to position X + 1 with a cost of P
    Or, you can go to the position 2 * X with a cost of Q

Examples:

    Input: N = 1, P = 3, Q = 4
    Output: 3
    Move from position 0 to 1st position with cost = 3.

    Input: N = 9, P = 5, Q = 1
    Output: 13
    Move from position 0 to 1st position with cost = 5,
    then 1st to 2nd with cost = 1,
    then 2nd to 4th with cost = 1,
    then 4th to 8th with cost = 1,
    finally 8th to 9th with cost = 5.
    Total cost = 5 + 1 + 1 + 1 + 5 = 13. 

*/

#include<iostream>
#include<vector>
using namespace std;

int MinimumCost2Reach(int N,int P, int Q)
{
    int ret = 0;
    vector<int> vc(N+1, 0);

    for(int i = 1; i<= N; ++i)
    {
        vc[i] = vc[i-1] + P;
        if(0 == i%2)
        {
          if( vc[i]> vc[i/2] + Q )
          {
              vc[i] = vc[i/2] + Q;
          }
        }
    }
    cout<<vc[N]<<endl;
    return ret;
}

int main(int argc, char const *argv[])
{
    int t = 0;

     MinimumCost2Reach(1,3,4);
     MinimumCost2Reach(9,5,1);

    // cin>>t;
    
    // while(t--)
    // {
    //     int N,P,Q;
    //     cin>>N>>P>>Q;
    //     MinimumCost2Reach(N,P,Q);
    // }
    return 0;
}
