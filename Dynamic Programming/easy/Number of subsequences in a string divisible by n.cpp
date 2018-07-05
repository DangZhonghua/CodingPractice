/*
Number of subsequences in a string divisible by n
https://practice.geeksforgeeks.org/problems/number-of-subsequences-in-a-string-divisible-by-n/0
https://www.geeksforgeeks.org/number-subsequences-string-divisible-n/

Given a string consisting of digits 0-9, count the number of subsequences in it divisible by n.


Input:

The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow.
The first line of each test case contains an integer M and N where M denotes the length of the numeric string.
The second line of each test case contains the numeric string.


Output:

Output the number of subsequences dicisible by N. Since the number can be quite large print the answer modulo 10^9+7.

Constraints:

1<= T <=100

1<= M <=1000

1<= N <=1000

Example:

Input:
2
4 4
1234
3 6
330
Output:
4
4
*/

/*

This problem can be recursively defined. Let remainder of a string with value x be 'r' when divided with n.
Adding one more character to this string changes its remainder to (r*10 + newdigit) % n.
For every new character, we have two choices, either add it in all current subsequences or ignore it.
Thus, we have an optimal substructure. 


C[N] = C[N-1][nth selected] + C[N-1][nth not selected]
C[N][reminder]:C[i][r]: means: the processed number is i.

C[N][0] is the result.

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int gMode = 1000000007;

int CountDivisible(const string& strnum, int N)
{
	int M = strnum.length();
	vector< vector<int> > C(M + 1, vector<int>(N + 1, 0));
	// the bottom point is C[0][0] = 0 which means there is no digital and no count
	C[0][(strnum[0] - '0') % N] = 1; // the new sequence started from index 0.


	// this is the digital number.
	for (int i = 1; i < M; ++i) 
	{
		C[i][(strnum[i]-'0')%N] = 1; // the new sequence started from index i.
		//this is reminder range, we need every possible reminder.
		for (int r = 0; r < N; ++r) 
		{
			// Now, the i-th digital is excluded.
			C[i][r] += C[i - 1][r];
			C[i][r] %= gMode;
			//Yes, the i-th digital is selected.
			if (C[i - 1][r]) // This make sure the reminder r has been reached by previous "i-1" digital
			{
				int sr = (r * 10 + strnum[i] - '0') % N;
				C[i][sr] += C[i - 1][r];
				C[i][sr] %= gMode;
			}
		}
	}

	cout << C[M-1][0]<<endl;

	return 0;
}



int main(int argc, char const *argv[])
{
	int t = 0;
	int M = 0;
	int N = 0;
	string strnum;

	cin >> t;

	while (t--)
	{
		cin >> M >> N;
		cin >> strnum;
		CountDivisible(strnum, N);
	}

	return 0;
}

