/*
Minimum Cost to make two Numeric Strings Identical
https://www.geeksforgeeks.org/minimum-cost-to-make-two-numeric-strings-identical/

Given two numeric strings, A and B. A numeric string is a string that contains only digits [‘0’-‘9’].
The task is to make both the strings equal in minimum cost.
The only operation that you are allowed to do is to delete a character (i.e. digit) from any of the strings (A or B).
The cost of deleting a digit D is D units.

Examples:

Input : A = “7135”, B = “135”
Output : 7
To make both string identical we have to delete ‘7’ from string A.

Input : A = “9142”, B = “1429”
Output : 14
There are 2 ways to make string “9142” identical to “1429” i.e either by deleting ‘9’
from both the strings or by deleting ‘1’, ‘4’and ‘2’
from both the string. Deleting 142 from both the string will cost 2*(1+4+2)=14 which is more optimal than deleting ‘9’.
*/

/*

			mc[i-1][j-1]
mc[i][j] =  min{mc[i-1][j] + x[i], mc[i][j-1]+y[j]}

*/

#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

int MinimumCost(const string& x, const string& y)
{
	int ret = 0;


	int R = x.length();
	int C = y.length();

	vector< vector<int> > mc(R + 1, vector<int>(C + 1, INT_MAX));
	vector< vector<int> > md(R + 1, vector<int>(C+1,0));

	mc[0][0] = 0; //for both empty string, it minimum cost is zero

	for (int r = 1; r <= R; ++r)
	{
		mc[r][0] = mc[r - 1][0];
		mc[r][0] += (x[r - 1] - '0');
	}

	for (int c = 1; c <= C; ++c)
	{
		mc[0][c] = mc[0][c - 1];
		mc[0][c] += (y[c - 1] - '0');
	}

	for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
		{
			if (x[r - 1] == y[c - 1])
			{
				mc[r][c] = mc[r - 1][c - 1];
			}
			else
			{
				mc[r][c] = mc[r - 1][c] + x[r - 1] - '0';
				md[r][c] = 1;
				if (mc[r][c] >mc[r][c - 1] + y[c - 1] - '0')
				{
					mc[r][c] = mc[r][c - 1] + y[c - 1] - '0';
					md[r][c] = 2;
				}
			}
		}
	}

	cout << mc[R][C] << endl;

	for (auto row : mc)
	{
		for (auto cost : row)
		{
			cout << cost << " ";
		}
		cout<<endl;
	}

	for (auto row : md)
	{
		for (auto cost : row)
		{
			cout << cost << " ";
		}
		cout << endl;
	}

	return ret;
}

int main(int argc, char const *argv[])
{

	string x1 = "7135";
	string y1 = "135";

	string x2 = "9142";
	string y2 = "1429"; 

	//MinimumCost(x1, y1);
	MinimumCost(x2, y2);

	return 0;
}
