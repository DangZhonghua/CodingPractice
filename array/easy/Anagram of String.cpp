/*
Anagram of String
https://practice.geeksforgeeks.org/problems/anagram-of-string/1/?ref=self

Given two strings in lowercase, the task is to make them anagram. 
The only allowed operation is to remove a character from any string. 
Find minimum number of characters to be deleted to make both the strings anagram. 
If two strings contains same data set in any order then strings are called Anagrams.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of 2 strings to make the anagrams.

Output:
Output the minimum number of characters to be deleted to make both the strings anagram.

Constraints:
1<=T<=10^5
1<=length of string<=10^5

Example:
Input:
2
bcadeh
hea
cddgk
gcd

Output:
3
2

*/

#include<iostream>
#include<string>
using namespace std;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2)
{
    // Your code goes here
    int vFreq1[26] = {0};
    int vFreq2[26] = {0};
    int minRemoval = 0;
    for(int i = 0; i<str1.size(); ++i)
    {
        vFreq1[str1[i]-'a'] +=1;
    }
    for(int j = 0; j<str2.size(); ++j)
    {
        vFreq2[str2[j]-'a'] +=1;
    }
    
    for(int k = 0; k <26; ++k)
    {
        if(vFreq1[k] != vFreq2[k])
        {
            minRemoval += (vFreq1[k]>vFreq2[k]? (vFreq1[k]- vFreq2[k]):(vFreq2[k]-vFreq1[k]) );
        }
    }

    cout<<minRemoval<<endl;

    return minRemoval;

}

int main()
{
    int t = 0;
    string str1;
    string str2;

    cin>>t;
    
    while(t--)
    {
        cin>>str1;
        cin>>str2;
        remAnagram(str1,str2);
    }

    return 0;
}