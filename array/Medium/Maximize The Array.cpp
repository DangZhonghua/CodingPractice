/*
Maximize The Array
https://practice.geeksforgeeks.org/problems/maximize-the-array/0

You are given two arrays of numbers. You have to maximize the first array by using the elements
from the second array such that the new array formed contains unique elements.
For example, let the size of array be 'n'.
Then the output should be n greatest but unique elements of both the arrays.
The order of elements should be as explained in example below, i.e., giving the second array priority.

Input:
The first line of each input contains the number of test cases . The description of T test cases follows:
The first line of each test case contains the size of the array (This is going to be the size of both the arrays).
The second line of each test case contains the elements of the first array.
The final line of each test case contains the elements of the second array.

Output:
Print the maximum elements giving second array higher priority.
The order of appearance of elements is kept same in output as in input (See Example for better Understanding).


Constraints:
1 <= T <= 20
1 <= N <= 10
0 <= Array 1 [i] < =9
0 <= Array 2 [i] < =9


Example:

Input:

2
5
7 4 8 0 1
9 7 2 3 6
4
6 7 5 3
5 6 2 9

Output:

9 7 6 4 8
5 6 9 7

*/

/*
7
5 6 9 3 7 4 5
2 5 4 7 4 4 3

Its Correct output is:
2 5 4 7 3 6 9

And Your Code's output is:
2 5 7 4 3 6 9

*/

/*

Use the condition the array element is 1~9. the count sort algorithm like can be applied.
Select larger element from the second array. record its index in auxiliary array.
Suppose the auxiliary is Named C.

C[B[index]] = index
C[A[index]] = 10+index if C[A[index]] is empty.
Select the top N largest elements from the C.
then sort the auxiliary array.

*/


#include<iostream>
#include<algorithm>

using namespace std;

int  MaximizeTheArray(int*a, int*b, int N)
{
	int C[10] = { -1 };
	int r[10] = { -1 };
	// Let's handle the second array since this is the requirement
	for (int i = 0; i < 10; ++i)
	{
		C[i] = -1;
		r[i] = -1;
	}

	for (int i = 0; i < N; ++i)
	{
		if (-1 == C[b[i]])
		{
			C[b[i]] = i;  // the corresponding value locate index i of B
		}	
	}

	//Now let handle the first array.

	for (int i = 0; i < N; ++i)
	{
		if (-1 == C[a[i]])
		{
			C[a[i]] = 10 + i;
		}
	}

	int j = 0;
	for (int i = 9; i >= 0 && j < N; --i)
	{
		if (-1 != C[i])
		{
			r[j++] = C[i];
		}
	}
	std::sort(r, r + N);

	for (int i = 0; i < N; ++i)
	{
		if (r[i] >= 10)
		{
			C[i] = a[r[i] - 10];
		}
		else
		{
			C[i] = b[r[i]];
		}
	}


	for (int i = 0; i < N; ++i)
	{
		cout << C[i] << " ";
	}
	cout << endl;

	return 0;
}

int main()
{
	int t = 0;
	int N = 0;
	int a[10];
	int b[10];

	cin >> t;

	while (t--)
	{
		cin >> N;
		int i = 0;
		while (i < N)
		{
			cin >> a[i++];
		}
		i = 0;
		while (i < N)
		{
			cin >> b[i++];
		}
		MaximizeTheArray(a, b, N);
	}

	return 0;
}