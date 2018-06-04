/*
Close to Perfection
https://practice.geeksforgeeks.org/problems/close-to-perfection/0/?ref=self

Geek likes this girl Garima from his neighborhood, and wants to impress her so that she may go on a date with him. Garima is a Perfectionist and likes only PERFECT things .This makes Geek really nervous, and so Geek asks for your Help.!
Geek has baked a cake for Garima, which is basically an array of Numbers. Garima will take only a Perfect Piece of the cake.
A Perfect Piece is defined as - a subarray such that the difference between the minimum and the maximum value in that range is at most 1. Now, Since garima just loves cake, She wants a Perfect Piece Of Maximum length possible. Help Geek go on a date.!

Input
The first line of the input contains an integer T denoting the number of test cases.

The first line of each test case contains an integer n-denoting the length of the array.
The second line contains n space separated integers -denoting the cake

Output
For each testcase, output a single line containing the maximum Possible length of the subarray which is a Perfect piece


Constraints

1 ≤ T ≤ 100
1 ≤ n ≤ 1 000
1 ≤ Ai ≤ 1000


Example

Input:
3
4
8 8 8 8
5
1 2 3 3 2
11
5 4 5 5 6 7 8 8 8 7 6

Output:
4
4
5


Explanation

Example case 1. The longest subarray is [1, 4] where maximum=8 and minimum = 8 and difference is 0,which is less than 1. Its length is 4.

Example case 2. 1-based indexing. The longest subarray is [2, 5] where maximum=3 and minimum is 2 and difference is 1. Its length is 4.

Example case 3. The longest subarray is [6, 10] where maximum=8 and minimum is 7 and difference is 1. Its length is 5.


*/

#include<iostream>
using namespace std;

int CalcPerfectionMaxLen(int*a, int N)
{
	int i = 0;
	int j = 1;
	int small = 0;
	int big = 0;
	int maxlen = 1;

	while (j<N)
	{
		if (a[small] == a[j])
		{
			small = j;
			if (a[big] == a[j])
			{
				big = j;
			}
		}
		else if (a[big] == a[j])
		{
			big = j;
		}
		//Just update the small or big index.
		else
		{
			if (a[small] == a[big])  //when they are the same, the new coming may become the small or big.
			{
				if (a[small]<a[j])
				{
					if (a[j] - a[small] <= 1)
					{
						big = j;
					}
					else  //Find the segment
					{
						if (maxlen<j - i)
						{
							maxlen = j - i;
						}
						i = j;
						small = j;
						big = j;
					}
				}
				else
				{
					if (a[small] - a[j] <= 1)
					{
						small = j;
					}
					else
					{
						if (maxlen<j - i)
						{
							maxlen = j - i;
						}
						i = j;
						small = j;
						big = j;
					}
				}
			}
			else
			{
				if (maxlen<j - i)
				{
					maxlen = j - i;
				}
				if (a[j] <a[small])
				{
					if (a[small] - a[j]>1)
					{
						i = j;
						small = j;
						big = j;
					}
					else
					{
						i = big + 1;
						big = small;
						small = j;
					}
				}
				else if (a[j]>a[big])
				{
					if (a[j] - a[big]>1)
					{
						i = j;
						small = j;
						big = j;
					}
					else
					{
						
						i = small + 1;
						small = big;
						big = j;
					}
				}
			}
		}
		++j;
	}

	if (maxlen<j - i)
	{
		maxlen = j - i;
	}
	cout << maxlen << endl;

	return 0;
}

int main()
{
	int t = 0;
	int N = 0;
	int a[1001] = { 0 };

	cin >> t;
	while (t--)
	{
		cin >> N;
		int i = 0;

		while (i<N)
		{
			cin >> a[i++];
		}
		CalcPerfectionMaxLen(a, N);
	}



	return 0;
}