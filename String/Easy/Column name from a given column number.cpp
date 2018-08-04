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


//This is 26 进制， like 10进制



/*

https://www.geeksforgeeks.org/find-excel-column-name-given-number/

Suppose we have a number n, let’s say 28. 
so corresponding to it we need to print the column name. We need to take remainder with 26.

If remainder with 26 comes out to be 0 (meaning 26, 52 and so on) then we put ‘Z’ 
in the output string and new n becomes n/26 -1 
because here we are considering 26 to be ‘Z’ while in actual it’s 25th with respect to ‘A’.

Similarly if the remainder comes out to be non zero. 
(like 1, 2, 3 and so on) then we need to just insert the char accordingly in the string and do n = n/26.

Finally we reverse the string and print.

// Function to print Excel column name for a given column number
void printString(int n)
{
    char str[MAX]; // To store result (Excel column name)
    int i = 0; // To store current index in str which is result
 
    while (n>0)
    {
        // Find remainder
        int rem = n%26;
 
        // If remainder is 0, then a 'Z' must be there in output
        if (rem==0)
        {
            str[i++] = 'Z';
            n = (n/26)-1;
        }
        else // If remainder is non-zero
        {
            str[i++] = (rem-1) + 'A';
            n = n/26;
        }
    }
    str[i] = '\0';
 
    // Reverse the string and print result
    reverse(str, str + strlen(str));
    cout << str << endl;
 
    return;
}


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