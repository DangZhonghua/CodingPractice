/*
Ugly Numbers
https://www.geeksforgeeks.org/ugly-numbers/
https://practice.geeksforgeeks.org/problems/ugly-numbers/0

Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … 
shows the first 11 ugly numbers. By convention, 1 is included.

Given a number n, the task is to find n’th Ugly number.

Input  : n = 7
Output : 8

Input  : n = 10
Output : 12

Input  : n = 15
Output : 24

Input  : n = 150
Output : 5832

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


unsigned long long vu[5301];
int UglyNumber(int N)
{
    vu[0] = 1;
    unsigned long long u2 = 2;
    unsigned long long u3 = 3;
    unsigned long long u5 = 5;
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;
    auto f = [](unsigned long long a, unsigned long long b)-> long long {return a>b? b:a;};
    for(int i = 1; i<N;++i)
    {
        unsigned long long latest = ((u2<u3? u2:u3)<u5 ? (u2<u3? u2:u3):u5);
        vu[i] = latest;
        if(latest == u2)
        {
            ++i2;
            u2 = vu[i2]*2;
        }
        if(latest == u3)
        {
            ++i3;
            u3 = vu[i3]*3;
        }
        if(latest == u5)
        {
            ++i5;
            u5 = vu[i5]*5;
        }
    }
    
    cout<<vu[N-1]<<endl;
    return 0;
}


int main(int argc, char const *argv[])
{
    int t = 0;
    
    scanf("%d",&t);

   // UglyNumber(5301);
    while(t--)
    {
        int N = 0;
        scanf("%d",&N);
        UglyNumber(N);
        //cout<<vu[N-1]<<endl;
        //printf("%llu\n",vu[N-1]);
    }


    return 0;
}
