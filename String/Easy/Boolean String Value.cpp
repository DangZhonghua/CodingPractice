/*
https://practice.geeksforgeeks.org/problems/boolean-string-value/0/?ref=self


Boolean String Value 


Given a string consisting of only 0, 1, A, B, C where
A = AND
B = OR
C = XOR
Calculate the value of the string assuming no order of precedence and evaluation is done from left to right.

Input:

The first line of input contains an integer T denoting the number of test cases.
The next T lines contains T strings.

Output:

Print the value of the string assuming no order of precedence and evaluation is done from left to right

Constraints:

1 ≤ T ≤ 100
1 ≤ length(string)<=1000


Examples:
Input : 
1
1A0B1

Output : 1
 

1 AND 0 OR 1 = 1

Input : 
2
1C1B1B0A0
1A0B1

Output : 
0
1

*/


#include<string>
#include<iostream>
using namespace std;


int CalcBooleanValue(string& strExp)
{
    int value[] = {0,1};

    int base = value[ strExp[0] -'0'];

    int i = 1;
    
    while(i+1<strExp.size())
    {
        if('0' == strExp[i+1] || '1' == strExp[i+1])
        {
            if('A' == strExp[i])
            {
                base  &= value[strExp[i+1]-'0'];
            }
            else if('B' ==strExp[i])
            {
                base |=value[strExp[i+1]-'0'];
            }
            else if('C' == strExp[i])
            {
                base ^= value[strExp[i+1]-'0'];
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
        i +=2;

    }

    cout<<base<<endl;
    return 0;
}


int main()
{
    int t = 0;
    string strexp;
    
    cin>>t;

    while(t>0)
    {
        --t;
        strexp.clear();
        cin>>strexp;
        CalcBooleanValue(strexp);
    }

    return 0;    
}