/*
Maximum Profit
https://practice.geeksforgeeks.org/problems/maximum-profit/0
https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-k-times/

In stock market , a person buys a stock and sells it on some future date.
Given the stock prices of N days in an form of an array A[ ] and a positive integer K,
find out the maximum profit a person can make in at most K transactions.
A transaction is equivalent to (buying + selling) of a stock and
new transaction can start only when the previous transaction has been completed.

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains a positve integer K, denoting the number of transactions.
The second line of each test case contains a positve integer N, denoting the length of the array A[ ].
The third line of each test case contains a N space separated positive integers,
denoting the prices of each day in the array A[ ].


Output
Print out the maximum profit earned by the person.
No profit will be equivalent to 0.


Constraints
1 <= T <= 100
0 <   K <= 10
2 <= N <=30
0 <= A[ ] <= 1000

Examples

Input
3
2
6
10 22 5 75 65 80
3
4
20 580 420 900
1
5
100 90 80 50 25

Output
87
1040
0


Explanation:
Output 1: Trader earns 87 as sum of 12 and 75  i.e. Buy at price 10, sell at 22, buy at  5 and sell at 80
Output 2: Trader earns 1040 as sum of 560 and 480 i.e. Buy at price 20, sell at 580, buy at 420 and sell at 900
Output 3: Trader cannot make any profit as selling price is decreasing day by day.Hence, it is not possible to earn anything.

2
2
17
334 500 169 724 478 358 962 464 705 145 281 827 961 491 995 942 827
7
25
604 902 153 292 382 421 716 718 895 447 726 771 538 869 912 667 299 35 894 703 811 322 333 673 664

*/

/*

P[i,j] = max{P[i,e], P[e+1,j]} for i<e<j
P[1,N] is the maximum value.

*/



#include<iostream>
#include<vector>
using namespace std;

int MaximumProfit(int*a, int N, int K)
{
	vector< vector< vector<int> > > p(K + 1, vector< vector<int> >(N + 1, vector<int>(N + 1, 0)));
	int max = 0;

	// Init one time transcation.
	for (int i = 0; i<N; ++i)
	{
		for (int j = i + 1; j<N; ++j)
		{
			if (a[j] - a[i]>0)
			{
				p[1][i][j] = (a[j] - a[i]);
				if (p[1][i][j]>max)
				{
					max = p[1][i][j];
				}
			}
		}
	}
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << p[1][i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;


	for (int k = 2; k <= K; ++k)
	{
		for (int i = 0; i<N; ++i)
		{
			for (int j = i + 1; j<N; ++j)
			{
				for (int l = j + 2; l<N; ++l)
				{
					p[k][i][l] = p[1][i][j] + p[k - 1][j + 1][l];
					if (p[k][i][l]>max)
					{
						max = p[k][i][l];
					}
				}
			}
		}
	}

	cout << max << endl;

	return 0;
}


int main()
{
	int t = 0;
	int K, N;
	int a[100] = { 0 };

	cin >> t;

	while (t--)
	{
		cin >> K >> N;

		int i = 0;
		while (i<N)
		{
			cin >> a[i++];
		}
		MaximumProfit(a, N, K);
	}

	return 0;
}
