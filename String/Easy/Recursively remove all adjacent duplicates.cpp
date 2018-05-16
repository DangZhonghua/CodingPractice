/*
Recursively remove all adjacent duplicates
https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates/0/?ref=self

Given a string, recursively remove adjacent duplicate characters from string. The output string should not have any adjacent duplicates.
 

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an string str.

Output:
For each test case output a new line containing the resulting string.

Constraints:
1<=T<=100
1<=Length of string<=50

Example:
Input:
2
geeksforgeek
acaaabbbacdddd

Output:
gksforgk
acac

*/

/*
pUnique == pchar

*/


#include<iostream>
#include<string>
using namespace std;

int RemoveDuplicateChar(char*szText, char*szout)
{
    char* pUnique = szText;
    char* pText   = szText;
    bool  bDuplicate = true;
    
    //mississipie
    --pUnique;
    while(bDuplicate)
    {
        bDuplicate = false;
        while(*pText != '\0')
       {
            if(pUnique == szText-1)
            {
                ++pUnique;
                *pUnique = *pText;
                ++pText;
            }
            else if(*pText == *pUnique)
            {
                bDuplicate = true;
                //Find the duplicate util not duplicate
                while(*pText != '\0' && *pUnique == *pText)
                {
                    ++pText;
                }
                *pUnique = *pText;
                if(*pText != '\0')
                {
                    ++pText;
                }
            }
            else
            {
                ++pUnique;
                *pUnique = *pText;
                ++pText;
            }
       }
        if(!bDuplicate)
        {
            break;
        }
        ++pUnique;
        *pUnique = '\0';

        pUnique = szText;
        pText   = szText;
        --pUnique;
    }
    cout<<szText<<endl;
    return 0;
}

int main()
{
    char sztext[52];
    char szout[52];
    int t = 0;
    
    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>sztext;
        RemoveDuplicateChar(sztext,szout);
    }
    

    return 0;
}