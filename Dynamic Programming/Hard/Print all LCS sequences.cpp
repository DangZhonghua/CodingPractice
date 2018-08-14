/*
Print all LCS sequences
https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences/0
https://www.geeksforgeeks.org/print-longest-common-sub-sequences-lexicographical-order/
You are given two strings a and b. Now your task is to print all longest common sub-sequences in lexicographical order.

Input:
The first line of input contains an integer denoting the no of test cases T. Then T test case follow each test case contains 2 space separated strings a and b.

Output:
For each test case in a new line  print the space separated sequences.

Constraints:
1<=T<=100
1<=length of strings a and b<=100

Example:
Input:
2
abaaa baabaca
aaa a
Output:
aaaa abaa baaa
a

*/


/*                1+LCS[i-1, j-1] if szx[i] == szy[j]

    LCS[i,j] =    max{LCS[i-1,j], LCS[i,j-1]} if(sz[i] ! = sz[j])

                  0 if i = 0 or j = 0;


*/


#include<iostream>
#include<vector>
using namespace std;


enum en_td 
{
    INVALID,
    DIG,
    LEFT,
    UPPER
};

struct CS
{
    int i = 0;
    int j = 0;
    bool bd[]{false};
};


int LCS(char* szx, char* szy,vector< vector<int> >& lcs,vector< vector<int> >& lds)
{
    //Init the lcs according to the formula.
    for(int r = 0; r<lcs.size(); ++r)
    {
        lcs[r][0] = 0;
    }
    for(int c = 0; c<lcs[0].size(); ++c)
    {
        lcs[0][c] = 0;
    }

    int m  = lcs.size();
    int n  = lcs[0].size();
    
    //Calc the lcs length.
    
    for(int i = 1; i<m; ++i)
    {
        for(int j = 1; j<n; ++j)
        {
            if(szx[i] == szy[j])
            {
                lcs[i][j] = lcs[i-1][j-1] + 1;
                lds[i][j] = DIG;
            }
            else
            {
                if(lcs[i-1][j]>lcs[i][j-1])
                {
                    lds[i][j] = UPPER;
                    lcs[i][j] = lcs[i-1][j];
                }
                else
                {
                    lds[i][j] = LEFT;
                    lcs[i][j] = lcs[i][j-1];
                }
            }
        }
    }

    return 0;
}


int formlcs(char* szx, vector< vector<int> >& lds)
{
    int m  = lds.size()-1;
    int n  = lds[0].size()-1;
    
    





    return  0;
}



int printLCS(char* szx, char* szy)
{
    int m = strlen(szx+1);
    int n = strlen(szy+1);
    
    vector< vector<int> > lcs(m+1, vector<int>(n+1, 0) ); 
    vector< vector<int> > lds(m+1, vector<int>(n+1, 0) );
    //1. Calculate the LCS first.
    LCS(szx, szy, lcs, lds);
    
    //cout<<lcs[m][n]<<endl;


    return 0;
}


int main()
{
    int t = 0;
    char szx[200];
    char szy[200];
    
    cin>>t;
    
    while(t--)
    {
        cin>>szx+1;
        cin>>szy+1;
        printLCS(szx,szy);
    }

    return 0;
}
