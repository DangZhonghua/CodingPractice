/*
Count number of increasing subsequences of size k
https://www.geeksforgeeks.org/count-number-increasing-subsequences-size-k/

Given an array arr[] containing n integers. The problem is to count number of increasing subsequences in the array of size k.

Examples:

Input : arr[] = {2, 6, 4, 5, 7},
k = 3
Output : 5
The subsequences of size '3' are:
{2, 6, 7}, {2, 4, 5}, {2, 4, 7},
{2, 5, 7} and {4, 5, 7}.

Input : arr[] = {12, 8, 11, 13, 10, 15, 14, 16, 20},
k = 4
Output : 39

*/

/*
CIS[i][k] += CIS[j][k-1] if a[i]>a[j] for all j < i

*/

#include<iostream>
#include<vector>
using namespace std;

int CountISofK(vector<int>& a, int K)
{
	int ret = 0;
	vector< vector<int> > CIS(a.size(), vector<int>(K + 1, 0));

	if (1 == K)
	{
		cout<<a.size()<<endl;
		return ret;
	}


	for (int i = 0; i<a.size(); ++i)
	{
		CIS[i][1] = 1; // for single element. 
	}

	for (int i = 1; i<a.size(); ++i)
	{
		for (int j = 0; j<i; ++j)
		{
			if (a[j]<a[i])
			{
				for (int k = K; k > 1; --k)
				{
					if (CIS[j][k - 1])
					{
						CIS[i][k] += CIS[j][k - 1];
					}
				}
			}
		}
	}
	int count = 0;

	for (int i = 0; i<a.size(); ++i)
	{
		count += CIS[i][K];
	}

	cout << count << endl;

	return ret;
}


int main(int argc, char const *argv[])
{
	vector<int> a{ 2, 6, 4, 5, 7 };
	vector<int> b{ 12, 8, 11, 13, 10, 15, 14, 16, 20 };
	CountISofK(a, 3);
	CountISofK(b, 4);
	return 0;
}
