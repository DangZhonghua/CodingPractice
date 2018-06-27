/*
Consecutive 1's not allowed
https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed/0/?ref=self
Count number of binary strings without consecutive 1’s

Problem Description:
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s.
Output your answer mod 10^9 + 7.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contain an integer N representing length of the binary string.

Output:
Print the count number of binary strings without consecutive 1’s of length N.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:
Input:
2
3
2

Output:
5
3

Explaination:
For first test case 5 strings are (000, 001, 010, 100, 101)
For second test case 3 strings are (00,01,10)

*/

/*

C[N][0] = C[N-1][1] + C[N-1][0];
C[N][1] = C[N-1][0]

total = C[N][0] + C[N][1];
*/

#include<iostream>
#include<vector>
using namespace std;


int nMod = 1000000007;


int CountNonConsecutiveBinaryString(int N)
{
	vector< vector<unsigned long long> > C(N + 1, vector<unsigned long long>(2, 0));

	C[1][0] = 1;
	C[1][1] = 1;

	for (int i = 2; i <= N; ++i)
	{
		C[i][0] = (C[i - 1][0]% nMod + C[i - 1][1]% nMod)% nMod;
		C[i][1] = C[i-1][0]% nMod;
	}
	unsigned long long total = (C[N][0]% nMod + C[N][1]% nMod)% nMod;

	total %= nMod;

	cout << total << endl;

	return 0;
}


int main()
{
	int t = 0;
	int N = 0;

	cin >> t;

	while (t--)
	{
		cin >> N;
		CountNonConsecutiveBinaryString(N);
	}


	return 0;
}