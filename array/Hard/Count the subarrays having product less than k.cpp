#include<iostream>
using namespace std;


int CountSubarrayProductLessThanK(unsigned long long*a, int N, unsigned long long K);


int main()
{
    int t = 0;
    int N = 0;
    unsigned long long  K = 0;
    unsigned long long a[100001]       = {0};

    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>N;
        cin>>K;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        CountSubarrayProductLessThanK(a,N,K);
    }

    return 0;
}



unsigned long long CalcUnqiueSubarray(int& pres, int& pree, int s, int e)
{
    unsigned long long nSubArrayCount  = 0;
    unsigned long long d = 0;
    if(s<=pree)
    {
        d = pree-s+1;
        d = ((d*(d+1))/2);
    }

    unsigned long long n = (e+1-s);

    nSubArrayCount = (n*(n+1))/2;
    nSubArrayCount -=d;     //exclude the intersection part

    pree = e;
    return nSubArrayCount;
}


int CountSubarrayProductLessThanK(unsigned long long*a, int N,unsigned long long K)
{
    unsigned long long p = 1;
    int i = 0;
    int s = 0;
    unsigned long long nMaxSubarray = 0;
    int pree = -1;
    int pres = -1;
    
    
    while(i< N)
    {
        if(p * a[i]<K)
        {
            p *=a[i];
            ++i;
        }
        else
        {
            //[s,i-1] is the continue subarray which product is less than K
            if(i-1>=s)
            {
                nMaxSubarray += CalcUnqiueSubarray(pres,pree,s, i-1);
                p /=a[s];
            }
            ++s;
            if(s>i)//Make sure the start point not large the end point
            {
                i = s;
            }
        }
    }   

    if(i-1>=s)
    {
        int n = i-s;
        nMaxSubarray += CalcUnqiueSubarray(pres,pree,s, i-1);
    }

    cout<<nMaxSubarray<<endl;

    return 0;
}