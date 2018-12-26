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
	int maxRatio = 0;
	int C = a.size();
	for (auto v : a)
	{
		if (maxRatio<v)
		{
			maxRatio = v;
		}
	}

	vector< vector<int> > dp(C + 1, vector<int>(maxRatio + 1, INT_MAX));
	for (int i = 0; i <= maxRatio; ++i)
	{
		dp[0][i] = i; //for single element case.
	}

	for (int i = 1; i < C; ++i)
	{
		if (a[i]>a[i - 1])  // increasing case
		{
			int s = 0;
			for (int p = 1; p <= maxRatio; ++p)
			{
				if (INT_MAX == dp[i - 1][p])
				{
					continue;
				}
				else
				{
					if (0 == s)
					{
						s = p;
						break;
					}	
				}
			}
			for (int p = s + 1; p <= maxRatio; ++p)
			{
				dp[i][p] = dp[i-1][s]+p;
			}
		}
		else if (a[i] < a[i - 1]) //decreasing case
		{
			int e = 0;
			for (int p = 1; p < maxRatio; ++p)
			{
				if (INT_MAX == dp[i - 1][p])
				{
					continue;
				}
				else
				{		
					e = p;
					break;
				}
			}
			for (int p = 1; p < e; ++p)
			{
				dp[i][p] = dp[i - 1][e] + p;
			}
		}
		else //Equal case.
		{
			for (int p = 1; p <= maxRatio; ++p)
			{
				if (INT_MAX == dp[i - 1][p])
				{
					dp[i][p] = dp[i - 1][p] + p;
				}
				
			}
		}
	}

	int minv = INT_MAX;
	for (int p = 1; p <= maxRatio; ++p)
	{
		if (dp[C - 1][p] < minv)
		{
			minv = dp[C-1][p];
		}
	}
	cout<<minv<<endl;

	return ret;
}

int easyWayToDo(vector<int>& a)
{
    int ret = 0;
    vector<int> leftMinV(a.size(),1);
    vector<int> rightMinV(a.size(),1);
    vector<int> minV(a.size(),0);
    for(int i = 1; i<a.size(); ++i)
    {
        if(a[i]>a[i-1])
        {
            leftMinV[i] = leftMinV[i-1]+1;
        }
    }
    
    for(int j = a.size()-2; j>=0; --j)
    {
        if(a[j]>a[j+1])
        {
            rightMinV[j] = rightMinV[j+1]+1;
        }
    }
    int sum = 0;
    for(int i = 0; i<a.size();++i)
    {
        minV[i] = rightMinV[i]>leftMinV[i]? rightMinV[i]:leftMinV[i];
        sum += minV[i];
    }

    cout<<sum<<endl;

    return ret;
}


int main(int argc, char const *argv[])
{
	vector<int> a{ 1, 3, 4, 3, 7, 1 };
	vector<int> b{ 1, 6, 8, 3, 4, 1, 5, 7 };
	MinimumCostOfBuying(a);
	MinimumCostOfBuying(b);

    easyWayToDo(a);
    easyWayToDo(b);

	return 0;
}
