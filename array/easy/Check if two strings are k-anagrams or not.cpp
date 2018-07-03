/*
Check if two strings are k-anagrams or not 
https://practice.geeksforgeeks.org/problems/check-if-two-strings-are-k-anagrams-or-not/1/?ref=self

Given two strings of lowercase alphabets and a value k, Your task is to complete the function which returns 
if two strings are K-anagrams of each other or not.
Two strings are called k-anagrams if following two conditions are true.
1. Both have same number of characters.
2. Two strings can become anagram by changing at most k characters in a string.

Input:
The first line of input contains an integer T denoting the no of test cases. 
Then T test cases follow. Th first line of input contains two Strings Str1 and Str2. 
And next line contains an integer k, which denotes number of characters can be replaced.

Output:
Print the respective output in the respective line.

Constraints:
1<=T<=100
1<=K<=|length of String|

Example:
Input:
1
fodr gork
2
Output:
1

2
fodr gork
2
uovwhqfaemqodyksjj 
swwhzsiowocjfyadvj
18

*/



/*Complete the function below*/
#include<string>
using namespace std;
bool areKAnagrams(string str1, string str2, int k)
{
    //add code here.
    
    if(str1.length() != str2.length())
    {
        return false;
    }


    bool bAnagrams  = true;
    int  degree     = 0;
    
    int ff[26] = {0};
    int sf[26] = {0};
    for(int i = 0; i<26; ++i)
    {
        ff[i] = 0;
        sf[i] = 0;
    }
    
    
    for(int i = 0; i<str1.length(); ++i)
    {
        ff[str1[i]-'a'] += 1;
    }
    
    for(int i = 0; i<str2.length(); ++i)
    {
        sf[str2[i]-'a'] += 1;
    }
    
    for(int i = 0; i<26; ++i)
    {
        degree += (ff[i]>sf[i]? ff[i]-sf[i]:sf[i]-ff[i]);       
    }
    
    if(bAnagrams && degree/2>k)
    {
        bAnagrams = false;
    }
   
    
    
    return bAnagrams;
    
}