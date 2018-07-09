/*
Extract Maximum 
https://practice.geeksforgeeks.org/problems/extract-maximum/0

You have been given an alphanumeric string , extract maximum numeric value from that string. 
Alphabets will only be in lower case.

Input:
The first line contains a single integer T i.e. the number of test cases. The first and only line consists of a String S.

Output: 
In one line print the Maximum number extracted from the string S.

Constraints:
1<=T<=100
2<=N<=100

Example:
Input:
3
100klh564abc365bg
abvhd9sdnkjdfs
abchsd0sdhs


Output:
564
9
0

Explanation:
Test Case 1: The maximum number found in the string is "564".  

*/

/*
use range or slide window to handle this.

*/

#include<iostream>
#include<string>
using namespace std;

int ExtractMax(const string& strexp)
{
    int s = -1;
    int e = 0;
    int max = 0;
    //[s,e-1] is the slide window
    while(e<strexp.length())
    {
        if(strexp[e]>='a' && strexp[e]<='z')
        {
            if( -1 != s) // the window has been formed.
            {          
                int base = 0;
                for(int i = s; i<e; ++i)
                {
                    base *=10;
                    base +=(strexp[i]-'0');
                }
                if(max<base)
                {
                    max = base;
                }
              s = -1;
            }
        }
        else
        {
            if(-1 == s)
            {
                s = e;
            }
        }

        ++e;    
    } 

    if(-1 != s) //the last window
    {
        int base = 0;
        for(int i = s; i<e; ++i)
        {
            base *=10;
            base +=(strexp[i]-'0');
        }
        if(max<base)
        {
            max = base;
        }
    }

    

    cout<<max<<endl;

    return 0;
}

int main()
{
    int t = 0;
    string strexp;

    cin>>t;

    while(t--)
    {
        cin>>strexp;
        ExtractMax(strexp);
    }

    
    return 0;
}