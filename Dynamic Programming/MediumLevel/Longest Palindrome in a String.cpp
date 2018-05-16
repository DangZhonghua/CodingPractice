/*
Longest Palindrome in a String 

https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0

Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[ i . . . . j ] where 0 ≤ i ≤ j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Input:

The first line of input consists number of the test cases. The following T lines consist of a string each.


Output:

In each separate line print the longest palindrome of the string given in the respective test case.


Constraints:

1 ≤T≤ 100
1 ≤ str≤ 100


Example:

Input:

1
aaaabbaa

Output:

aabbaa



*/

/*
Dynamic Programming: overlapped sub-problem and optimal sub-structure.

                0  if 0 == lpstring[i+1, j-1] 
lpstring[i,j] = 
                0  if s[i] != s[j]

                lpstring[i+1,j-1] +2  if s[i] == s[j] 
 

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;


int lpsSubstring(string& strtext)
{
    int maxlen = 1;
    int s = 0;
    int e = 0;

    int N = strtext.size();
    
    vector<int> row(N,1);
    vector< vector<int> > m(N, row);

    
    
    for(int l = 2; l<= N; ++l)
    {
        for(int i = 0; i<N-l+1; ++i)
        {
            int j = i+l-1;
            if(strtext[i] == strtext[j])
            {
                if(i+1 > j-1)
                {
                    m[i][j] = 2;
                    if(m[i][j]>maxlen)
                    {
                        maxlen = m[i][j];
                        s = i;
                        e = j;
                    }
                }
                else
                {
                    if(0 == m[i+1][j-1])
                    {
                        m[i][j] = 0;
                    }
                    else
                    {
                        m[i][j] = m[i+1][j-1]+2;
                        if(m[i][j]>maxlen)
                        {
                            maxlen = m[i][j];
                            s = i;
                            e = j;
                        }
                        
                    }
                }
            }
            else
            {
                m[i][j] = 0;    
            }
        }
    }

    for(int i = s; i<=e; ++i)
    {
        cout<<strtext[i];
    }
    cout<<endl;

    return 0;
}

int main()
{
    int t = 0;
    string strtext;

    cin>>t;

    while(t>0)
    {
        --t;
        cin>>strtext;
        lpsSubstring(strtext);
        strtext.clear();
    }


    return 0;
}