/*
Brackets in Matrix Chain Multiplication
https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication/0

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications. There are many options to multiply a chain of matrices because matrix multiplication is associative i.e. no matter how one parenthesize the product, the result will be the same.

Example:
if you had four matrices A, B, C, and D, you would have:

(ABC)D = (AB)(CD) = A(BCD) = ....

However, the order in which one parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency.

For example:

A: 10 × 30 matrix
B : 30 × 5 matrix
C : 5 × 60 matrix
Then,
(AB)C = (10×30×5) + (10×5×60)
= 1500 + 3000
= 4500 operations
A(BC) = (30×5×60) + (10×30×60)
= 9000 + 18000
= 27000 operations.

Given an array arr[] which represents the chain of matrices such that the ith matrix Ai is of dimension arr[i-1] x arr[i].
Your task is to write a program that should print the optimal way to multiply the matrix chain such that minimum number of multiplications operations are needed to multiply the chain. Represent first matrix as starting Alphabet of the english dictionary i.e. 'A', and the rest so on.

Input: p[] = {40, 20, 30, 10, 30}
Output: Optimal parenthesization is  ((A(BC))D)
There are 4 matrices of dimensions 40x20,
20x30, 30x10 and 10x30. Let the input 4
matrices be A, B, C and D.  The minimum
number of multiplications are obtained
by putting parenthesis in following way
(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

Input: p[] = {10, 20, 30, 40, 30}
Output: Optimal parenthesization is (((AB)C)D)
There are 4 matrices of dimensions 10x20,
20x30, 30x40 and 40x30. Let the input 4
matrices be A, B, C and D.  The minimum
number of multiplications are obtained by
putting parenthesis in following way
((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

Input:
The first line of the input contains an integer T, denoting the number of test cases. Then T test case follows.
The first line of each test case contains an integer N, denoting the number of elements in the array.
Then next line contains N space separated integers denoting the values of the element in the array.

Output:
For each test case the print the minimum number of operations needed to multiply the chain.

Constraints:
1<=T<=100
2<=N<=27
1<=A[]<=500

Example:
Input:
2
5
1 2 3 4 5
3
3 3 3
Output:
(((AB)C)D)
(AB)


*/

#include<iostream>
#include<vector>
#include<climits>
#include<string>
using namespace std;



int BuildExpress(string& strexp, vector< vector<int> >& sc, int s, int e)
{
	if (s == e)
	{
		strexp += ('A' + s);
		return 0;
	}
	strexp += "(";

	BuildExpress(strexp, sc, s, sc[s][e]);
	BuildExpress(strexp, sc, sc[s][e] + 1, e);
	strexp += ")";


	return 0;
}



int outputMatrixMultiplyChain(vector< vector<int> >& sc, int N)
{
	string strexp;

	BuildExpress(strexp, sc, 0, N - 1);

	cout << strexp << endl;

	return 0;
}


int BracketsOfMatrixChainMultiplication(int*a, int N)
{
	vector< vector<int> > mc(N + 1, vector<int>(N + 1, INT_MAX));
	vector< vector<int> > sc(N + 1, vector<int>(N + 1, -1));

	for (int i = 0; i<N; ++i)
	{
		mc[i][i] = 0;
	}

	for (int l = 2; l <= N; ++l) // the matrix multiply chain length.
	{
		for (int i = 0; i <= N - l; ++i)
		{
			int j = i + l - 1;
			for (int k = i; k< j; ++k)
			{
				if (mc[i][j]>(mc[i][k] + mc[k + 1][j] + a[i] * a[k + 1] * a[j + 1]))
				{
					mc[i][j] = (mc[i][k] + mc[k + 1][j] + a[i] * a[k + 1] * a[j + 1]);
					sc[i][j] = k;
				}
			}
		}
	}


	outputMatrixMultiplyChain(sc, N);

	return 0;
}

int main()
{
	int t = 0;
	int N = 0;
	int a[30];

	cin >> t;
	while (t--)
	{
		cin >> N;
		int i = 0;
		while (i<N)
		{
			cin >> a[i++];
		}
		BracketsOfMatrixChainMultiplication(a, N - 1);
	}



	return 0;
}