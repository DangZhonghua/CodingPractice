/*

Word Break 
https://practice.geeksforgeeks.org/problems/word-break/0
https://www.geeksforgeeks.org/dynamic-programming-set-32-word-break-problem/

Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.

Consider the following dictionary
{ i, like, sam, sung, samsung, mobile, ice,
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" or "i like sam sung".

Input:
First line is integer T denoting number of test cases. 1<=T<=100.
Every test case has 3 lines.
First line is N number of words in dictionary. 1<=N<=12.
Second line contains N strings denoting the words of dictionary. Length of each word is less than 15.
Third line contains a string S of length less than 1000.

Output:
Print 1 is possible to break words, else print 0.

Example:
Input:
2
12
i like sam sung samsung mobile ice cream icecream man go mango
ilike
12
i like sam sung samsung mobile ice cream icecream man go mango
idontlike
Output:
1
0

*/

#include<unordered_set>
#include<string>
#include<iostream>
using namespace std;


int decodePassword( unordered_set<string>& dict,char* szPassword);

int main()
 {
    int t = 0;
    int N = 0;
    unordered_set<string> dict;   
    string  strPassword;
    char  szPassword[1001];
    string  strword;
    cin>>t;
    
    while(t>0)
    {
        dict.clear();
        --t;
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>strword;
            dict.insert(strword);
            strword.clear();
            ++i;
        }
        cin>>szPassword;
        decodePassword(dict,szPassword);
    }


	return 0;
}

int decodePassword( unordered_set<string>& dict,char* szPassword)
{
    bool bDecode = true;
    char flag[1001];
    
    for(int i = 0; i<1001; ++i)
    {
        flag[i] = 0;
    }
    
    int i = 0;
    for(i = 0; szPassword[i] != '\0'; ++i)
    {
        int j = i-1;
        char t = szPassword[i+1];
        szPassword[i+1] = '\0';
        
        while(j >= 0)
        {
            if( 1 == flag[j] )
            {
               if( dict.find( szPassword+j+1 ) != dict.end() )
               {
                   flag[i] = 1;
               }
            }
            --j;
        }
        
        if( dict.find( szPassword+j+1 ) != dict.end() )
        {
            flag[i] = 1;
        }
        
        szPassword[i+1]  = t;
        
    }
    
    cout<<(bool)flag[i-1]<<endl;
    
    
    return 0;
}







