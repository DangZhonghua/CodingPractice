/*
https://www.geeksforgeeks.org/move-zeroes-end-array-set-2-using-single-traversal/
Move all zeroes to end of array | Set-2 (Using single traversal)

Given an array of n numbers. The problem is to move all the 0’s to the end of the array while maintaining the order of the other elements. Only single traversal of the array is required.

Examples:

Input : arr[]  = {1, 2, 0, 0, 0, 3, 6}
Output : 1 2 3 6 0 0 0

Input: arr[] = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9}
Output: 1 9 8 4 2 7 6 9 0 0 0 0 0

*/

/*

i is the last element which next to zero
j is the loop index.

*/


#include<iostream>
#include<vector>
using namespace std;

int moveZero2End(vector<int>& a)
{
    int i = -1;
    int j = 0;
    
    for(int j = 0; j<a.size(); ++j)
    {
        if(0 != a[j])
        {
            ++i;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    for(int i = 0; i< a.size(); ++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}

int main(int argc, char const *argv[])
{
    vector<int> a{1, 2, 0, 0, 0, 3, 6};
    vector<int> b{0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};

    moveZero2End(a);
    moveZero2End(b);
    
    return 0;
}
