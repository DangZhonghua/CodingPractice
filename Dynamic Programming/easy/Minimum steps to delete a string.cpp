/*
Minimum steps to delete a string 
https://practice.geeksforgeeks.org/problems/minimum-steps-to-delete-a-string/0/?ref=self

Given a string containing characters as integers only. We need to delete all character of this string 
in a minimum number of steps where in one step we can delete the substring which is a palindrome. 
After deleting a substring remaining parts are concatenated.


Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. The first line of each test case contains an integer N denoting the length of the string.
The second line of each test case contains the string consisting of only integer characters.


Output:
Count the minimum number of steps to delete the whole string and output the answer in a new line.


Constraints:

1<= T <=100
1<= N <=1000


Example:
Input:

1
7
2553432

Output:
2

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int LongestPalindromicSubtring(string& a, int& start, int& end)
{
    int ret = 0;
    int maxlen = 1;
    int len = a.size();
    vector< vector<int> >  LPS(len+1, vector<int>(len+1,0));
    
    start = end = 0;
    //for length = 1 initialize
    for(int i = 1; i<=len; ++i)
    {
        LPS[i][i] = 1;
    }
    for( int l = 2; l<=len; ++l)
    {
        for(int i = 1; i<=len; ++i)
        {
            int j = i+l-1;
            if(j>len)
            {
                break;
            }
            LPS[i][j] = 0;
            if(a[i-1] == a[j-1]) // both endpoints are the same
            {
                if(l == 2)
                {
                    LPS[i][j] = 2;
                }
                else
                {
                    LPS[i][j] = 0;
                    if(LPS[i+1][j-1])
                    {
                        LPS[i][j] = LPS[i+1][j-1] + 2;
                    }
                }
                if(LPS[i][j]>maxlen)
                {
                    maxlen = LPS[i][j];
                    start = i-1;
                    end = j-1;
                }
            }            
        }
    }

    return ret;
}


int main(int argc, char const *argv[])
{
    string x = "2553432";
    int start = 0;
    int end = 0;
    LongestPalindromicSubtring(x,start,end);
    cout<<(end-start+1)<<endl;
    return 0;
}
