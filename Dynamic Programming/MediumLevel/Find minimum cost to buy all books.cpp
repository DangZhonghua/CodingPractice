/*
https://www.geeksforgeeks.org/find-minimum-cost-buy-books/
Find minimum cost to buy all books

Given an array of ratings for n books. Find the minimum cost to buy all books with below conditions :

    Cost of every book would be at-least 1 dollar.
    A book has higher cost than an adjacent (left or right) if rating is more than the adjacent.

Examples :

Input : Ratings[] = {1, 3, 4, 3, 7, 1}
Output : 10
Exp :- 1 + 2 + 3 + 1 + 2 + 1 = 10

Input : ratings[] = {1, 6, 8, 3, 4, 1, 5, 7}
Output : 15
Exp :- 1 + 2 + 3 + 1 + 2 + 1 + 2 + 3 = 15 

*/

/*
Dynamic Programming: optimal substructure and overlapped subproblems.

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int MinimumCostOfBuying(vector<int>& a)
{
    int ret = 0;
    int maxRatio  = 0;
    int C = a.size();
    for(auto v:a)
    {
        if(maxRatio<v)
        {
            maxRatio = v;
        }
    }
    vector< vector<int> > dp(C, vector<int>(maxRatio+1, INT_MAX));

    for(int i = 0; i<C; ++i)
    {
        for(int r = 1; r<=maxRatio; ++r)
        {
            
        }
    }


    return ret;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
