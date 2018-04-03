/*

https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0/?ref=self
Given a String of length N reverse the words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. 
Each case contains a string containing spaces and characters.
 

Output:
For each test case, output a single line containing the reversed String.

Constraints:
1<=T<=20
1<=Lenght of String<=2000


Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr

*/

#include<iostream>
using namespace std;


int ReverseWordsOfString(char* oristr, char* deststr)
{
    int len = 0;
    while(oristr[len++] != '\0'){};
    --len;
    
    int di = 0;
    int ob = len-1;
    int oe = len-1;
    
    while (ob>=0)
    {
        if(oristr[ob] != '.')
        {
            --ob;
        }
        else
        {
            int i = 0;
            for(i = ob+1; i<= oe; ++i)
            {
                deststr[di++] = oristr[i];
            }
            deststr[di++] = '.';
            --ob;
            oe = ob;
        }
    }

    int i = 0;
    for(i = ob+1; i<= oe; ++i)
    {
        deststr[di++] = oristr[i];
    }

    deststr[di] = '\0';

    cout<<deststr<<endl;


 return 0;
}


int main()
{
    int t = 0;
    char oristr[2001]   = {0};
    char deststr[2001]  = {0};

    cin>>t;
    
    while(t--)
    {
        cin>>oristr;
        ReverseWordsOfString(oristr,deststr);
    }
    return 0;
}

