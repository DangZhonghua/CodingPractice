/*
Ways To Tile A Floor 
https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor/0
https://www.geeksforgeeks.org/tiling-problem/

Given a floor of dimensions 2 x W and tiles of dimensions 2 x 1, write code to 
find the number of ways the floor can be tiled. 
A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is W.

Output:

Print number of ways the floor can be tiled in a separate line.

Constraints:

1 ≤ T ≤ 50
1 ≤ W ≤ 70

Example:

Input
2
5
3

Output
8
3

*/

#include<iostream>
#include<vector>
using namespace std;

int WaysOfTileFloor(int N)
{
    vector<long long> wtf(N+1,0);
    wtf[1] = 1;
    wtf[2] = 2;

    for(int w = 3; w<=N; ++w)
    {
        wtf[w] = wtf[w-1] + wtf[w-2];
    }
    cout<<wtf[N]<<endl;

    return 0;    
}

int main()
{
    int t = 0;
    int N = 0;

    cin>>t;
    
    while(t--)
    {
        cin>>N;
        WaysOfTileFloor(N);
    }
    
    return 0;
}

