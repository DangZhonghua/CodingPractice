/*
https://www.geeksforgeeks.org/print-shortest-common-supersequence/
Shortest Common Supersequence

Given two strings X and Y, print the shortest string that has both X and Y as subsequences. If multiple shortest supersequence exists, print any one of them.

Examples:

Input: X = "AGGTAB",  Y = "GXTXAYB"
Output: "AGXGTXAYB" OR "AGGXTXAYB" 
OR Any string that represents shortest
supersequence of X and Y

Input: X = "HELLO",  Y = "GEEK"
Output: "GEHEKLLO" OR "GHEEKLLO"
OR Any string that represents shortest 
supersequence of X and Y

*/


/*

             SCS[i-1][j-1] + 1 if x[i] == y[j] 
SCS[i][j] =  min{SCS[i-1][j]+1 ##this is add x[i] case ##, SCS[i][j-1] + 1 ##this is add y[j] case ##} if x[i] != y[j]
             SCS[0][j] = j
             SCS[i][0] = i;

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int ShortestCommonSuperSequence(const string& x, const string& y)
{
    vector< vector<int> > scs(x.length()+1, vector<int>(y.length()+1,x.length()+y.length()+1));
    vector< vector<int> > ss(x.length()+1, vector<int>(y.length()+1,x.length()+y.length()+1));
    string strscs;
    for(int j = 0; j<y.length() + 1; ++j)
    {
        scs[0][j] = j;
        ss[0][j] = 'y';
    }
    for(int i = 0; i<x.length() +1; ++i)
    {
        scs[i][0] = i;
        ss[i][0] = 'x';
    }
    
    for(int i = 1; i<x.length()+1; ++i)
    {
        for(int j = 1; j<y.length()+1; ++j)
        {
            if(x[i-1] == y[j-1])
            {
                scs[i][j] = scs[i-1][j-1]+1;
                ss[i][j] = 'c';
            }
            else
            {
                scs[i][j] = scs[i-1][j] + 1;
                ss[i][j]  = 'x';
                if(scs[i][j]>scs[i][j-1] + 1)
                {
                    scs[i][j] = scs[i][j-1] + 1;
                    ss[i][j] = 'y';
                }
            }
        }
    }
    
    int i = x.length();
    int j = y.length();
    while(i>0 || j>0)
    {
        if('c' == ss[i][j])
        {
            strscs += x[i];
            --i;
            --j;
        }
        else if ('x' == ss[i][j])
        {
            strscs += x[i];
            --i;
        }
        else if('y' == ss[i][j])
        {
            strscs += y[j];
            --j;
        }
    }
    std::reverse(strscs.begin(), strscs.end());

    cout<<strscs<<endl;
    return 0;
}

int main()
{
    string x = "AGGTAB";
    string y = "GXTXAYB";
    ShortestCommonSuperSequence(x,y);

    return 0;
}