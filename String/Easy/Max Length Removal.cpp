/*
Max Length Removal
https://practice.geeksforgeeks.org/problems/max-length-removal/0/?ref=self

Given a binary string (consists of only 0 and 1). If there is “100” as a sub-string in the string, 
then we can delete this sub-string. 
The task is to find the length of longest sub-string which can be make removed?

Examples:

Input  : str = "1011100000100"
Output : 6
// Sub-strings present in str that can be make removed 
// 101{110000}0{100}. First sub-string 110000-->100-->null,
// length is = 6. Second sub-string 100-->null, length is = 3

Input  : str = "111011"
Output : 0
// There is no sub-string which can be make null

Input:

The first line of input contains a single integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of one line. The line contains a string of 0's and 1's.

Output:

Length of the longest string that can be removed.

Constraints:

1 ≤ T ≤ 100
1 ≤ string length ≤ 1000

Example:

Input
2
010010
1011110000

1
01110010101010011001000111001

1
100111100111110011100001111101111110000


Output
3
6
*/

/*

 use extra O(n) space to record the subtring range.

*/

#include<string>
#include<iostream>
#include<vector>
using namespace std;

int maxLengthRemoval(const string&  sztext)
{
	//used to record the actual index of element in sztext even though removal.
	vector<int> vkeep(sztext.size() + 1, 0); 
	int maxlen = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < sztext.size(); ++i)
	{
		if ('1' == sztext[i])
		{
			vkeep[j] = i;
			++j;
		}
		else if ('0' == sztext[i]) //this is valuable tricky code piece.
		{
			//Detect the removable substring.
			if (j < 2)
			{
				vkeep[j] = i;
				++j;
				continue;
			}
			int k = j - 1;
			if ('1' == sztext[vkeep[k]])
			{
				vkeep[j] = i;
				++j;
				continue;
			}
			else if ('0' == sztext[vkeep[k]])
			{
				if ('1' == sztext[vkeep[k - 1]])
				{
					// Now, we check this removal substring whether contrenate the previous.
					int s = k - 1;
					if (k - 2 >= 0)
					{
						s = k - 2;
						if (i - vkeep[s]>maxlen)
						{
							maxlen = i - vkeep[s];
						}
					}
					else
					{
						if (i - vkeep[s] + 1>maxlen)
						{
							maxlen = i - vkeep[s] + 1;
						}
					}
	
					j = k - 1;
				}
				else
				{
					vkeep[j] = i;
					++j;
				}		
			}
		}
	}

	cout << maxlen << endl;

	return 0;
}

int main()
{
	int t = 0;
	string sztext;

	cin >> t;

	while (t--)
	{
		cin >> sztext;
		maxLengthRemoval(sztext);
	}


	return 0;
}