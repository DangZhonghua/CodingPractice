/*
Check if a given string is a rotation of a palindrome
https://practice.geeksforgeeks.org/problems/check-if-a-given-string-is-a-rotation-of-a-palindrome/0/?ref=self

Given a string, check if it is a rotation of a palindrome. For example “aab” is a rotation of “aba”.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. 
Each case contains a string.


Output:
For each test case, output "1" if string is rotation of a palindrome otherwise "0" in a new line.
 

Constraints:
1<=T<=100
1<=Length of the string<=100


Example:
Input:
1
aab

Output:
1

*/

/*

Just check whether the char in the sting are pairs and allow only one char is not paired.

*/

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int JudgeRotationPalindrome(const string& x)
{
    bool bRotation = true;
    int nSingleCount = 0;
    unordered_map<int, int> ch2CountMap;    
    for(int i = 0; i<x.length(); ++i)
    {
        if( ch2CountMap.end() != ch2CountMap.find(x[i]))
        {
            ch2CountMap[x[i]] += 1;
        }
        else
        {
            ch2CountMap[x[i]] = 1;
        }
    }

    for(auto it = ch2CountMap.begin(); it != ch2CountMap.end(); ++it)
    {
        if(it->second%2)
        {
            ++nSingleCount;
        }
    }
    
    if(nSingleCount>1)
    {
        bRotation = false;
    }
    
    cout<<(bRotation?1:0)<<endl;

    return 0;
}


int main(int argc, char const *argv[])
{
    int t = 0;

    cin>>t;
    while(t--)
    {
        string x;
        cin>>x;
        JudgeRotationPalindrome(x);
    }

    return 0;
}
