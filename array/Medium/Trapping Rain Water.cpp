//https://practice.geeksforgeeks.org/problems/trapping-rain-water/0/?ref=self

#include<iostream>
using namespace std;


int TrapRainWater(int*a, int N);

int main()
 {
    int t = 0;
    int N = 0;
    int a[101] = {0};
    
    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        
        TrapRainWater(a,N);
    }


	return 0;
}

//This is o(n^2) solution, but it is not accepted by geeksforgeeks, but it is easy to understand

//Let's find "U" Shape sub-array
int TrapRainWater(int*a, int N)
{
    int maxWater         = 0;
    int leftWallIndex    = 0;
    int rightWallIndex   = 0;
    
    while(leftWallIndex+1<N)
    {
        int lw = a[leftWallIndex];
        int trappedWater = 0;
        int rw = 0;
        int rwindex = 0;
        
        rightWallIndex = (leftWallIndex + 1);
        rw = a[rightWallIndex]; 
        
       
        
        while(rightWallIndex<N)
        {
            if(lw > a[rightWallIndex])
            {
                if(rw < a[rightWallIndex] )
                {
                   rw = a[rightWallIndex]; 
                   rwindex = rightWallIndex;
                }
            }
            else
            {
                rw = a[rightWallIndex]; 
                rwindex = rightWallIndex;
                break;
            }
            ++rightWallIndex;
        }
        
        int h = lw>rw? rw:lw;
        for(int m = leftWallIndex+1; m<rwindex; ++m)
        {
            maxWater += (h-a[m]);
        }
        leftWallIndex = rwindex;
    }
    
    cout<<maxWater<<endl;
    return 0;
}

int fastTrapRainWater(int*a, int N)
{
    int r[10][102];

    for(int i = 0; i <10; ++i)
    {
        r[i][0] = 1;
        r[i][1] = 1;
    }

    for(int i = 0; i<N; ++i)
    {
        int pos = (++(r[a[i]][0]));
        r[a[i]][pos] = i;
    }

    int i = 0;
    
    while(i < N)
    {
        int pos = -1;
        if(int j = a[i]; j<10; ++j)
        {
            
        }
    }

    return 0;
}