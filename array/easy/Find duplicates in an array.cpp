/*
Find duplicates in an array
https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1/?ref=self
https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/
https://www.geeksforgeeks.org/duplicates-array-using-o1-extra-space-set-2/

Given an array A[], Your task is to complete the function printDuplicates which prints
the duplicate elements of the given array. If no duplicate element is found  print -1.

Note: Auxiliary Space must be O(1) and Time complexity must be O(n).

Input:
The first line of input contains an integer T denoting the no of test cases.
Then T test cases follow. Each test case contains an integer N
which denotes number of elements of Array. Second line of each test case contains
N space separated integers denoting elements of Array A[].

Output:
Print the duplicate elements from the array.The order of the output should be as the element found to be repeated.

Constraints:
1<=T<=100
1<=N<=50
0<=A[]<N

Example:
Input:
2
4
0 3 1 2
5
2 3 1 2 3
Output:
-1
2 3

*/

/*

(Use array elements as index)
4
0 3 3 3

5
0 3 1 0 3

*/


/*
1- Traverse the given array from i= 0 to n-1 elements
Go to index arr[i]%n and increment its value by n.
3- Now traverse the array again and print all those
indexes i for which arr[i]/n is greater than 1.

This approach works because all elements are in range
from 0 to n-1 and arr[i]/n would be greater than 1
only if a value "i" has appeared more than once.


*/


#include <iostream>
using namespace std;



// void printDuplicates(int arr[], int n)
// {
//    //add code here.
//    bool bfind = false;
//     for(int i = 0; i<n; ++i)
//     {
//       int index = arr[i]%n;
//       arr[index] +=n;

//     }

//     for(int i = 0; i<n; ++i)
//     {
//         if(arr[i]/n>1)
//         {
//             cout<<i<<" ";
//             bfind = true;
//         }
//     }

//     if(!bfind)
//     {
//         cout<<-1;
//     }
//     //cout<<endl;

// }



void printDuplicates(int arr[], int n)
{
	//add code here.
	bool bfind = false;
	for (int i = 0; i<n; ++i)
	{
		int v = arr[i];
		v &= 0X0000FFFF;
		int index = v%n;

		int hindex = arr[index];
		hindex &= 0XFFFF0000;
		if (0 == hindex)
		{
			hindex = i + 1;
			hindex <<= 16;
		}
		v = arr[index];
		v &= 0x0000FFFF;
		v += n;
		arr[index] = (v | hindex);
	}

	

	for (int i = 0; i<n; ++i)
	{
		int v = arr[i];
		int index = (0XFFFF0000 & arr[i]);
		index >>= 16;
		v &= 0X0000FFFF;
		v = (0X0000FFFF & arr[i]);
		if (v / n>1)
		{
			arr[index - 1] = i;
			bfind = true;
		}
		else
		{
			arr[index - 1] = n;
		}
	}

	if (!bfind)
	{
		cout << -1;
	}
	else
	{
		for (int i = 0; i<n; ++i)
		{
			if (arr[i] < n)
			{
				cout << arr[i] << " ";
			}
		}
	}
	//cout<<endl;

}

int main()
{
	//int a[] = { 0, 3, 1, 2 };
	int a[] = { 2, 3, 1, 2, 3 };
	printDuplicates(a, _countof(a));
	return 0;
}