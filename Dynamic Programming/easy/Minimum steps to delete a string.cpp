/*
Minimum steps to delete a string
https://practice.geeksforgeeks.org/problems/minimum-steps-to-delete-a-string/0/?ref=self
https://www.geeksforgeeks.org/minimum-steps-to-delete-a-string-after-repeated-deletion-of-palindrome-substrings/

Given a string containing characters as integers only. We need to delete all character of this string
in a minimum number of steps where in one step we can delete the substring which is a palindrome.
After deleting a substring remaining parts are concatenated.


Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. The first line of each test case contains an integer N denoting the length of the string.
The second line of each test case contains the string consisting of only integer characters.


Output:
Count the minimum number of steps to delete the whole string and output the answer in a new line.


Constraints:

1<= T <=100
1<= N <=1000


Example:
Input:

1
7
2553432

Output:
2

*/

/*


md[i,j] = min
				{
				1+md[i+1,j],
				md[i+2,k-1] + md[k+1,j], if s[k] == s[i]
				1 + md[i+2,j] if s[i] == s[i+1]
				}


*/


#include<iostream>
#include<vector>
#include<string>
using namespace std;

int MinimumDeletion(string& strText)
{
	int ret = 0;
	int L = strText.length();
	vector< vector<int> > md(L + 1, vector<int>(L + 1, 0));

	for (int i = 0; i<L; ++i)
	{
		md[i][i] = 1;
	}

	for (int l = 2; l <= L; ++l)
	{
		for (int i = 0; i <= L - l; ++i)
		{
			int j = i + l - 1;
			md[i][j] = 1 + md[i + 1][j]; //delete s[i] alone
			if (strText[i] == strText[i + 1] && md[i][j]>1 + md[i + 2][j]) // edge case.
			{
				md[i][j] = 1 + md[i + 2][j];
			}

			/*
			loop over all right characters and suppose Kth char is same as ith character 
			then choose minimum from current and two substring after ignoring ith and Kth char
			*/

			for (int k = i + 2; k<=j; ++k)
			{
				if (strText[i] == strText[k] && md[i][j]>(md[i + 1][k - 1] + md[k + 1][j]))
				{
					md[i][j] = md[i + 1][k - 1] + md[k + 1][j];
				}
			}
		}
	}

	cout << md[0][L - 1] << endl;


	return ret;
}


int main(int argc, char const *argv[])
{
	string x = "2553432";
	//MinimumDeletion(x);
	int t = 0;
	
	cin>>t;

	while (t--)
	{
		int N = 0;
		cin>>N;
		string x;
		cin>>x;
		MinimumDeletion(x);
	}

	return 0;
}
