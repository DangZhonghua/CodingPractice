/*
Number to words
https://practice.geeksforgeeks.org/problems/number-to-words/0
Given number into words. For example, if “1234” is given as input, output should be “one thousand two hundred and thirty four”

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.

Output:

Print the number into words (in small letter).

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 9999

Example:

Input:
2
2
142

Output:
two
one hundred and forty two

*/



#include<iostream>
#include<string>
using namespace std;

string  strunit[4] = {"thousand","hundred"};

string   tenunit[10] = {"ten","eleven","twelve","thirteen", "fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string   dig[10]     = {"zero","one","two","three","four","five","six","seven","eight","nine"};
string   irty[10]    = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};


int number2Word(int N)
{
    string strword;
    int digs[5] = {0};
    int M = N;
    int i = 1;
    while(M)
    {
        digs[i++] = M%10;
        M -= (M%10);
        M /=10;
    }

    if(digs[4])
    {
        strword += dig[ digs[4] ];
        strword += " ";
        strword += "thousand";
    }
    
    if(digs[3])
    {
        if(digs[4])
        {
            strword += " ";
        }
        strword += dig[ digs[3] ];
        strword += " ";
        strword += "hundred";
    }

    if( (digs[2] || digs[1] ) && (digs[3] || digs[4] ) )
    {
        strword += " and ";
    }

    if(digs[2])
    {
        if(1 == digs[2])
        {
            strword += tenunit[digs[1]];
        }
        else
        {
            strword += irty[digs[2]];
            if(digs[1])
            {
                strword += " ";
                strword += dig[digs[1]];
            }
        }
    }
    else if(digs[1])
    {
        strword += dig[digs[1]];
    }

    cout<<strword<<endl;

    return 0;
}


int main()
{
    int t = 0;
    int N = 0;

    cin>>t;

    while(t--)
    {
        cin>>N;
        number2Word(N);
    }
    
    return 0;
}