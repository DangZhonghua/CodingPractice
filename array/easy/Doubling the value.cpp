/*
Doubling the value 
https://practice.geeksforgeeks.org/problems/doubling-the-value/0/?ref=self

Given an array of size n and an integer b, traverse the array and if the element in array is b, double b and continue traversal. In the end return value of b.

Input:

The first line of the input contains T denoting the number of testcases. Then follows the description of testcases. The first line of each testcase contains two space separated positive integers n and b denoting the size of array and initial value of b respectively.The second line contains n space separated positive integers denoting the elements of array.


Output:

For each testcase, print the final value of b.


Constraints:

1<=T<=100
1<=n<=50
1<=b<=1000
1<=A[i]<=1018 (1<=i<=N)


Example:

Input:
1
5 2
1 2 3 4 8

Output:
16

Explanation: The initial value of b is 2. Traversing from the first element, 2 is found in 2nd position, so doubling b we get b = 4 . 4 is found in 4th position so doubling b we get b = 8. 8 is found in 5th position, so doubling b we get b = 16.

*/

#include<iostream>
#include<vector>
using namespace std;

int DoubleTarget(vector<unsigned long long>a, unsigned long long target)
{
    for(unsigned long long  e: a)
    {
        if(target == e)
        {
            target *=2;
        }
    }

    cout<<target<<endl;
    return 0;
}

int main(int argc, char const *argv[])
{
    int t = 0;
    cin>>t;
    
    while(t--)
    {
        int N, target;
        cin>>N>>target;
        vector<unsigned long long> a(N,0);
        int i = 0;
        while(i< N)
        {
            unsigned long long d = 0;
            cin>>d;
            a[i++] = d;
        }
        DoubleTarget(a, target);
    }
    return 0;
}
