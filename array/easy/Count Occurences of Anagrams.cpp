/*
Count Occurences of Anagrams 
https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams/0/?ref=self
Given a word and a text, return the count of the occurences of anagrams of the word in the text
(For eg: anagrams of word for are for, ofr, rof etc.))

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a text  consisting of only lowercase Latin Letters.
The second line contains a word consisting of only lowercase Latin Letters.

Output:
Print the count of the occurences of anagrams of the word in the text.

Constraints:
1 <= T <= 50
1 <= |word|<= |text| <= 50
here |word| denotes the size of word and |text| denotes the size of text 

Example:
Input:
2
forxxorfxdofr
for
aabaabaa
aaba

Output:
3
4

*/


/*

use slide window to do this. the slide window size is the target word.

*/


#include<iostream>
#include<string>
using namespace std;

int CountOccurencesofAnagrams(const string& strtext, const string& strword)
{
    int wordFreq[26] = {0};
    int textFreq[26] = {0};
    int vindex[26]   = {0};
    int letterCount  = 0;
    int count        = 0;
    int W = strword.size();

    for(int i = 0; i<strword.size(); ++i)
    {
        wordFreq[strword[i]-'a'] +=1;
        if(1 == wordFreq[strword[i]-'a'])
        {
            vindex[letterCount] = strword[i]-'a';
             ++letterCount;
        }
    }
    
    int i = 0;
    int j = 0;

    for(int j = 0; j<strtext.size(); ++j)
    {
        textFreq[strtext[j]-'a'] += 1;
        if(j-i+1 == W)
        {
          //Now, let's check the Anagram.
          bool bFind = true;
          for(int l = 0; l<letterCount; ++l)
          {
            if(wordFreq[vindex[l]] != textFreq[vindex[l]])
            {
                bFind = false;
                break;    
            }
          }
          if(bFind)
          {
              ++count;
          }
          textFreq[strtext[i]-'a'] -= 1;
          ++i;
        }
    }
    
    cout<<count<<endl;

    return 0;
}


int main()
{
    int t = 0;
    string strtext;
    string strword;
    
    cin>>t;
    
    while(t--)
    {
        cin>>strtext;
        cin>>strword;
        CountOccurencesofAnagrams(strtext,strword);
    }
    
    return 0;
}
