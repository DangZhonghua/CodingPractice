/*

Longest Common Prefix in an Array
https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array/0

Given a array of n strings, find the longest common prefix among all strings present in the array.

Input:
The first line of the input contains an integer T which denotes the number of test cases to follow. Each test case contains an integer n. Next line has space separated n strings. 

Output:
Print the longest common prefix as a string in the given array. If no such prefix exists print "-1"(without quotes).

Constraints:
1<=T<=200
1<=n<=100
1<=|S|<=100

Example:
Input:
2
4
geeksforgeeks geeks geek geezer
3
apple ape april

Output:
gee
ap

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int longestCommonPrefix(vector<string>& strarr)
{
    string strPrefix;
    int len = 0;
    for(int l = 0; ;++l)
    {
        bool ball = true;
        if(l>=strarr[0].length())
        {
            break;
        }

        char chbase = strarr[0][l];

        for(int i=1; i<strarr.size(); ++i)
        {
            if(l>=strarr[i].length())
            {
                ball = false;
                break;
            
            }
            if(chbase != strarr[i][l])
            {
                ball = false;
                break;
            }
            
        }
        if(!ball)
        {
            break;
        }
        else
        {
            strPrefix.push_back(chbase);
            ++len;
        }
    }
    if(0 == len)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<strPrefix<<endl;
    }

    return 0;    
}


int main()
{
    int t = 0;
    int N = 0;
    vector<string> vstr;
    
    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            ++i;
            string str;
            cin>>str;
            vstr.push_back(str);
        }
        longestCommonPrefix(vstr);
        vstr.clear();   
    }

    return 0;
}


