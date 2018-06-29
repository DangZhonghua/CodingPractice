/*
Find the closest number
https://practice.geeksforgeeks.org/problems/find-the-closest-number/0/?ref=self

Given an array of sorted integers. The task is to find the closest value to the given number in array. 
Array may contain duplicate values.

Note: If the difference is same for two values print the value which is greater than the given number.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
Each test case consists of two lines. 
First line of each test case contains two integers N & K and 
the second line contains N space separated array elements.

Output:
For each test case, print the closest number in new line.

Constraints:
1<=T<=100
1<=N<=10^5
1<=K<=10^5
1<=A[i]<=10^5

Example:
Input:
2
4 4
1 3 6 7
7 4
1 2 3 5 6 8 9

Output:
3
5
*/

/*
Binary Search is the progress of find the closest.

*/

#include<iostream>
using namespace std;

int makeDiff(int a, int b)
{
    return (a>b? a-b:b-a );
}

int FindClosestNumber(int*a, int N, int K)
{
    int closest = 0;
    int diff    = 100000;
    
    int s = 0;
    int e = N-1;
    
    while(s<=e)
    {
        int m = (s+e)/2;
        if(a[m] == K)
        {
            closest = a[m];
            break;
        }
        else if(a[m]>K)
        {
            if(diff > a[m]-K)
            {
                diff = a[m]- K;
                closest = a[m];
            }
            else if( diff == a[m]-K)
            {
                if(closest<a[m])
                {
                    closest = a[m];
                }
            }

            e = m-1;
        }
        else
        {

            if(diff>K-a[m])
            {
                diff = K-a[m];
                closest = a[m];
            }
            else if(diff == K-a[m])
            {
                if(closest<a[m])
                {
                    closest = a[m];
                }
            }
            s = m+1;
            
        }
    }

    cout<<closest<<endl;

    return 0;
}


int main()
{   
    int t = 0;
    int N,K;
    int a[100000];
    
    cin>>t;
    
    while(t--)
    {
        cin>>N>>K;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        FindClosestNumber(a,N,K);
    }

    return 0;
}


