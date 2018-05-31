/*
https://practice.geeksforgeeks.org/problems/palindromic-patitioning/0
https://www.geeksforgeeks.org/dynamic-programming-set-17-palindrome-partitioning/
Palindromic patitioning 

Given a string, a partitioning of the string is a palindrome partitioning 
if every sub-string of the partition is a palindrome. 
For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. 
Determine the fewest cuts needed for palindrome partitioning of a given string. 
For example, minimum 3 cuts are needed for “ababbbabbababa”. 
The three cuts are “a|babbbab|b|ababa”.

Input:
The first line of input contains an integer T, denoting the number of test cases. 
Then T test cases follow. The first line of every Test Case consists of S, denoting a String.

Output:
For each test case in a new line print an integer, denoting the number cuts in the String to make it palindromic.

Constraints:
1<=T<=100
1<=|Length of String|<=1000

Example:
Input:
2
ababbbabbababa
aaabba

Output:
3
1

*/


/*


*/


#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;

bool IsPalindromicString(const string& strtxt, int i, int j,  vector< vector<int> >& psp)
{
    bool bPalindromic = false;
    if((j-i+1) == 2)
    {
        if(strtxt[i] == strtxt[j])
        {
            bPalindromic = true;
        }
    }
    else
    {
        if( strtxt[i] == strtxt[j] && psp[i+1][j-1] == 0)
        {
            bPalindromic = true;
        }
    }

    return bPalindromic;
}




//Matrix chain multiply extension.
//This is O(N^3) solution
int PalindromicPartition(string& strtext)
{
    int N = strtext.size();
    vector< vector<int> > psp(N+1,vector<int>(N+1,0));


    for(int l = 2; l<=N; ++l)
    {
        for(int i = 0; i<=N-l; ++i)
        {
          int j = i+l-1;
          psp[i][j] = INT_MAX;
          for(int k = i; k<j; ++k)
          {
              if(IsPalindromicString(strtext, i,j,psp))
              {
                  psp[i][j] = 0;
                  break;
              }
              else
              {
                  if(psp[i][j] > (psp[i][k] + psp[k+1][j] + 1) )
                  {
                    psp[i][j] = (psp[i][k] + psp[k+1][j] + 1);
                  }         
              }
          }
        }
    }

    cout<<psp[0][N-1]<<endl;

    return 0;
}


// This is O(n^2) solution
bool IsPalindromicString(const string& strtxt, int i, int j,  vector< vector<bool> >& psp)
{
    bool bPalindromic = false;
    if((j-i+1) == 2)
    {
        if(strtxt[i] == strtxt[j])
        {
            bPalindromic = true;
        }
    }
    else
    {
        if( strtxt[i] == strtxt[j] && psp[i+1][j-1])
        {
            bPalindromic = true;
        }
    }

    return bPalindromic;
}
int OptPalindromicPartition(string& strtext)
{
    int N = strtext.size();
    vector< vector<bool> > psp(N+1,vector<bool>(N+1,false));
    vector<int> mincut(N+1,0);

    for(int i = 0; i<N; ++i )
    {
        psp[i][i] = true;
    }

    for(int l = 2; l<=N; ++l)
    {
        for(int i = 0; i<=N-l; ++i)
        {
          int j = i+l-1;
  
            if(IsPalindromicString(strtext, i,j, psp))
            {
                psp[i][j] = true;             
            } 
        }
    }
    
    for(int i = 0; i<N; ++i)
    {
        if(psp[0][i])
        {
            mincut[i] = 0;
        }
        else
        {
            mincut[i] = INT_MAX;
            for(int j = 0; j<i; ++j)
            {
                if(psp[j+1][i] && (1+mincut[j] /* since j is less than i, mincut[j] has been calculated*/)< mincut[i])
                {
                    mincut[i] = (1+mincut[j]);
                }

            }
        }
    }
    
    cout<<mincut[N-1]<<endl;

 return 0;
}

int  main()
{
    int t = 0;
    string strtext;
    
    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>strtext;
        OptPalindromicPartition(strtext);
    }

    return 0;
}