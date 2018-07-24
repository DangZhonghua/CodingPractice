/*
Find the largest three elements in an array
https://www.geeksforgeeks.org/find-the-largest-three-elements-in-an-array/
Given an array with all distinct elements, find the largest three elements. Expected time complexity is O(n) and extra space is O(1).

Examples :

Input: arr[] = {10, 4, 3, 50, 23, 90}
Output: 90, 50, 23



*/

#include<iostream>
#include<climits>
using namespace std;


int findLargestThree(int* a, int N)
{
	int first = INT_MIN;
	int second = INT_MIN;
	int third = INT_MIN;

	for (int i = 0; i<N; ++i)
	{
		if (a[i]>first)
		{
			third = second;
			second = first;
			first = a[i];
		}

		else if (a[i]>second)
		{
			third = second;
			second = a[i];
		}
		else if (a[i]>third)
		{
			third = a[i];
		}
	}

	cout << first << " " << second << " " << third << endl;
	return 0;
}


/* Driver program to test above function */
int main()
{
	int arr[] = { 34, 13, 1, 10, 12, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	findLargestThree(arr, n);
	return 0;
}