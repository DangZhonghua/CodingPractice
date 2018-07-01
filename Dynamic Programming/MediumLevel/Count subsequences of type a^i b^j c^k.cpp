/*
Count subsequences of type a^i b^j c^k 
https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck/0
https://www.geeksforgeeks.org/number-subsequences-form-ai-bj-ck/

Given a string s, the task is to count number of subsequences of the form aibjck, where i >= 1, j >=1 and k >= 1.

Note: Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.


Examples:

Input  : abbc
Output : 3
Subsequences are abc, abc and abbc

Input  : abcabc
Output : 7
Subsequences are abc, abc, abbc, aabc
abcc, abc and abc


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string s.

Output:
For each test case in a new line print the required output.

Constraints:
1<=T<=100
1<=Length of string <=100

Example:
Input:
2
abbc
abcabc
Output:
3
7

*/

/*
We traverse given string. For every character encounter, we do following:

1) Initialize counts of different subsequences caused by different combination of ‘a’. Let this count be aCount.

2) Initialize counts of different subsequences caused by different combination of ‘b’. Let this count be bCount.

3) Initialize counts of different subsequences caused by different combination of ‘c’. Let this count be cCount.

4) Traverse all characters of given string. Do following for current character s[i]
    If current character is ‘a’, then there are following possibilities :
    a) Current character begins a new subsequence.
    b) Current character is part of aCount subsequences.
    c) Current character is not part of aCount subsequences.
    Therefore we do aCount = (1 + 2 * aCount);

    If current character is ‘b’, then there are following possibilities :
    a) Current character begins a new subsequence of b’s with aCount subsequences.
    b) Current character is part of bCount subsequences.
    c) Current character is not part of bCount subsequences.
    Therefore we do bCount = (aCount + 2 * bCount);

    If current character is ‘c’, then there are following possibilities :
    a) Current character begins a new subsequence of c’s with bCount subsequences.
    b) Current character is part of cCount subsequences.
    c) Current character is not part of cCount subsequences.
    Therefore we do cCount = (bCount + 2 * cCount);

5) Finally we return cCount;

*/

//Expected Time Complexity : O(n)


#include<iostream>
#include<string>
using namespace std;

int CountSubSequence(const string& strtxt)
{
    int N = strtxt.size();


    


    return 0;
}


int main()
{
    int t = 0;    
    string strtxt;


    cin>>t;
    
    while(t--)
    {
        cin>>strtxt;
        CountSubSequence(strtxt);
    }

    return 0;
}

