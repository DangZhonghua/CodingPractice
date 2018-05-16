/*

https://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/

https://www.geeksforgeeks.org/print-longest-palindromic-subsequence/

Given a sequence, find the length of the longest palindromic subsequence in it.

longest-palindromic-subsequence

As another example, if the given sequence is “BBABCBCAB”, then the output should be 7 as “BABCBAB” is the longest palindromic subseuqnce in it. “BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence, but not the longest ones.

The naive solution for this problem is to generate all subsequences of the given sequence and find the longest palindromic subsequence. This solution is exponential in term of time complexity. Let us see how this problem possesses both important properties of a Dynamic Programming (DP) Problem and can efficiently solved using Dynamic Programming.


*/

/*

This is dynamatic programming problem? what are the properties(hallmarks) of DP: optimal sub-structure and 
overlapped sub-problems. Optimal sub-structre and overlapped sub-problems characters are problem specifics. 

the key words for this problem: sub-sequence, longest, palindromic.

            LPS[i+1,j-1] + 2,                   if a[i] == a[j]
LPS[i,j] =  
            max{ LPS[i+1][j], LPS[i][j-1]}      otherwise

LPS[0, L] is the result.
            
*/

#include<string>
#include<iostream>
#include<vector>
using namespace std;


int LengthOflps(string& strtext)
{
    int len = strtext.size();
    vector<int> row;
    vector< vector<int> > lps;
    
    for(int i = 0; i<len; ++i)
    {
        row.push_back(0);
    }
    for(int i = 0; i<len; ++i)
    {
        lps.push_back(row);
    }
  

    for(int i = 0; i<len; ++i)
    {
        lps[i][i] = 1;
    }


    for(int l = 2; l<=len; ++l)
    {
        for(int i = 0; i<= len - l; ++i)
        {
            int j = i+l-1;
            if(strtext[i] == strtext[j])
            {
                if(i+1> j-1)
                {
                    lps[i][j] = 2;
                }
                else
                {
                    lps[i][j] = lps[i+1][j-1] + 2;
                }
            }
            else
            {
                lps[i][j] = lps[i+1][j]>lps[i][j-1]? lps[i+1][j]:lps[i][j-1];
            }
        }
    }
    cout<<lps[0][len-1]<<endl;

    return 0;
}

int main()
{
    int     t = 0;
    string  strtext;
    
    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>strtext;
        LengthOflps(strtext);
    }

    return 0;
}