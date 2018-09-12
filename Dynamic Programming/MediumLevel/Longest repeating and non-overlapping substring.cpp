/*
Longest repeating and non-overlapping substring
https://practice.geeksforgeeks.org/problems/longest-repeating-and-non-overlapping-substring/0
https://www.geeksforgeeks.org/longest-repeating-and-non-overlapping-substring/

Given a string str, find the longest repeating non-overlapping substring in it. 
In other words find 2 identical substrings of maximum length which do not overlap. 
If there exists more than one such substring return any of them.

Input:

The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. The first line of each test case contains an integer N denoting the length of the string str.

The second line of each test case contains the string str.It consists of only lower case english alphabets.

Output:
Print the longest non - overlapping substring for each test case in a new line. If no such sub - sequence exists print -1.

Constraints:
1<= T<=100
1<= N <=1000

Example:
Input:

1
13
geeksforgeeks

Output:
geeks

18
kxiksxjecwmkwabhs

*/

/*

                LPS[i-1][j-1] + 1 if x[i+LPS[i-1][j-1]] == x[j + LPS[i-1][j-1]]
LPS[i][j] = 
                LPS[i-1][j-1]

This problem can be solved in O(n^2) time using Dynamic Programming. 
The basic idea is to find the longest repeating suffix for all prefixes in the string str.

*/
/*
Longest repeating and non-overlapping substring
https://practice.geeksforgeeks.org/problems/longest-repeating-and-non-overlapping-substring/0
https://www.geeksforgeeks.org/longest-repeating-and-non-overlapping-substring/

Given a string str, find the longest repeating non-overlapping substring in it.
In other words find 2 identical substrings of maximum length which do not overlap.
If there exists more than one such substring return any of them.

Input:

The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. The first line of each test case contains an integer N denoting the length of the string str.

The second line of each test case contains the string str.It consists of only lower case english alphabets.

Output:
Print the longest non - overlapping substring for each test case in a new line. 
If no such sub - sequence exists print -1.

Constraints:
1<= T<=100
1<= N <=1000

Example:
Input:

1
13
geeksforgeeks

Output:
geeks

1
18
kxiksxjecwmkwabhsl

*/

/*
			LPS[i-1][j-1] + 1 if x[i] == x[j + LPS[j]
LPS[i][j] =
			LPS[i-1][j-1] = 0;

Length of longest non-repeating substring can be recursively
defined as below.

LCSRe(i, j) stores length of the matching and
            non-overlapping substrings ending 
            with i'th and j'th characters.

If str[i-1] == str[j-1] && (j-i) > LCSRe(i-1, j-1)
     LCSRe(i, j) = LCSRe(i-1, j-1) + 1, 
Else
     LCSRe(i, j) = 0

Where i varies from 1 to n and 
      j varies from i+1 to n

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;


int LPS(const string& x)
{
	int max = 0;
	int start = -1;
	int L = x.length();
	vector< vector<int> >  lps(L + 1, vector<int>(L + 1, 0));

	for(int i = 1; i<=L; ++i) //suffix substring
	{
		for(int j =  i+1; j<=L; ++j) // repeating prefix of suffix
		{
			if(x[i-1] == x[j-1] && lps[i-1][j-1]<(j-i) /* not overlapped*/)
			{
				lps[i][j] = lps[i-1][j-1] + 1;
				if(max<lps[i][j])
				{
					max = lps[i][j];
					start = (i)>start? (i):start;
				}
			}
			else
			{
				lps[i][j] = 0;
			}
		}
	}	

	if (-1 == start)
	{
		cout << -1 << endl;
	}
	else
	{
        for (int i = start - max + 1; i <= start; i++) 
        {
            cout<<x[i-1];
        }
		cout << endl;
	}

	return 0;
}


int main(int argc, char const *argv[])
{
	int t = 0;
	int N = 0;

	cin >> t;

	while (t--)
	{
		cin >> N;
		string x;
		cin>>x;
		LPS(x);
		x.clear();
	}

	return 0;
}






string longestRepeatedSubstring(string str) 
{ 
    int n = str.length(); 
    int LCSRe[n+1][n+1]; 
  
    // Setting all to 0 
    memset(LCSRe, 0, sizeof(LCSRe)); 
  
    string res; // To store result 
    int res_length  = 0; // To store length of result 
  
    // building table in bottom-up manner 
    int i, index = 0; 
    for (i=1; i<=n; i++) 
    { 
        for (int j=i+1; j<=n; j++) 
        { 
            // (j-i) > LCSRe[i-1][j-1] to remove 
            // overlapping 
            if (str[i-1] == str[j-1] && 
                LCSRe[i-1][j-1] < (j - i)) 
            { 
                LCSRe[i][j] = LCSRe[i-1][j-1] + 1; 
  
                // updating maximum length of the 
                // substring and updating the finishing 
                // index of the suffix 
                if (LCSRe[i][j] > res_length) 
                { 
                    res_length = LCSRe[i][j]; 
                    index = max(i, index); 
                } 
            } 
            else
                LCSRe[i][j] = 0; 
        } 
    } 
  
    // If we have non-empty result, then insert all 
    // characters from first character to last 
    // character of string 
    if (res_length > 0) 
        for (i = index - res_length + 1; i <= index; i++) 
            res.push_back(str[i-1]); 
  
    return res; 
} 