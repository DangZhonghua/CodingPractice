/*
Combination Sum - Part 2
https://practice.geeksforgeeks.org/problems/combination-sum-part-2/0/?ref=self

Given an array of integers A and a sum B, find all unique combinations in A where the sum is equal to B.

each number in A may only be used once in the combination.

Note:
All numbers will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
If there is no combination possible the print "Empty" (without qoutes).
Example,
Given A = 10,1,2,7,6,1,5 and B(sum) 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

Input:
First is T , no of test cases. 1<=T<=500
Every test case has three lines.
First line is N, size of array. 1<=N<=12
Second line contains N space seperated integers(x). 1<=x<=9.
Third line is the sum B. 1<=B<=30.

Output:
One line per test case, every subset enclosed in () and in every set intergers should be space seperated.(See example)

Example:
Input:
2
7
10 1 2 7 6 1 5
8
5
8 1 8 6 8
12

Output:
(1 1 6)(1 2 5)(1 7)(2 6)
Empty


*/

/*

This is 0-1 knapsack problem.

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<functional>
#include<stack> 
using namespace std;

void outputCombination(vector<int>& vc)
{
	cout << '(';

	for (int i = 0; i<vc.size() - 1; ++i)
	{
		cout << vc[i] << " ";
	}
	cout << vc[vc.size() - 1] << ")";

}

int CombinationSum(vector<int>&a, int sum)
{
	vector< vector<int> > fv(a.size() + 1, vector<int>(sum + 1, -1));
	unordered_map<int, vector<int> > dict;
	sort(a.begin(), a.end(), greater<int>());
	fv[0][0] = 0;
	for (int i = 0; i <= a.size(); ++i)
	{
		fv[i][0] = 0;
	}
	for (int i = 1; i <= a.size(); ++i)
	{
		for (int v = 1; v <= sum; ++v)
		{
			if ((v - a[i - 1]) >= 0 && -1 != fv[i - 1][v - a[i - 1]])
			{
				fv[i][v] = 0;
				dict[v].push_back(i - 1);
			}
		}
	}

	int i = 0;
	struct st
	{
		int v;
		int i;
	};
	stack<st> s;
	if (dict[sum].size())
	{
		st c;
		c.v = sum;
		c.i = 0;
		s.push(c);
	}
	else
	{
		cout << "Empty" << endl;
		return 0;
	}

	vector<int> vc;
	while (!s.empty())
	{
		if (dict[s.top().v].size() > s.top().i)
		{
			vc.push_back(a[dict[s.top().v][s.top().i]]);
			s.top().i += 1;
			int sd = s.top().v - a[dict[s.top().v][s.top().i]];
			if (0 == sd)
			{
				s.top().i += 1;
				outputCombination(vc);
				vc.pop_back();
				s.pop();
			}
			else
			{
				st c;
				if (dict[sd].size())
				{
					c.v = sd;
					c.i = 0;
					s.push(c);
				}
				else
				{
					s.pop();
					vc.pop_back();
				}
			}
		}
		else
		{
			s.pop();
			vc.pop_back();
		}
	}
	cout << endl;

	return 0;
}


int main(int argc, char const *argv[])
{
	int t = 0;
	cin >> t;

	while (t--)
	{
		int N = 0;
		cin >> N;
		vector<int> a(N, 0);
		int i = 0;
		while (i<N)
		{
			int d = 0;
			cin >> d;
			a[i++] = d;
		}
		int sum = 0;
		cin >> sum;
		CombinationSum(a, sum);
	}


	return 0;
}
