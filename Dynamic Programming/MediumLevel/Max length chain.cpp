/*

Max length chain
https://practice.geeksforgeeks.org/problems/max-length-chain/1
https://www.geeksforgeeks.org/dynamic-programming-set-20-maximum-length-chain-of-pairs/


You are given N pairs of numbers. In every pair, the first number is always smaller than the second number.
A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion.
Your task is to complete the function maxChainLen which returns an integer denoting the
longest chain which can be formed from a given set of pairs.

Input:
The first line of input contains an integer T denoting the no of test cases then T test cases follow .
Then T test cases follow . The first line of input contains an integer N denoting the no of pairs .
In the next line are 2*N space separated values denoting N pairs.

Output:
For each test case output will be the length of the longest chain formed.

Constraints:
1<=T<=100
1<=N<=100

Example(To be used only for expected output):
Input
2
5
5  24 39 60 15 28 27 40 50 90
2
5 10 1 11

Output
3
1
​
Explanation
(i) the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} },
the longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}
(ii) The max length chain possible is only of length one.


*/

/*
Nothing, this is just like LIS problem.
8
125 896 546 583 368 815 365 435 44 751 88 809 179 277 585 789
4

*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



struct val
{
	int first;
	int second;
};

struct valCompare
{
	bool operator () (const val& lhs, const val& rhs)
	{
		return lhs.second < rhs.second;
	}
};

int maxChainLen(struct val p[], int n)
{
	int maxlen = 1;
	vector<int> MLC(n + 1, 1);
	std::sort(p, p + n, valCompare());
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (p[i].first > p[j].second && MLC[i] < MLC[j] + 1)
			{
				MLC[i] = MLC[j] + 1;
			}
		}
		if (maxlen < MLC[i])
		{
			maxlen = MLC[i];
		}
	}

	return maxlen;
}


int maxChainLen(int a[], int N)
{
	int maxlen = 1;
	vector<int> MLC(N + 1, 1);

	for (int i = 2; i < 2 * N; i += 2)
	{
		for (int j = 0; j<i; ++j)
		{
			if (j & 1)
			{
				if (a[i]>a[j] && MLC[i / 2] < MLC[j / 2] + 1)
				{
					MLC[i / 2] = MLC[j / 2] + 1;
				}
			}
		}
		if (maxlen < MLC[i / 2])
		{
			maxlen = MLC[i / 2];
		}
	}

	//cout << maxlen << endl;

	return maxlen;
}

int main(int argc, char const *argv[])
{
	/* code */
	int t = 0;
	int N = 0;
	int a[1000];

	cin >> t;

	while (t--)
	{
		cin >> N;
		int i = 0;
		while (i < 2 * N)
		{
			cin >> a[i++];
		}
		cout<<maxChainLen(a, N)<<endl;
	}


	return 0;
}
