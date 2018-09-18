/*

Super Ugly Number (Number whose prime factors are in given set)
https://www.geeksforgeeks.org/super-ugly-number-number-whose-prime-factors-given-set/
Super ugly numbers are positive numbers whose all prime factors are in the given prime list.
Given a number n, the task is to find n’th Super Ugly number.

It may be assumed that given set of primes is sorted. Also, first Super Ugly number is 1 by convention.

Examples:

Input  : primes[] = [2, 5]
n = 5
Output : 8
Super Ugly numbers with given prime factors
are 1, 2, 4, 5, 8, ...
Fifth Super Ugly number is 8

Input  : primes[] = [2, 3, 5]
n = 50
Output : 243

Input : primes[] = [3, 5, 7, 11, 13]
n = 9
Output: 21

*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;



int SuperUglyNumber(int Nth, vector<int>& vfactors)
{
	unordered_map<int, int> pfindexmap;
	vector< long long> vu(Nth + 1, 0);
	vector< long long> vc(vfactors.size(), 0);

	std::sort(vfactors.begin(), vfactors.end());

	int index = 0;
	for (int e : vfactors)
	{
		vc[index] = e;
		pfindexmap[index] = 0;
		++index;
	}

	vu[0] = 1; //the first ugly number is 1;

	for (int i = 1; i<Nth; ++i)
	{
		long long minu = LLONG_MAX;
		for (int j = 0; j<vc.size(); ++j)
		{
			if (vc[j] < minu)
			{
				minu = vc[j];
			}
		}
		vu[i] = minu;
		for (int j = 0; j<vc.size(); ++j)
		{
			if (minu == vc[j])
			{
				++pfindexmap[j];
				vc[j] = vu[pfindexmap[j]] * vfactors[j];
			}
		}
	}
	cout << vu[Nth - 1] << endl;


	return 0;
}





int main(int argc, char const *argv[])
{
	vector<int> vf1{ 2, 5 };
	int nth1 = 5;
	SuperUglyNumber(nth1, vf1);

	vector<int> vf2{ 2, 3,5 };
	int nth2 = 50;
	SuperUglyNumber(nth2, vf2);
	vector<int> vf3{ 3, 5, 7, 11, 13 };
	int nth3 = 9;
	SuperUglyNumber(nth3, vf3);


	return 0;
}

