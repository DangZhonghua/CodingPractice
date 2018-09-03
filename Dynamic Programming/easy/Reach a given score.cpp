/*
https://practice.geeksforgeeks.org/problems/reach-a-given-score/0
https://www.geeksforgeeks.org/count-number-ways-reach-given-score-game/

Reach a given score

Consider a game where a player can score 3 or 5 or 10 points in a move. 
Given a total score n, find number of distinct combinations to reach the given score.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.

Output:
Print number of ways/combinations to reach the given score.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000

Example:
Input
3
8
20
13

Output
1
4
2
Explanation
For 1st example when n = 8
{ 3, 5 } and {5, 3} are the two possible permutations but these represent the same cobmination. Hence output is 1.

*/

/*

variation of infinite knapsack problem
S[j][c] = S[i-1][c-s[i]]

*/

#include<iostream>
#include<vector>
using namespace std;

int score[3] = {3,5,10};

int scoreWay(int N)
{
    vector<int> w(N+1,0);
    w[0] = 1;

    for(int i = 0; i<3; ++i)
    {
        for(int n = score[i]; n<=N; ++n)
        {
            w[n] += w[n-score[i]];
        }
    }

    cout<<w[N]<<endl;

    return 0;
}



int main(int argc, char const *argv[])
{
    int t = 0;
    int N = 0;
    
    cin>>t;
    
    while(t--)
    {
        cin>>N;
        scoreWay(N);
    }
    
    return 0;
}
