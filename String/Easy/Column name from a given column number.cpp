/*
Column name from a given column number
https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number/0/?ref=self
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
MS Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc.
In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA”.

Input:

The first line of each input consists of the test cases. And, the second line consists of a number N.

Output:

In each separate line print the corresonding column title as it appears in an Excel sheet.

Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 4294967295

Example:

Input:

2
28
13

Output:

AB
M

2044897764
FPBUZQZ
*/

#include<iostream>
#include<vector>
using namespace std;

int CalcColumnName(unsigned long long N)
{
	int len = 1;
	unsigned long long c = 26;
	unsigned long long clen = 26;
	unsigned long long prec = 0;
	unsigned long long vleft = 0;
	vector<unsigned long long> vc;
	vector<char> vcol;
	vc.push_back(1);
	vc.push_back(26);

	//Calculate the the target length.
	while (c < N)
	{
		clen *= 26;
		vc.push_back(clen);
		prec = c;
		c += clen;		
		++len;
	}

	vleft = N - prec;
	
	if (1 == len)
	{
		vcol.push_back('A' + N- 1);
	}
	else
	{
		int i = len;
		while (i)
		{
			// if (i == 1)
			// {
			// 	vcol.push_back('A' + vleft - 1);
			// 	break;
			// }
			// Judge the the which letter at position i;
			if (vleft / vc[i - 1])
			{
				if (vleft % vc[i - 1]) //left is the i-1 char number.
				{
					vcol.push_back(vleft / vc[i - 1] + 'A');
					vleft %= vc[i - 1];
				}
				else
				{
					vcol.push_back(vleft / vc[i - 1] + 'A' - 1);
					if (vleft / vc[i - 1] > i - 1) 
					{
						vleft -= (vleft / vc[i - 1]  -1)*vc[i - 1]; // the left count
					}
					
				}
				
			}
			else //since this is not beyond the previou char count
			{
				vcol.push_back('A');
			}
			--i;
		}
	}

	for (int i = 0; i < vcol.size(); ++i)
	{
		cout << vcol[i];
	}
	cout << endl;


	return 0;
}

int main()
{
	int t = 0;
	unsigned long long N = 0;

	cin >> t;

	while (t--)
	{
		cin >> N;
		CalcColumnName(N);
	}

	return 0;
}