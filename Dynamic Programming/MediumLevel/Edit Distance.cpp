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

#include<iostream>
#include<vector>
#include<string>
using namespace std;


int editDistance(const string& x, const string& y)
{


 return 0;
}


int main()
{
    int t;
    string x,y;

    
    cin>>t;
    
    while(t--)
    {
        cin>>x>>y;
        editDistance(x,y);
    }
    
    return 0;
}