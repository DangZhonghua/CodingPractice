/*
Longest Prefix Suffix 
https://practice.geeksforgeeks.org/problems/longest-prefix-suffix/0

Given a string of character, find the length of longest proper prefix which is also a proper suffix.
Example:
S = abab
lps is 2 because, ab.. is prefix and ..ab is also a suffix.

Input:
First line is T number of test cases. 1<=T<=100.
Each test case has one line denoting the string of length less than 100000.

Expected time compexity is O(N).

Output:
Print length of longest proper prefix which is also a proper suffix.

Example:
Input:
2
abab
aaaa

Output:
2
3

qgqbqgqlqjqgvqgqbqwqgdqgqbqgqlqjqgvqgqbqqqgqbqgqlqjqgvqgqbqwqgdqgqbqgqlqjqgvqgqbbqgqbqgqlqjqgvqgqbqwqgdq
57

wrwbwrqwhwrwbw
5

*/

/*
this is the KMP pattarn prefix array
This is the dynamic programming style.

         j+1 if x[i] = x[j]
lps[i] = 
         lps[lps[ j-1] ]
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int longestPefixPostfix(const string& strtext)
{
    vector<int> lps(strtext.length()+1,0);
    int i = 1;
    int j = 0;
    
    for(i = 1; i<strtext.size(); ++i)
    {  
        while(j>0 && strtext[j] != strtext[i])
        {
            j = lps[j-1];
        }

        if(strtext[j] == strtext[i])
        {
            lps[i] = j+1;
            ++j;
        }
   
    }


    cout<<lps[strtext.length()-1]<<endl;



    return 0;
}


int main()
{
    int t = 0;
    string strtext;

    cin>>t;

    while(t--)
    {
        cin>>strtext;
        longestPefixPostfix(strtext);
    }
    
    return 0;
}

