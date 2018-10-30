/*
Combination Sum
https://practice.geeksforgeeks.org/problems/combination-sum/0

Given an array of integers A and a sum B, find all unique combinations in A where the sum is equal to B.
The same repeated number may be chosen from A unlimited number of times.
Note:
All numbers will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
If there is no combination possible the print "Empty" (without qoutes).
Example,
Given A = 2,4,6,8 and B(sum) = 8,
A solution set is:

[2, 2, 2, 2]
[2, 2, 4]
[2, 6]
[4, 4]
[8]

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
3
4
7 2 6 5
16
11
6 5 7 1 8 2 9 9 7 7 9
6
4
5 2 2 6
3

Output:
(2 2 2 2 2 2 2 2)(2 2 2 2 2 6)(2 2 2 5 5)(2 2 5 7)(2 2 6 6)(2 7 7)(5 5 6)
(1 1 1 1 1 1)(1 1 1 1 2)(1 1 2 2)(1 5)(2 2 2)(6)
Empty
*/


/*
this can be done by using dynamic programming or backtracking technique.





*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void OutputCombination(vector<int>& vc)
{
    int i = 0;
	cout << "(";
	for(i = 0; i<vc.size()-1; ++i)
	{
	    cout<<vc[i]<<" ";
	}
	cout <<vc[i]<<")";
}

void btCombinationSum(vector<int>& a, vector<int>& vc, int index, int sum, bool& bFind)
{

	for (int i = index; i<a.size(); ++i)
	{
		if (sum >= a[i])
		{
			sum -= a[i];
			vc.push_back(a[i]);
			if (0 == sum)
			{
				bFind = true;
				OutputCombination(vc);
			}
			else
			{
				btCombinationSum(a, vc, i, sum,bFind);
			}
			vc.pop_back();
			sum += a[i];
		}
		else
		{
			break;
		}
	}

}


int CombinationSum(vector<int>&a, int sum)
{
	vector<int> vc;
	bool bFind = false;
	std::sort(a.begin(), a.end());
	
	vector<int> b;
	b.push_back(a[0]);
	int j = 0;
	for(int i = 1; i<a.size(); ++i)
	{
	    if(a[i] == b[j])
	    {
	        continue;
	    }
	    else
	    {
	        b.push_back(a[i]);
	        ++j;
	    }
	}
	
	btCombinationSum(b, vc, 0,sum, bFind);
	if (!bFind)
	{
		cout << "Empty" << endl;
	}
	else
	{
		cout << endl;
	}
	return 0;
}


int main()
{
	int t = 0;
	cin >> t;

	while (t--)
	{
		int N = 0;
		int Sum = 0;
		cin >> N;
		vector<int> a(N, 0);
		int i = 0;
		while (i < N)
		{
			cin >> a[i];
			++i;
		}
		cin >> Sum;
		CombinationSum(a, Sum);
	}

	return 0;
}