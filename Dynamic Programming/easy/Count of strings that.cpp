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


*/

#include<iostream>
#include<vector>
using namespace std;

int CountOfCombineString(int N)
{
	vector< vector<int> > cst(N + 1, vector<int >(4, 0));

	// 1 for b, 2 for c, 3 for double c.


	cst[1][0] = 3;
	cst[1][1] = 1;
	cst[1][2] = 1;
	cst[1][3] = 0;

	for (int i = 2; i <= N; ++i)
	{
		//Update the total number.
		cst[i][0] = /*a*/  cst[i - 1][0] + /*b*/(cst[i - 1][0] - cst[i - 1][1]) + /*c*/(cst[i - 1][0] - cst[i - 1][3]);
		cst[i][1] = ( /*a*/cst[i - 1][1] + /*c*/cst[i - 1][1] + /*b*/(cst[i - 1][0] - cst[i - 1][1]));
		cst[i][2] = (/*a*/ cst[i - 1][2] + /*b*/cst[i - 1][2] + /*c*/ (cst[i - 1][0] - cst[i - 1][2] - cst[i - 1][3]));
		cst[i][3] = (/*a*/cst[i - 1][3] + /*b*/cst[i - 1][3] + /*c*/ cst[i - 1][2]);
	}

	cout << cst[N][0] << endl;

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
		cout<< (1 + (n * 2) + (n*((n*n) - 1) / 2))<<endl;
	}

	return 0;
}