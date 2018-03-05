//https://practice.geeksforgeeks.org/problems/trapping-rain-water/0/?ref=self

#include<iostream>
#include <climits>
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
        
        fastTrapRainWater(a,N);
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
	int c[10] = { 0 };  //is the count of every specific value.
	int p[10] = { 0 };  //is the specific index. 
	int maxWater = 0;


	for (int k = 0; k < 10; ++k)
	{
		c[k] = 0;
		p[k] = 0;
	}

	for (int k = 0; k < N; ++k)
	{
		r[a[k]][c[a[k]]] = k;
		c[a[k]] += 1;
	}

	int i = 0;
	while (i+1 < N)
	{
		int pos = INT_MAX;
		int j = a[i];
		p[j] += 1; //skip the current element which is under processing.

		for (j; j < 10; ++j)
		{
			if (p[j] < c[j] && i< r[j][p[j]] && pos > r[j][p[j]])
			{
				pos = r[j][p[j]];
			}
		}

		if (INT_MAX == pos)
		{
			j = a[i];
			--j;
			for (; j >= 0; --j)
			{
				if (p[j] < c[j] && i < r[j][p[j]])
				{
					pos = r[j][p[j]];
					break;
				}
			}
		}

		if (INT_MAX != pos)
		{
			int h = a[i] < a[pos] ? a[i] : a[pos];
			for (int w = i + 1; w < pos; ++w)
			{
				maxWater += (h - a[w]);
			}

			for (int w = 0; w < 10; ++w)
			{
				while (p[w]<c[w] && pos > r[w][p[w]])
				{
					++p[w];
				}
			}
		}
		else
		{
			break;
		}

		i = pos;
	}

	cout << maxWater << endl;

	return 0;
}