/*
K-Palindrome
https://practice.geeksforgeeks.org/problems/k-palindrome/1
A string is k palindrome if it can be transformed into a palindrome on removing at most k characters from it. 
Your task is to complete the function is_k_palin which takes two arguments a string str and a number N . 
Your function should return true if the string is k palindrome else it should return false.

Input:
The first line of input is an integer T denoting the number of test cases . 
Then T test cases follow . Each test case  contains a string str and an integer N separated by space.  

Output:
The output will be 1 if the string is  k palindrome else 0 .

Constraints:
1<=T<=100
1<=length of str<=100
1<=N<=20

Example:
Input
2
abcdecba 1
acdcb  1
Output
1
0

*/

/*
1) Use DP to calculate the longest palindrome sub-sequence.
2) N(string length) - longest sub-sequence <K

*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool JudgeKPalindrome(string& strText, int N)
{
    bool bKPalindrome = false;
    int L = strText.size();
    vector<int> row(L+1,0);
    vector< vector<int> > lps(L+1, row);
    
    for(int i = 0; i <L; ++i)
    {
        lps[i][i] = 1;
    }
    for(int l = 2; l<=L; ++l) //l means the length of substring
    {
        for(int i = 0; i<L-l+1; ++i)
        {
            int j = i+l-1;
            

            if(strText[i] == strText[j])
            {
                if(i+1>j-1)
                {
                    lps[i][j] = 2;
                }
                else
                {
                    lps[i][j] = lps[i+1][j-1] + 2;
                }
            }
            else
            {
                lps[i][j] = lps[i+1][j];
                if(lps[i][j]<lps[i][j-1])
                {
                    lps[i][j] = lps[i][j-1];
                }
            }
        }
    }
   bKPalindrome = ( (L-lps[0][L-1]) <=N? true:false);

    cout<<bKPalindrome<<endl;

    return bKPalindrome;    
}

int main()
{
    int t = 0;
    int N = 0;
    string strText;
    
    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>strText;
        cin>>N;
        JudgeKPalindrome(strText,N);
    }

    return 0;
}