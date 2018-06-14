/*
Amend The Sentence 
https://practice.geeksforgeeks.org/problems/amend-the-sentence/0/?ref=self
Given an array of characters which is basically a sentence. 
However there is no space between different words and the first letter of every word is in uppercase. 
You need to print this sentence after following amendments:
(i) Put a single space between these words
(ii) Convert the uppercase letters to lowercase.

Input: 

The first line of input contains the number of test cases. The description of T test case follows.

Each test case contains a single line containing a string.

Output:

Print the desired Sentence.


Constraints:

1<=T<=30

1<=Size of String <=100

Example:

Input : 

2

BruceWayneIsBatman

You

Output : 

bruce wayne is batman

you


*/

#include <string>
#include<iostream>
using namespace std;

int AmendTheSentence(const string& strsen)
{
    char sztext[300];
    int  i  = 0;
    int  j  = 0;
    
    if(strsen[j]>='A' && strsen[j]<='Z')
    {
        sztext[i++] = strsen[j] + 32;
    }
    else
    {
        sztext[i++] = strsen[j];
    }
    
    for(int j = 1; j<strsen.size(); ++j)
    {
        if(strsen[j]>='A' && strsen[j]<='Z')
        {
            sztext[i++]= ' ';
            sztext[i++] = strsen[j] + 32;
        }
        else
        {
            sztext[i++] =strsen[j];
        }
    }
    sztext[i++] = '\0';

    cout<<sztext<<endl;


    return 0;
} 


int main()
{

    int t = 0;
    string strsen;
    cin>>t;

    while(t--)
    {
        cin>>strsen;
        AmendTheSentence(strsen);
    }

    return 0;
}