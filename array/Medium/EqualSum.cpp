//https://practice.geeksforgeeks.org/problems/equal-sum/0/?ref=self

#include<iostream>
using namespace std;

int EqualSum(int* a, int N)
{
    int p        = -1;
    long long sum      = 0;
    long long leftsum  = 0;
    long long rightsum = 0;

    for(int i = 0; i<N; ++i)
    {
        sum += a[i];
    }
    
    for(int i = 0; i<N; ++i)
    {
        rightsum = sum-a[i]-leftsum;
        if(leftsum == rightsum)
        {
            p = i;
            break;
        }
        leftsum += a[i];
    }
    if(-1 != p)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }


    return 0;
}

int main ()
{
    int t = 0;
    int a[100000];
    int N = 0;
    
    cin>>t;
    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        EqualSum(a,N);
    }

    return 0;
}