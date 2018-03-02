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