/*
Largest Number formed from an Array 
https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array/0/?ref=self

Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.

The result is going to be very large, hence return the result in the form of a string.

Input:

The first line of input consists number of the test cases. The description of T test cases is as follows:

The first line of each test case contains the size of the array, and the second line has the elements of the array.


Output:

In each separate line print the largest number formed by arranging the elements of the array in the form of a string.


Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 1000


Example:

Input:

2
5
3 30 34 5 9
4
54 546 548 60

Output:

9534330
6054854654

*/

#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;


vector<string> vDig;

int LargestNumberFromArray(int*a, int N);

int main()
 {
    int t = 0;
    int a[100];
    int N = 0;
    
    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i];
            ++i;
        }
         LargestNumberFromArray(a, N);
    }
    
    

	return 0;
}

bool compareNumberChar(const char* lsz,int lsize, const char* rsz,int rsize)
{
    bool    bGreat  = false;
    int     min     = lsize>=rsize? rsize:lsize;
    
    int i = 0;
    
    while(i<min)
    {
        if(lsz[i]>rsz[i])
        {
            bGreat = true;
            return bGreat;
        }
        else if(lsz[i] == rsz[i])
        {
            ++i;
        }
        else
        {
            return bGreat;
        }
    }
    
    if(lsize == rsize)
    {
        return false;
    }
    
    if(lsize<rsize)
    {
       return compareNumberChar(lsz,lsize,rsz+min,rsize-min);
    }
    else
    {
        return compareNumberChar(lsz+min,lsize-min,rsz,rsize);
    }
    
    
}

bool compareNumberString(int lhs, int rhs)
{
    int lsize   = vDig[lhs].length();
    int rsize   = vDig[rhs].length();
   
   return compareNumberChar(vDig[lhs].c_str(),lsize, vDig[rhs].c_str(),rsize);
}


int LargestNumberFromArray(int*a, int N)
{
    vDig.clear();
    
    vector<int> vIndex;
    char szDig[10];
    
    for(int i = 0; i<N;++i)
    {
        sprintf(szDig,"%d",a[i]);
        vDig.push_back(szDig);
        vIndex.push_back(i);
    }
    std::sort(vIndex.begin(),vIndex.end(),compareNumberString);
    
    for(int i =0; i<N;++i)
    {
        cout<<vDig[vIndex[i]].c_str();
    }
    cout<<endl;
    
    return 0;
}