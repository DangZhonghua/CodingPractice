/*
https://www.geeksforgeeks.org/maximum-triplet-sum-array/
https://practice.geeksforgeeks.org/problems/maximum-triplet-sum-in-array/0
Maximum triplet sum in array

iven an array, the task is to find maximum triplet sum in the array.

Examples :

Input : arr[] = {1, 2, 3, 0, -1, 8, 10} 
Output : 21
10 + 8 + 3 = 21

Input : arr[] = {9, 8, 20, 3, 4, -1, 0}
Output : 37
20 + 9 + 8 = 37

*/

/*



*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maximumTripSum(vector<int>& a)
{
    int first  = a[0]; // The biggest
    int second = INT_MIN;
    int third  = INT_MIN;
    
    for(int i = 1; i<a.size(); ++i)
    {
        if(a[i] >= first)
        {
            third = second;
            second = first;
            first = a[i];
        }
        else if(a[i]>= second)
        {
            third = second;
            second = a[i];
        }
        else if(a[i]>=third)
        {
            third = a[i];
        }
    }

    cout<< (first+second+third)<<endl;
    
    return 0;
}


int main()
 {

    int t = 0;
    
    cin>>t;
    
    while(t--)
    {
        int N = 0;
        cin>>N;
        vector<int> a(N,0);
        int i  = 0;
        
        while(i<N)
        {
            int d = 0;
            cin>>d;
            a[i++] = d;
        }
        maximumTripSum(a);
    }

	return 0;
}