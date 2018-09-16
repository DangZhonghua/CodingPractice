/*
https://practice.geeksforgeeks.org/problems/jumbled-strings/0/?ref=self
Jumbled Strings

You are provided an input string S and the string “GEEKS” . 
Can you figure out all possible subsequence “GEEKS” in the string S ? 
You have to tell the number of ways in which the subsequence “GEEKS” can be formed from the string S.

Input:
The first line of input contains a single integer T, denoting the number of test cases. 
Then T test cases follow. 
Each test case consists of two lines. The first line of each test case conatins an integer N denoting the size of the string S. 
Second line of each test case consists of a string S of size N.

Output:
Corresponding to each test case, print in a new line, 
a number denoting the number of ways in which we can form the subsequence "GEEKS". Output the answer modulo 1000000007.

Constraints :
1<=T<=10
1<=N<=500
Input String contains only uppercase English Letters

Examples:
Input
2
5
GEEKS
8
AGEEKKSB

Output :
1
2

Explanation :
In the first test case the input string is GEEKS itself so the number of ways is 1.
For the second case there are two K's. So a total of two possible strings can be formed by taking either of the two K's.

*/

#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int waysoflcs(const string& x, const string& y)
{
    int n = y.size();
    int m = x.size();
    
    vector< vector<int> > lcs(n+1, vector<int>(m+1,0));
    vector< int > vt;
    
    for(int i = 1;i<=n; ++i)
    {
        for(int j = 1; j<=m; ++j)
        {
            if(y[i-1] == x[j-1])
            {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else
            {
                lcs[i][j] = lcs[i-1][j];
                if(lcs[i][j] < lcs[i][j-1])
                {
                    lcs[i][j] = lcs[i][j-1];
                }
            }
        }
    }
    if(lcs[n][m] == n) // the subsequence is y
    {
        int start = 0;
        vector< vector<int> > wc(n+1, vector<int>(m+1,0));
        for(int r = n; r>0; --r)
        {
            int c = 0;
            for(int j = 1; j<=m; ++j)
            {
                if(r == lcs[r][j])
                {
                    ++c;
                    wc[r][j] = c;
                }
            }
        }
        stack<  pair<int,int> > s;
        for(int c = 1; c<=m; ++c)
        {
            if(lcs[n][c] == n)
            {
                start = c;
                break;
            }
        }
        s.push(pair<int,int>(n,start));
        
        while(!s.empty())
        {
            pair<int,int>& a = s.top();
            if(a.first-1>0)
            {
                
            }
            else
            {

            }
        }




        

    }


    return 0;
}


/*
#include <iostream>
#include <assert.h>
using namespace std;
int getFirstOneBit(int num) //输出 num 的低位中的第一个 1 的位置
{
    return num & ~(num - 1); // num 与 -num 相与找到
}
void findTwo(int *array, int length)
{
    int aXORb = 0;
    int firstOneBit = 0;
    int a = 0;
    int b = 0;
    for (int i = 0; i < length; i++) 
    {
        aXORb ^= array[i];
    }
    assert(aXORb != 0); //保证题目要求，有两个single的数字
    firstOneBit = getFirstOneBit(aXORb);
    for (int i = 0; i < length; ++i) 
    {
    if(array[i] & firstOneBit) 
    {
    a ^= array[i];
    }
    }
    b = aXORb ^ a;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}
int findOne(int *array, int length) 
{
    int aXORbXORc = 0;
    int c = 0;
    int firstOneBit = 0;
    for (int i = 0; i < length; ++i) 
    {
        aXORbXORc ^= array[i];
    }
    for (int i = 0; i < length; ++i) 
    {
        firstOneBit ^= getFirstOneBit(aXORbXORc ^ array[i]); //使用异或会排除掉不相干的元素
    }
    // firstOneBit = getFirstOneBit(a ^ b) ^ getFirstOneBit(a ^ c) ^ getFirstOneBit(b ^ c);
    firstOneBit = getFirstOneBit(firstOneBit); //获取到最低位下面要用
    for (int i = 0; i < length; ++i) 
    {
    if (getFirstOneBit(aXORbXORc ^ array[i]) == firstOneBit) 
    {
    c ^= array[i]; //使用异或会排除掉不相干的元素
    }
    }
    cout << "c: " << c << endl;
return c;
}
int main()
{
int array1[] = {2, 5, 8, 2, 5, 8, 6, 7, 1};
int c = findOne(array1, 9);
int array2[] = {2, 5, 8, 2, 5, 8, 6, 7, 1, c}; //为了更好重用函数，我重新定义了一个数组让大家理解
findTwo(array2, 10);
return 0;
}


*/