/*

String formation from substring

https://practice.geeksforgeeks.org/problems/string-formation-from-substring/0

Given a string ‘str’, check if it can be constructed by taking a substring of it and appending 
multiple copies of the substring together.  
For example "abab" can be created by appending "ab" to "ab",
 but "abac" cannot be created by appending a substring to itself.

Input:
The first line contains T denoting the number of test cases. 
Then follows description of testcases. Each case contains a string.


Output:
For each test case, output "True" if it is possible and "False" if not.
 

Constraints:
1<=T<=100
1<=Length of String<=1000 
 
Example:
Input:
1
abcabcabc

Output:
True

Explanation :
The given string is 3 times repetition of "abc"


*/

/*

Initially, the pattarn  range is [s,e] s =0 & e = 0
How to build the pattarn: i is the forward index, j is the forward index for the pattarn.

// the basic idea is: if there is mismatched pointed. reset the pattatn to the start index.


if(X[i] == X[j]): { ++i; ++j}  if(j > e) j = s(0);
if(X[i] != X[j]): 
{ 
    if(j == 0) // the first char of pattarn is mismatched, only way is to extend the pattarn by the current char
    {
        e = i; j = s;
    }
    else  // the at some middle index of pattarn is mismatched, need reset the range to check again.
    {
        --i;(make sure the current compare with the pattarn starting char)
        e = i;
        j = s;
        
    }
}

*/




#include<string>
#include<iostream>
using namespace std;

int PattarnFormString(const string& X)
{
	int s = 0;
	int e = 0;
	int i = 1;
	int j = 0;

	for (i = 1; i<X.length(); ++i)
	{
		if (X[i] == X[j])
		{
			++j;
			if (j > e)
			{
				j = s;
			}
		}
		else
		{
			if (0 == j)
			{
				e = i;
				j = s;
			}
			else
			{
				j = s;
				--i;
				e = i;
			}

		}
	}
	if (X.length() % (e - s + 1) == 0 && X.length() != (e - s + 1))
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}

	return 0;
}



int main(int argc, char const *argv[])
{
	/* code */
	int t = 0;
	string strtext;

	cin >> t;

	while (t--)
	{
		cin >> strtext;
		PattarnFormString(strtext);
	}


	return 0;
}