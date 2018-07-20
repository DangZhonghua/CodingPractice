/*
Special Keyboard
https://practice.geeksforgeeks.org/problems/special-keyboard/0/?ref=self
https://www.geeksforgeeks.org/how-to-print-maximum-number-of-a-using-given-four-keys/

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

Below are few important points to note.
a) For N < 7, the output is N itself. b) Ctrl V can be used multiple times to print current buffer (See last two examples above). 
The idea is to compute the optimal string length for N keystrokes by using a simple insight. 
The sequence of N keystrokes which produces an optimal string length will end with a suffix of Ctrl-A, a Ctrl-C, 
followed by only Ctrl-V's (For N > 6).
The task is to find out the break=point after which we get the above suffix of keystrokes. 
Definition of a breakpoint is that instance after which we need to only press Ctrl-A, Ctrl-C once and 
the only Ctrl-V’s afterwards to generate the optimal length. If we loop from N-3 to 1 and choose each of these 
values for the break-point, and compute that optimal string they would produce. Once the loop ends, 
we will have the maximum of the optimal lengths for various breakpoints, thereby giving us the optimal length for N keystrokes.

Input:  N = 11
Output: 27
We can at most get 27 A's on screen by pressing 
following key sequence.
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V, Ctrl A, 
Ctrl C, Ctrl V, Ctrl V


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

	if(N<7)
	{
		cout<<N<<endl;
		return 0;
	}

	vector<long long> SK(N + 1, 0);
	for(int i = 1; i<7; ++i)
	{
		SK[i] = i;
	}	


	for (int i = 7; i <= N; ++i)
	{
		long long max = 0;
		for(int b = i-3; b>=1; --b)
		{
			long long  cur = (i-b-1)*SK[b];
			if(cur>max)
			{
				max = cur;
			}
		}
		SK[i] = max;
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