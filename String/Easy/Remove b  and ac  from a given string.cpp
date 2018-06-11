/*
Remove “b” and “ac” from a given string
https://practice.geeksforgeeks.org/problems/remove-b-and-ac-from-a-given-string/0
Given a string, eliminate all “b” and “ac” in the string, replace them in-place and iterate over the string once.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains a string of length N.

Output:
Print the resultant substring after removing 'b' and 'ac' from string.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 200

Example:
Input:
2
acbac
aababc

Output:

aaac


*/

#include<iostream>
#include<string>
using namespace std;

int RemoveBac(const string& strtxt)
{
    char a[201] = {0};
    int N = strtxt.size();
    int i = -1;

    int j = 0;
    
    while(j<N)
    {
        if(strtxt[j] == 'b')
        {
            ++j;
        }
        else if(strtxt[j] == 'c') 
        {
            if(j>0 && strtxt[j-1]  == 'a')  //Should compare with strtxt[j-1] not the a[++i]
            {
                --i;
            }
            else
            {
                ++i;
                a[i] = 'c';
            }
            ++j;
        }
        else
        {
            ++i;
            a[i] = strtxt[j];
            ++j;
        }
    }
    ++i;
    a[i] = '\0';

    cout<<a<<endl;

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
        RemoveBac(strtxt);
    }

    return 0;
}