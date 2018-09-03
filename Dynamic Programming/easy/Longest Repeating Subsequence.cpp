/*

https://www.geeksforgeeks.org/longest-repeated-subsequence/
https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0

Longest Repeating Subsequence 

Given a string str, find length of the longest repeating subseequence such that 
the two subsequence don’t have same string character at same position, i.e., any i’th character 
in the two subsequences shouldn’t have the same index in the original string.

Input:

The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. The first line of each test case contains an integer N denoting the length of string str.

The second line of each test case contains the string str consisting only of lower case english alphabets.

Output:

Print the length of the longest repeating subsequence for each test case in a new line.


Constraints:

1<= T <=100

1<= N <=1000


Example:

Input:

2

3
abc
5
axxxy

Output:

0
2

*/

/*

This problem is just the modification of Longest Common Subsequence problem. The idea is to find the LCS(str, str) where str 
is the input string with the restriction that when both the characters are same, they shouldn’t be on the same index in the two strings. 


*/




#include<iostream>
#include<vector>
#include<string>
using namespace std;

int longestRepeatSubSequence(const string& strx)
{
    vector< vector<int> > lrs(strx.length()+1, vector<int>(strx.length()+1,0));
    
    for(int i =  1; i <=strx.length(); ++i)
    {
        for(int j = 1; j<= strx.length(); ++j)
        {
            if(strx[i-1] == strx[j-1] && i != j)
            {
                lrs[i][j] = lrs[i-1][j-1] + 1;
            }
            else
            {
                lrs[i][j] = lrs[i-1][j]>lrs[i][j-1]? lrs[i-1][j]:lrs[i][j-1];
            }
        }
    }
    cout<<lrs[strx.length()][strx.length()]<<endl;

	return 0;
}

int main(int argc, char const *argv[])
{
	string x = "axxxy";
	string y = "aabb";
	//longestRepeatSubSequence(x);
	//longestRepeatSubSequence(y);
    
    int t = 0;
    int N = 0;

    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int i = 0;
        string x;
        while(i<N)
        {
            char c;
            cin>>c;
            x.push_back(c);
            ++i;
        }
        longestRepeatSubSequence(x);
    }


	return 0;
}