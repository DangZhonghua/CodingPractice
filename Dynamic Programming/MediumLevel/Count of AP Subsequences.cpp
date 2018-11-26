
/*
Given an array A[] of n positive integers. The task is to count the number of Arithmetic Progression subsequence in the array.

Note: Empty sequence or single element sequence is Arithmetic Progression. 

Examples:

Input : A[] = { 1, 2, 3 }
Output : 8
Arithmetic Progression subsequence from the 
given array are: {}, { 1 }, { 2 }, { 3 }, { 1, 2 },
{ 2, 3 }, { 1, 3 }, { 1, 2, 3 }.

Input : A[] = { 10, 20, 30, 45 }
Output : 12

Input : A[] = { 1, 2, 3, 4, 5 }
Output : 23

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer n denoting size of the array. Then in the next line are n space separated values of the array.

Output:
For each test case in a new line print the required output.

Constraints:
1<=T<=100
1<=n<=100
1<=A[]<=100

Example:
Input:
2
3
1 2 3
4
10 20 30 45
Output:
8
12
*/

//#define MAX 1000001 
//
//#include<iostream>
//#include<climits>
//#include<cstdlib>
//#include<cstdio>
//#include<functional>
//#include<vector>
//using namespace std;
//
//
//int dp[MAX], sum[MAX];
//
//int numofAP(int a[], int n)
//{
//	// initializing the minimum value and 
//	// maximum value of the array. 
//	int minarr = INT_MAX, maxarr = INT_MIN;
//
//	// Finding the minimum and maximum 
//	// value of the array. 
//	for (int i = 0; i < n; i++)
//	{
//		minarr =  minarr<a[i] ? minarr : a[i];
//		maxarr = maxarr<a[i] ? a[i]:maxarr;
//	}
//
//	// dp[i] is going to store count of APs ending with arr[i]. 
//	// sum[j] is going to store sum of all dp[]'s with j as an AP element. 
//
//	// Initialize answer with n + 1 as single elements and empty array are also DP. 
//	int ans = n + 1;
//
//	// Traversing with all common difference. 
//	for (int d = (minarr - maxarr); d <= (maxarr - minarr); d++)
//	{
//		memset(sum, 0, sizeof (sum));
//
//		// Traversing all the element of the array. 
//		for (int i = 0; i < n; i++)
//		{
//			// Initialize dp[i] = 1. 
//			dp[i] = 1;
//
//			// Adding counts of APs with given differences and a[i] is last element.   
//			// We consider all APs where an array element is previous element of AP with a particular  difference 
//			if (a[i] - d >= 1 && a[i] - d <= 1000000)
//				dp[i] += sum[a[i] - d];
//
//			ans += dp[i] - 1;
//			sum[a[i]] += dp[i];
//		}
//	}
//
//	return ans;
//}
//
//// Driver code 
//int main()
//{
//	int arr[] = { 87, 93, 50, 22, 63, 28, 91, 60, 64, 27, 41, 27, 73, 37, 12, 69 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	cout << numofAP(arr, n) << endl;
//	return 0;
//}

/*

1
16
87 93 50 22 63 28 91 60 64 27 41 27 73 37 12 69


1
15
87 93 50 22 63 28 91 60 64 27 41 73 37 12 69

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int CountAP(vector<int>&a)
{
	long long count = 1 + a.size(); // 1 for empty set
	//It should not sort the array since this will modify the array.
	int minVal = INT_MAX;
	int maxVal = INT_MIN;

	for (int v : a)
	{
		if (minVal > v)
		{
			minVal = v;
		}
		if (maxVal < v)
		{
			maxVal = v;
		}
	}

	int d = 0;
	int maxd = maxVal - minVal;
	int mind = -maxd;

	vector< vector<int> > PAP(a.size(), vector<int>(maxd + 1, 0));
	vector< vector<int> > NAP(a.size(), vector<int>(maxd + 1, 0));

	for (int j = 1; j < a.size(); ++j)
	{
		for (int i = 0; i < j; ++i)
		{
			d = a[j] - a[i];
			if (d >= 0)
			{
				PAP[j][d] += (PAP[i][d] + 1);
				count += PAP[j][d];
			}
			else if (d<0)
			{
				NAP[j][-d] += (NAP[i][-d] + 1);
				count += NAP[j][-d];
			}
		}
	}
	cout << count << endl;

	return 0;
}

int main(int argc, char const *argv[])
{
	int t = 0;

	cin >> t;
	while (t--)
	{
		int N = 0;
		cin >> N;
		vector<int>  a(N, 0);
		int i = 0;
		while (i < N)
		{
			cin >> a[i];
			++i;
		}
		CountAP(a);
	}

	return 0;
}

