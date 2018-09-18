/*
Amount of Water 
https://practice.geeksforgeeks.org/problems/amount-of-water/0/?ref=self
https://www.geeksforgeeks.org/trapping-rain-water/

An array containing heights of building was given. Its a rainy season. 
Calculate the amount of water collected between all the buildings.
Input:

 

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the number of buildings.
The second line of each test case contains N input H[i],height of buildings.

Output:

Print the amount of water collected between all the buildings.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 1000
1 ≤ H[i] ≤ 1000

Example:

Input
1
6
1 5 3 7 4 2

Output
2
*/

/*
An Efficient Solution is to prre-compute highest bar on left and right of every bar in O(n) time. 
Then use these pre-computed values to 
find the amount of water in every array element. Below is C++ implementation of this solution.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int AmountofWater(vector<int>& a)
{
    vector<int> vleftmax(a.size(),0);
    vector<int> vrightmax(a.size(),0);
    
    vleftmax[0] = a[0];
    vrightmax[a.size()-1] = a[a.size()-1];
    
    for(int i = 1; i<a.size(); ++i)
    {
        vleftmax[i] = std::max(a[i], vleftmax[i-1]);
    }
    for(int i = a.size()-2; i>=0; --i)
    {
        vrightmax[i] = std::max(a[i], vrightmax[i+1]);
    }
    
    int amount = 0;
    for(int i = 0;i<a.size(); ++i)
    {
        amount += (std::min(vleftmax[i],vrightmax[i])-a[i]);
    }
    cout<<amount<<endl;

    return 0;
}

int AmountofWaterSpaceOpt(vector<int>& a)
{
    int amount = 0;
    int leftmax = 0;
    int rightmax = 0;
    int low = 0;
    int high = a.size()-1;
    
    while(low<=high)
    {
        if(a[low]<a[high])
        {
            if(a[low]>leftmax)
            {
                leftmax = a[low];
            }
            else
            {
                amount = (leftmax-a[low]);
            }
              ++low;
        }
        else
        {
            if(a[high]>rightmax)
            {
                rightmax = a[high];
            }
            else
            {
                amount += (rightmax-a[high]); 
            }
             --high;
        }
    }

    cout<<amount<<endl;


    return 0;
}

int main(int argc, char const *argv[])
{
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
        //AmountofWater(a);
        AmountofWaterSpaceOpt(a);
    }
    return 0;
}

