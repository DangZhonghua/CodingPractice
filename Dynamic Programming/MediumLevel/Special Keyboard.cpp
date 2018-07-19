/*
Special Keyboard
https://practice.geeksforgeeks.org/problems/special-keyboard/0/?ref=self

Imagine you have a special keyboard with the following keys:
Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it
after what has already been printed.

If you can only press the keyboard for N times (with the above four keys),
write a program to produce maximum numbers of A's.
That is to say, the input parameter is N (No. of keys that you can press),
the output is M (No. of As that you can produce).

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the number of key.

Output:

Print maximum number of A's.  Print -1, if N is greater than 75.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 75

Example:

Input:
2
3
7

Output:
3
9

Explanation:

Input:  N = 3
Output: 3
We can at most get 3 A's on screen by pressing
following key sequence.
A, A, A

Input:  N = 7
Output: 9
We can at most get 9 A's on screen by pressing
following key sequence.
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V


*/

/*
C[i-1] + 1  if presss A

C[i] =  Max   C[i-1]      if press Ctrl-A

C[i-1]      if press Ctrl-C

C[i-3]*2    if press Ctrl-V

C[i-1]+ CountByCopied[i-1]


*/

#include<iostream>
#include<vector>
using namespace std;

int maximumSeq(int N)
{
	// according to the problem description
	if (N > 75)
	{
		cout << "-1" << endl;
		return 0;
	}

	vector<long long> SK(N + 1, 0);
	vector<long long> BC(N + 1, 0);
	SK[1] = 1;

	for (int i = 1; i < N; ++i)
	{
		if (SK[i + 1] < SK[i] + 1)
		{
			SK[i+1] = SK[i] + 1;
			BC[i + 1] = BC[i];
		}
		
		if (i + 3 <= N)
		{
			if (SK[i + 3] <= SK[i] * 2)
			{
				SK[i + 3] = SK[i] * 2;
				BC[i + 3] = SK[i];
			}
		}
		if (i + BC[i] <= N)
		{
			if (SK[i + BC[i]] <= SK[i] + BC[i])
			{
				SK[i + BC[i]] = SK[i] + BC[i];
				BC[i + BC[i]] = BC[i];
			}
		}


	}

	cout << SK[N] << endl;

	return 0;
}


int main()
{
	int t = 0;
	int N = 0;

	cin >> t;

	while (t--)
	{
		cin >> N;
		maximumSeq(N);
	}

	return 0;
}