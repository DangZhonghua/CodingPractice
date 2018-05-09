/*

https://practice.geeksforgeeks.org/problems/sum-of-numbers-or-number/0

Given two non-negative numbers X and Y. The task is calculate the sum of X and Y.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two numbers X and Y.

Output:
For each test case, if the number of digits in sum (X+Y) are equal to the number of digits in X, then print sum, else print X.

Constraints:
1<=T<=500
1<=|Number length |<=100

Example:
Input:
2
25 23
3 5

Output:
48
8
*/

#include<iostream>
#include<string>
using namespace std;

char table[] = {'0','1','2','3','4','5','6','7','8','9'};

int addlargeNumber(const string& str1, const string& str2)
{
    int stepf = 0;
    int l1 = str1.length();
    int l2 = str2.length();
    string strRes;
    
    l1 -=1;
    l2 -=1;

    while(l1>=0 && l2>=0)
    {
        int s = stepf + str1[l1]-'0' + str2[l2]-'0';
        stepf = s/10;
        strRes.push_back(table[s%10]);
        --l1;
        --l2;
    }
    while(l1>=0)
    {
        int s = stepf + str1[l1]-'0';
        stepf = s/10;
        strRes.push_back(table[s%10]);
        --l1;
    }
    while(l2>=0)
    {
        int s = stepf + str2[l2]-'0';
        stepf = s/10;
        strRes.push_back(table[s%10]);
        --l2;
    }
    if(stepf)
    {
        strRes.push_back(table[stepf%10]);
    }
   
    string res;
    for(auto it = strRes.rbegin(); it != strRes.rend(); ++it)
    {
        res.push_back(*it);
    }
    
    if(res.length() == str1.length())
    {
        cout<<res<<endl;
    }
    else
    {
        cout<<str1<<endl;
    }
    

    return 0;
}

int main()
{
    int t = 0;
    string str1;
    string str2;

    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>str1>>str2;
        addlargeNumber(str1,str2);
    }


    return 0;
}
