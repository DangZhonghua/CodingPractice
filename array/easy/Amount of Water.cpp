/*
Amount of Water 
https://practice.geeksforgeeks.org/problems/amount-of-water/0/?ref=self

An array containing heights of building was given. Its a rainy season. Calculate the amount of water collected between all the buildings.
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
find the range: [start peak, end peak]
*/

#include<iostream>
#include<vector>

struct range_t
{
    int s;
    int e;
};


using namespace std;

int AmountofWater(vector<int>& a)
{
    vector<range_t> vr;
    int s = -1;
    int e = -1;
    
    for(int i = 1; i< a.size(); ++i)
    {
         
    }


    return 0;
}

