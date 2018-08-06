/*
Print all possible ways to convert one string into another string
https://www.geeksforgeeks.org/print-all-possible-ways-to-convert-one-string-into-another-string-edit-distance/


Print all possible ways to convert one string into another string | Edit-Distance

Prerequisite: Dynamic Programming | Set 5 (Edit Distance)
Given two strings str1 and str2, the task is to print the all possible ways to convert ‘str1’ into ‘str2’.
Below are the operations that can be performed on “str1”:

    Insert
    Remove
    Replace

All of the above operations are of equal cost. 
The task is to print all the various ways to convert ‘str1’ into ‘str2’ 
using the minimum number of edits (operations) required, where a “way” 
comprises of the series of all such operations required.

Examples:

    Input: str1 = “abcdef”, str2 = “axcdfdh”
    Output:
    Method 1:
    Add h
    Change f to d
    Change e to f
    Change b to x

    Method 2:
    Change f to h
    Add d
    Change e to f
    Change b to x

    Method 3:
    Change f to h
    Change e to d
    Add f
    Change b to x 


*/

/*

            ed[i-1][j-1]  if x[i] == y[j]

ed[i][j] =  min     if x[i] != y[j]
                {
                    ed[i-1][j-1] + 1 //replace
                    ed[i-1][j] + 1 // remove
                    ed[i][j-1] + 1 // for insert
                }

*/

/*

after computing the minicost of transforming. We store the parent pointer to
figure out the possible way.

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;



int main()
{
    int t = 0;
    
    cin>>t;
    
    while(t--)
    {
        string x,y;
        cin>>x>>y;
    }
    
    return 0;
}