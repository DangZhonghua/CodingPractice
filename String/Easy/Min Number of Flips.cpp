/*
Min Number of Flips
https://practice.geeksforgeeks.org/problems/min-number-of-flips/0/?ref=self
Given a binary string, that is it contains only 0s and 1s. 
We need to make this string a sequence of alternate characters by flipping some of the bits, 
our goal is to minimize the number of bits to be flipped.
Examples:

Input : str = “001”
Output : 1
Minimum number of flips required = 1
We can flip 1st bit from 0 to 1 

Input : str = “0001010111”
Output : 2
Minimum number of flips required = 2
We can flip 2nd bit from 0 to 1 and 9th 
bit from 1 to 0 to make alternate 
string “0101010101”.

Input:

The first line of input contains a single integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of one line. The line contains a string of 0's and 1's.

Output:

Minimum number of characters to be removed to make string alternate.

Constraints:

1 ≤ T ≤ 100
1 ≤ string length ≤ 1000

Example:

Input
2
01010
1111

Output
0
2
*/

/*

the final pattarn is: 101010... OR 010101...

*/

#include<iostream>
#include<string>
using namespace std;

int NumberOfFlip(const string& strtxt)
{
    string strp1;
    string strp2;

    for(int i = 0; i<strtxt.size(); ++i)
    {
        if(0 == (i%2) )
        {
            strp1.push_back('0');
            strp2.push_back('1');
        }
        else
        {
            strp1.push_back('1');
            strp2.push_back('0'); 
        }
    }

    int np1 = 0;
    int np2 = 0;

    for(int i = 0; i<strtxt.size(); ++i)
    {
        if(strtxt[i] != strp1[i])
        {
            ++np1;
        }

        if(strtxt[i] != strp2[i])
        {
            ++np2;
        }
    }
    
    cout<<(np1>np2?np2:np1)<<endl;
    
    return 0;
}

int main()
{
    int     t = 0;
    string  strtxt;

    cin>>t;
    
    while(t--)
    {
        cin>>strtxt;
        NumberOfFlip(strtxt);
    }


    return 0;
}



