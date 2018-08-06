/*
Edit Distance
https://practice.geeksforgeeks.org/problems/edit-distance/0/?ref=self
Given two strings str1 and str2 and below operations that can performed on str1. 
Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

    Insert
    Remove
    Replace

All of the above operations are of cost=1.
Both the strings are of lowercase.

Input:
The First line of the input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each tese case consists of two lines. 
The first line of each test case consists of two space separated integers P and Q denoting 
the length of the strings str1 and str2 respectively. 
The second line of each test case coantains two space separated strings str1 and str2 in order.


Output:
Corresponding to each test case, pirnt in a new line, the minimum number of operations required.

Constraints:
1<=T<=50
1<= Length(str1) <= 100
1<= Length(str2) <= 100
 

Example:
Input:
1
4 5
geek gesek

Output:
1

*/

/*
                    ed[i-1][j-1]  if x[i] == y[j]     

ed[i][j] =  min {
                  ed[i-1][j] + 1 //for remove
                  ed[i-1][j-1] + 1 //for replace
                  ed[i][j-1] + 1 // for insert
                }

*/


#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;


int editDistance(const string& x, const string& y)
{
    int R = x.length(); 
    int C = y.length();
    vector< vector<int> > ed(R+1,vector<int>(C+1,INT_MAX));

    //if y is empty.
    for(int i = 0; i<=R; ++i)
    {
        ed[i][0] = i; //just removing
    }
    //if x is empty
    for(int i = 0; i<=C; ++i)
    {
        ed[0][i] = i; //just insert
    }
    
    for(int i = 1; i<=R; ++i)
    {
        for(int j = 1; j<=C; ++j)
        {
            if(x[i-1] == y[j-1])
            {
                ed[i][j] = ed[i-1][j-1];
            }
            else
            {
                if(ed[i-1][j] + 1<ed[i][j]) //for remove
                {
                    ed[i][j] = ed[i-1][j] + 1;
                }
                if(ed[i-1][j-1] + 1 < ed[i][j]) // for replace
                {
                    ed[i][j] = ed[i-1][j-1] + 1;
                }
                if(ed[i][j-1] + 1 < ed[i][j]) // for insert
                {
                    ed[i][j] = ed[i][j-1] + 1;
                }
            }
        }
    }

    cout<<ed[R][C]<<endl;

 return 0;
}


int main()
{
    int t;
    int M = 0;
    int N = 0;
    string x,y;

    
    cin>>t;
    
    while(t--)
    {
        cin>>M>>N;
        cin>>x>>y;
        editDistance(x,y);
    }
    
    return 0;
}