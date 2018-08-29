/*

https://practice.geeksforgeeks.org/problems/missing-element-of-ap/0/?ref=self

Missing element of AP
Find the missing element from  an ordered array A[ ], consisting of N elements representing an Arithmetic Progression (AP) .
 

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains an integer N, where N is the size of the array A[ ].
The second line of each test case contains N space separated integers of an Arithmetic Progression denoting elements of the array A[ ].
 

Note: The series should have a missing element in between a perfect A.P. with no missing element will not be considered.
 

Output:
Print out the missing element. 
 

Constraints:
1 <= T <= 100
2 <= N <= 10
-50 <= A[i] <=50
 

Examples :

Input:
3
3 
2 10 14 
4 
-28 -21 -7 0 
5 
9 12 15 21 24

Output : 
6
-14
18
*/

#include<iostream>
#include<vector>
using namespace std;

int findMissing(vector<int>&a)
{
	int bd = 0;
	int sd = 0;
	int firstindex = 0;
	int secondindex = 0;
	int t = 0;

	for (int i = 1; i<a.size(); ++i)
	{
		if (0 == bd)
		{
			bd = a[i] - a[i - 1];
			firstindex = i - 1;
		}
		else if (0 == sd)
		{

			sd = a[i] - a[i - 1];
			if (sd != bd) // look for different diff.
			{
				secondindex = i - 1;
			}
			else
			{
				sd = 0;
			}
			
		}
		else
		{
			break;
		}
	}

///////////////////////////////// dealing with array size == 2 case
	if (sd == 0)
	{
		sd = bd/2;
	}
	else if (bd == 0)
	{
		bd = sd/2;
	}
////////////////////////////
	int  d = bd>sd ? (bd - sd) : (sd - bd);

	if (bd > sd)
	{
		t = a[firstindex] + d;
	}
	else
	{
		t = a[secondindex] + d;
	}

	cout << t << endl;

	return 0;
}


int main(int argc, char const *argv[])
{
	int t = 0;
	int N = 0;

	cin >> t;

	while (t--)
	{
		cin >> N;
		vector<int> a(N, 0);
		int i = 0;
		while (i<N)
		{
			int d;
			cin >> d;
			a[i++] = d;
		}
		findMissing(a);
	}

	return 0;
}