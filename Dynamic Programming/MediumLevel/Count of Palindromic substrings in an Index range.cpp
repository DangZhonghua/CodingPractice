/*
Count of Palindromic substrings in an Index range 
https://practice.geeksforgeeks.org/problems/count-of-palindromic-substrings-in-an-index-range/0

Given a string str of small alphabetic characters other than this we will be given substring of this string in form of index tuples. We need to find out the count of the palindromic substrings in given substring range.
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the size of the string.

The second line of each test case contains the string and the third line contains integer q1 and q2 denoting the substring range.

Output:
Output the answer to each test case in a new line.
Constraints:
1<= N <=1000
1<= q1, q2 <=1000

Example:
Input:
2
7
xyaabax
3 5
7
xyaabax
2 3

Output:
4
3

Explanation:
For Range1, substring is "aba" |
Count of palindromic substring in "aba" is  four : "a", "b", "aba", "a"
For Range2, substring is "aa"
Count of palindromic substring in "aa" is three : "a", "a", "aa"

*/

#include<iostream>
#include <string>
#include <vector>
using namespace std;


int lpstr(const char* sztext, int N)
{
    int nlpscount = 0;
    vector< vector<bool> > lps(N+1, vector<bool>(N+1, false));
    
    for(int i = 0; i<N; ++i)
    {
        lps[i][i] = true;
        ++nlpscount;
    }
    
    for(int l = 2; l<=N; ++l)
    {
        for(int i = 0; i<=N-l; ++i)
        {
            int j = i+l-1;
            if(sztext[i] == sztext[j])
            {
                if(2 == l)
                {
                    lps[i][j] = true;
                }
                else
                {
                    lps[i][j] = lps[i+1][j-1];
                }

                if(lps[i][j])
                {
                    ++nlpscount;
                }
            }
        }
    }
    
    cout<<nlpscount<<endl;

    return 0;
}


int main(int argc, char const *argv[])
{
   int t = 0;
   int N  = 0;
   string strtxt;
   int s,e;

    cin>>t;

    while(t--)
    {
        cin>>N;
        cin>>strtxt;
        cin>>s>>e;
        int t1 = s>e?e:s;
        int t2 = s<e?e:s;
        lpstr(strtxt.c_str()+t1, t2-t1+1);

    }

    return 0;
}

