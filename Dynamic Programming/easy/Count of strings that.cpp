/*
Count of strings that can be formed using a, b and c under given constraints
https://practice.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints/0

https://www.geeksforgeeks.org/count-strings-can-formed-using-b-c-given-constraints/

Given a length n, count the number of strings of length n that can be made using ‘a’, ‘b’ and ‘c’
with at-most one ‘b’ and two ‘c’s allowed.



Input:

The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. The first line of each test case contains
an integer N denoting the length of the string.


Output:

Output the count of the strings that can be formed under the given constraint.


Constraints:

1<= T <=100

1<= N <=1000


Example:

Input:

2

1

3

Output:

3

19

*/

/*

C[N][a] will record the total number.

C[N][a]     = a*C[N-1] + b*(C[N-1][a]- C[N-1][b]) + c*(C[N-1][a]-C[N-1][2c])
C[N][b]     = a*C[N-1][b]+ b*(C[N-1][a]- C[N-1][b]) + c*C[N-1][b]
C[N][c]     += c*(C[N-1][a]-C[N-1][2c]);
C[N][2c]    += c*(C[N-1][c]);
https://careercup.appspot.com/question?id=5717453712654336

cst[1][0][0] = 1; //only a
cst[1][0][1] = 1; // only c
cst[1][0][2] = 0; // no double c

cst[1][1][0] = 1; //only b
cst[1][1][1] = 0; // no b and c
cst[1][1][2] = 0; // no b and 2c

*/

#include<iostream>
#include<vector>
using namespace std;

int CountOfCombineString(int N)
{
	int cst[1001][2][3];
	memset(cst, 0, sizeof(cst));

	cst[1][0][0] = 1; //only a
	cst[1][0][1] = 1; // only c
	cst[1][0][2] = 0; // no double c

	cst[1][1][0] = 1; //only b
	cst[1][1][1] = 0; // no b and c
	cst[1][1][2] = 0; // no b and 2c


	for (int i = 2; i <= N; ++i)
	{
		for (int k = 'a'; k<'d'; ++k)
		{
			if (k == 'a')
			{
				cst[i][0][0] = cst[i - 1][0][0];
				cst[i][0][1] = cst[i - 1][0][1];
				cst[i][0][2] = cst[i - 1][0][2];
				cst[i][1][0] = cst[i - 1][1][0];
				cst[i][1][1] = cst[i - 1][1][1];
				cst[i][1][2] = cst[i - 1][1][2];

			}
			else if (k == 'b')
			{
				cst[i][1][0] += cst[i - 1][0][0];
				cst[i][1][1] += cst[i - 1][0][1];
				cst[i][1][2] += cst[i - 1][0][2];
			}
			else if (k == 'c')
			{
				cst[i][0][1] += cst[i - 1][0][0];
				cst[i][1][1] += cst[i - 1][1][0];
				cst[i][0][2] += cst[i - 1][0][1];
				cst[i][1][2] += cst[i - 1][1][1];
			}
		}
	}

	int count = 0;
	for (int i = 0; i<2; ++i)
	{
		for (int j = 0; j<3; ++j)
		{
			count += cst[N][i][j];
		}
	}
	cout << count << endl;;
	return 0;
}


int main()
{
	int t = 0;
	int n = 0;

	cin >> t;

	while (t--)
	{
		cin >> n;
		CountOfCombineString(n);
		//cout << (1 + (n * 2) + (n*((n*n) - 1) / 2)) << endl;
	}

	return 0;
}