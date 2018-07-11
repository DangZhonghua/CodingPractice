/*
Merge k Sorted Arrays
https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

Given K sorted arrays arranged in a form of a matrix, your task is to merge them. You need to complete
mergeKArrays function which takes 2 arguments, an arr[k][k] 2D Matrix containing k sorted arrays
and an integer k denoting the no. of sorted arrays.
The function should return a pointer to the merged sorted arrays.
There are multiple test cases. For each test case, this method will be called individually.

Input:
The first line of input will denote the no of Test cases then T test cases will follow .
Each test cases will contain an integer N denoting the no of sorted arrays.
Then in the next line contains all the elements of the array separated by space.

Output:
The output will be the sorted merged array.

Constraints
1<=T<=50
1<=N<=10

Example:

Input
1
3

1 2 3 4 5 6 7 8 9

Output:
1 2 3 4 5 6 7 8 9

Explanation
above test case has 3 sorted arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],

[4, 5, 6],

[7, 8, 9]]
The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9]

*/

#include<iostream>
#include<queue>
#include<functional>
using namespace std;

#define N 10

// your task is to complete this function
// function should return an pointer to output array int*
// of size k*k

struct AP
{
	int value;
	int arrindex;
	int index;
	bool operator >(const struct AP& rhs) const
	{
		return value>rhs.value;
	}
};


int* mergeKArrays(int arr[][N], int k)
{
	int* a = new int [k*k];

	priority_queue<AP, vector<AP>, std::greater<AP> > minHeap;

	for (int i = 0; i<k; ++i)
	{
		AP ae;
		ae.value = arr[i][0];
		ae.arrindex = i;
		ae.index = 0;
		minHeap.push(ae);
	}

	int i = 0;
	while (!minHeap.empty())
	{
		AP at = minHeap.top();
		a[i++] = at.value;
		minHeap.pop();
		if ((at.index + 1)<k)
		{
			++at.index;
			at.value = arr[at.arrindex][at.index];
			minHeap.push(at);
		}
	}

	return a;
}