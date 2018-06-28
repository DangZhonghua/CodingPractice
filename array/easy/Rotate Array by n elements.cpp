/*
Rotate Array by n elements
https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/0/?ref=self
Given an array of size n, rotate it by d elements.

Input: The first line of the input contains T denoting the number of testcases.
First line of test case is the number of elements 'n' and elements 'd' to be rotated.
Second line of test case will be the array elements.
Output: Rotated array is displayed to the user.


Constraints:

1 <=T<= 50
1 <=n<= 100
d<=n
1 <=arr[i]<= 100


Example:

Input:
2
5 2
1 2 3 4 5
10 3
2 4 6 8 10 12 14 16 18 20

Output:
3 4 5 1 2
8 10 12 14 16 18 20 2 4 6

*/

#include<iostream>
#include<vector>
using namespace std;

//O(d) extra space method.
int RotateArrayBydElements(int*a, int N, int d)
{
	vector<int> tb(d, 0);

	for (int i = 0; i < d; ++i)
	{
		tb[i] = a[i];
	}
	for (int i = d; i < N; ++i)
	{
		a[i - d] = a[i];
	}

	for (int i = 0; i < d; ++i)
	{
		a[N - d + i] = tb[i];
	}

	for (int i = 0; i < N; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}


//With O(1) extra space. But it not work, sading 5 mins
int RotateArray(int*a, int N, int d)
{
    for(int i = 0; i<N; ++i)
    {
        int t = a[i];
        if(i+d<N)
        {
            a[i] = a[i+d];
            a[i+d] = t;
        }
        else
        {
            if(i+1<N)
            {
                a[i] = a[i+1] ;
                a[i+1] = t;
            }
        }
    }


    return 0;
}


int main()
{
	int t = 0;
	int a[101] = { 0 };
	int N, d;

	cin >> t;

	while (t--)
	{
		cin >> N >> d;

		int i = 0;

		while (i < N)
		{
			cin >> a[i++];
		}
		RotateArrayBydElements(a, N, d);
	}

	return 0;
}