/*
Distinct palindromic substrings 
https://practice.geeksforgeeks.org/problems/distinct-palindromic-substrings/0/?ref=self

Given a string of lowercase ASCII characters, 
find all distinct continuous palindromic sub-strings of it.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case contains a string.

Output:
Print the count of distinct continuous palindromic sub-strings of it.

Constraints:
1<=T<=10^5
1<=length of string<=10^5

Example:
Input:
2
abaaa
geek

Output:
5
4
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;


int CountDistPalinString(char* sztxt, int N)
{
    vector< vector<bool > > lps( N+1, vector<bool>(N+1, false));
    unordered_map<char*, int > dict;

    for(int i = 0; i<N; ++i)
    {
        lps[i][i] = true;
    }

    for(int  l = 2; l<=N; ++l)
    {
        for(int i = 0; i<=N-l; ++i)
        {
            int j = i+l-1;
            if(sztxt[i] != sztxt[j])
            {
                continue;
            }
            if(2 == l)
            {
                lps[i][j] = true;
            }
            else
            {
                lps[i][j] = lps[i+1][j-1];
            }
        }
    }

int ncount = 0;
    for(int i = 0; i<N; ++i)
    {
        for(int j = i; j<N; ++j)
        {
            if(lps[i][j])
            {
                ++ncount;
                char t = sztxt[j+1];
                sztxt[j+1] = '\0';
                auto it = dict.find(sztxt+i);
                if(it == dict.end())
                {
                    dict[sztxt+i] = 1;
                }
                sztxt[j+1] = t;
            }
        }
    }

    cout<<dict.size()<<endl;

    
    return 0;
}

int main()
{
    int t = 0;
    string strtxt;

    cin>>t;

    while(t--)
    {
        cin>>strtxt;
        CountDistPalinString((char*)strtxt.c_str(),strtxt.size());
    }


    return 0;
}