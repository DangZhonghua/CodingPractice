/*
https://practice.geeksforgeeks.org/problems/next-larger-element/0/?ref=self
https://www.geeksforgeeks.org/next-greater-element/

Next larger element 

Given an array A [ ] having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. If no such element exists, output -1 

Input:
The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. Each test case consists of two lines. The first line contains an integer N denoting the size of the array. The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A[ ].
 
Output:
For each test case, print in a new line, the next greater element for each array element separated by space in order.

Constraints:
1<=T<=200
1<=N<=1000
1<=A[i]<=1000

Example:
Input
1
4
1 3 2 4 

Output
3 4 4 -1

Explanation
In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist hence -1.

*/

#include<iostream>
#include<vector>
using namespace std;

int nextLarger(vector<int>& a)
{
    vector<int> b(a.size(),-1);

    for(int i = a.size()-2; i>=0; --i )
    {
        if(a[i]<a[i+1])
        {
            b[i] = i+1;
        }
        else
        {
            int j = i+1;
            while( -1 != b[j])
            {
                if(a[ b[j]] > a[i])
                {
                    b[i] = b[j];
                    break;
                }
                else
                {
                    j = b[j];
                }
            }
            if(-1 == b[j])
            {
                if(a[i]<a[j])
                {
                    b[i] = j;
                }
            }
        }
    }

    for(int i = 0; i<b.size(); ++i)
    {
        if( -1 != b[i])
        {
            b[i] = a[b[i]];
        }
        cout<< b[i]<<" ";
    }
    cout<<endl;


    return 0;
}

int main(int argc, char const *argv[])
{
    //vector<int> a{1, 3, 2, 4 };
    //nextLarger(a);
    int t = 0;
      
    cin>>t;
    while(t--)
    {
        int N = 0;
        cin>>N;
        vector<int> a(N,0);
        int i = 0;
        while(i<N)
        {
            int d;
            cin>>d;
            a[i++] = d;
        }
        nextLarger(a);
    }

    return 0;
}
