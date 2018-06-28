/*
Tom and Jerry 
https://practice.geeksforgeeks.org/problems/tom-and-jerry/0
https://www.geeksforgeeks.org/dynamic-programming-set-31-optimal-strategy-for-a-game/

Since very long time Tom and Jerry have been fighting with each other for a piece of Cheese. 
So finally you came to rescue and decided that the result of the fight will be decided by a mathematical game , 
in which you will write a number N . Tom and Jerry will play the game alternatively 
and each of them would subtract a number n [n< N] such that N%n=0. 
The game is repeated turn by turn until the one,who now cannot make a further move looses the game. 
The game begins with Tom playing first move.It is well understood that both of them will make moves in optimal way.
You are to determine who wins the game.

Input

The first line of input contains a single integer T denoting the number of test cases.
Then T test cases follow. The first line of each test case consists of N the number.

Output

Print 1 if Tom wins and Print 0 if Jerry wins in a separate line.

Constraints

1<= T<=100 

1 <= N <= 10^6

Sample Input

2 
2 
4

Sample Output

1 
1
*/

/*

 win[i] = !(win[i-j]& win[i-k]...) j and k are these number that can divide by i and thess than i. 

*/

#include<iostream>
#include<vector>
using namespace std;

int TomCat(int N)
{
	//vector<bool>  vwin(N + 1, false);
	bool vwin[100001] = {false};

    

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 1; j <= i/2; ++j)
		{
			if (0 == (i%j) && !vwin[i - j])
			{
				vwin[i] = true;
				break;
			}
		}
	}

	cout << (vwin[N] ? 1 : 0) << endl;

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
		TomCat(N);
	}


	return 0;
}