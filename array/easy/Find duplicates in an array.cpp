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
	bool ans = false;
	for (int i = 0; i<n; i++)
	{
		int index = arr[i]%n;
		if (arr[index] / n == 1)
		{
			ans = true;
			cout << arr[i] % n << ' ';
		}
		arr[index] += n;
	}
	if (!ans)
		cout << -1;
}

int main()
{
	//int a[] = { 0, 3, 1, 2 };
	//int a[] = { 2, 3, 1, 2, 3 };
	int a[] = { 0, 3, 12, 27, 14, 6, 24, 8, 21, 34, 0, 33, 0, 33, 1, 20, 18, 14, 32, 2, 24, 33, 8, 8, 29, 16, 35, 19, 34, 32, 30, 0, 35, 36, 31, 2, 16 };
	printDuplicates(a, _countof(a));
	return 0;
}