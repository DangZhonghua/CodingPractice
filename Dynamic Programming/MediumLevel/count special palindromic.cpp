/*
count special palindromic 
https://practice.geeksforgeeks.org/problems/count-special-palindromic/0

Given a String s, count all special palindromic substrings of size greater than 1. 
A Substring is called special palindromic substring 
if all the characters in the substring are same or 
only the middle character is different for odd length.Example “aabaa” and “aaa” are special palindromic 
substrings and “abcba” is not a special palindromic substring.

Input: the first line of input contains integer T denoting the number of test cases. Each test case contains string S.
Output:
For each test case, print count of special palindromic substrings.
Constraints:

1<=T<=100

1<=N<=10^5
Example:

INPUT:
2
abab
aaba

OUTPUT:
2
2

explanation :
tese case 1 : All Special Palindromic substring size > 1 are : "aba", "bab" 

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int CountSps(const string& strtxt)
{
    int N = strtxt.size();
    int nCount = 0;
    vector< vector<bool> > cps(N+1,vector<bool>(N+1,false));
    
    for(int i = 0; i<N; ++i)
    {
        cps[i][i] = true;
    }
    
    for(int l = 2; l<=N; ++l)
    {
        for(int i = 0; i<=N-l; ++i)
        {
            int j = i+l-1;
            if(strtxt[i] == strtxt[j])
            {
                if(2 == l)
                {
                    ++nCount;
                    cps[i][j] = true;
                }
                else
                {
                    if(cps[i+1][j-1])
                    {
                        if(l>3)
                        {
                            if(strtxt[i] == strtxt[i+1])
                            {
                                cps[i][j] = true;
                                ++nCount;
                            }
                        }
                        else
                        {
                            cps[i][j] = true;
                            ++nCount;
                        }
                    }
                }
            }
        }
    }

    cout<<nCount<<endl;

    return 0;
}



int main(int argc, char const *argv[])
{
    int t = 0;
    string strtxt;
    
    cin>>t;
    
    while(t--)
    {
        cin>>strtxt;
        CountSps(strtxt);
    }

    return 0;
}
