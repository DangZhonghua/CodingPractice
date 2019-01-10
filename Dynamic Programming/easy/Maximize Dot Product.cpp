/*
https://practice.geeksforgeeks.org/problems/maximize-dot-product/0/?ref=self
Maximize Dot Product

Given a array A with N elements and array B with M elements. You have to insert (N-M) zeroes in
between array B such that the dot product of array A and array B is maximum.

Definition of Dot Product : A.B = A[0]*B[0] + A[1]*B[1]+....A[N]*B[N].

Input :
The first line will contain T which denotes the number of test cases.
The first line of each test case will contain integer N and M, denoting the length of array A and array B respectively.
The second line of each test case will contain N integers denoting the elements of array A.
The third line of each test case will contain M integers denoting the elements of array B.


Output:
For each test case, Output the maximized dot product in a new line .


Constraints :
1<=T<=10
1<= N,M<=1000
0<=A[i],B[i]<=10^7


Example
Input :

1
3 1
1 2 3
4

Output :
12
*/

/*
p[i,j] = max{p[i-1,j-1]+a[i]*b[j], p[i,j-1]}
*/

#include<vector>
#include<iostream>
#include<climits>
using namespace std;

int  MaximizeProduct(vector<long long int>& a, vector<long long int>& b)
{
	int ret = 0;
	vector< vector<long long int> > p(b.size() + 1, vector<long long int>(a.size() + 1, 0));

	for (int i = 0; i <= b.size(); ++i)
	{
		p[i][0] = 0;
	}
	for (int j = 0; j <= a.size(); ++j)
	{
		p[0][j] = 0;
	}

	for (int i = 1; i <= b.size(); ++i)
	{
		for (int j = i; j <= a.size(); ++j) //from j = i is important, this is implict constriant
		{
			p[i][j] = p[i][j - 1];
			if (p[i - 1][j - 1] + b[i - 1] * a[j - 1] > p[i][j])
			{
				p[i][j] = p[i - 1][j - 1] + b[i - 1] * a[j - 1];
			}
		}
	}
	cout << p[b.size()][a.size()] << endl;

	return ret;
}

int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		int n = 0;
		int m = 0;
		cin >> n >> m;
		vector<long long int> a(n, 0);
		vector<long long int> b(m, 0);
		int i = 0;
		while (i < n)
		{
			cin >> a[i];
			++i;
		}
		i = 0;
		while (i < m)
		{
			cin >> b[i];
			++i;
		}
		MaximizeProduct(a, b);
	}
	//vector<int> a{ 1,2,3 };
	//vector<int> b{ 4 };
	//MaximizeProduct(a, b);

	return 0;
}
