/*
https://leetcode-cn.com/problems/decode-ways-ii/
Decode Ways II

 A message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
C->3
D->4
E->5
F->6
G->7
H->8
I->9
J->10
...
'Z' -> 26

Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

Also, since the answer may be very large, you should return the output mod 10^9 + 7.

Example 1:

Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".

Example 2:

Input: "1*"
Output: 9 + 9 = 18

Note:

	The length of the input string will fit in range [1, 10^5].
	The input string will only contain the character '*' and digits '0' - '9'.
*/


/*

need handle special number "0"

*/

#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution
{
public:
	int numDecodings(string s)
	{
		long long mode = 1e9 + 7;

		int N = s.length();
		vector<long long> dw(N + 1, 0);
		dw[0] = 1;

		for (int i = 1; i <= N; ++i)
		{
			if ('*' == s[i - 1])
			{
				if (i < N) //for s[i] == '0' case
				{
					if (s[i] == '0')
					{
						dw[i] += dw[i - 1] * 2;
					}
					else
					{
						dw[i] += dw[i - 1] * 9;
					}
				}
				else
				{
					dw[i] += dw[i - 1] * 9;
				}
				
				dw[i] %= mode;
			}
			else
			{
				if( '0' != s[i-1])
				dw[i] += dw[i - 1];
				dw[i] %= mode;
			}

			if (i >= 2)
			{
				if ('*' == s[i - 2])
				{
					//treat the "*" as 1
					if ('0' <= s[i - 1] && '9' >= s[i - 1])
					{
						dw[i] += dw[i - 2];
						dw[i] %= mode;
					}

					if ('0' <= s[i - 1] && '6' >= s[i - 1])
					{
						dw[i] += dw[i - 2];
						dw[i] %= mode;
					}

					if ('*' == s[i - 1])
					{
						dw[i] += dw[i - 2] * 15;
						dw[i] %= mode;
					}
				}
				else
				{
					if ('*' == s[i - 1])
					{
						if ('1' == s[i - 2])
						{
							if (i <= N && '0' != s[i-1])
							{
								dw[i] += dw[i - 2] * 9;
							}
							
							dw[i] %= mode;
						}
						else if ('2' == s[i - 2])
						{
							if (i <= N && '0' != s[i])
							{
								dw[i] += dw[i - 2] * 6;
								dw[i] %= mode;
							}
						}
					}
					else
					{
						if (('1' == s[i - 2] && s[i - 1] <= '9') || ('2' == s[i - 2] && s[i - 1] <= '6'))
						{
							dw[i] += dw[i - 2];
							dw[i] %= mode;
						}
					}
				}
			}

		}
		return dw[N];
	}
};

int main()
{
	Solution sol;
	string s = "2*";

	cout << sol.numDecodings(s) << endl;

	return 0;

}