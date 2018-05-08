/*
https://practice.geeksforgeeks.org/problems/check-if-array-contains-contiguous-integers-with-duplicates-allowed/0

Check if array contains contiguous integers with duplicates allowed 

Given an array of n integers(duplicates allowed). Print “Yes” if it is a set of contiguous integers else print “No”.

INPUT: The first line consists of an integer T i.e. the number of test cases. First line of each test case consists of an integer n, denoting the size of array. Next line consists of n spaced integers, denoting elements of array.
OUTPUT:  Print “Yes” if it is a set of contiguous integers else print “No”.

 

CONSTRAINTS:
1<=T<=100
1<=n<100000
a[i]<=105

 Example:

 2
8
5  2  3  6  4  4  6  6
7
10  14  10  12  12  13  15

Output :
 Yes
 No

Explanation:
Test Case 1 : The elements  of array form a contiguous set of integers which is {2, 3, 4, 5, 6} so the output is Yes.
Test Case 2: We are unable to form contiguous set of integers using elements of array.

*/

#include<iostream>
#include<unorderedset>
using namespace std;

int CheckContiguous(int*a, int N)
{
    int nMin = 0;
    int nMax = 0;
    unorderedset<int> c;

    nMin = a[0];
    nMax = a[0];
    for(int i = 0; i<N; ++i)
    {
        if(a[i]>nMax)
        {
            nMax = a[i];
        }
        if(a[i]<nMin)
        {
            nMin = a[i];
        }
        if(c.find(a[i]) == c.end())
        {
            c.insert(a[i]);
        }
    }

   bool bContinue = true;
    for(int i = nMin;i<=nMax;++i)
    {
        if(c.end() == c.find(i))
        {
            bContinue = false;
            break;
        }
    }

    if(bContinue)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    return 0;
}

int main()
{
  int t = 0;
  int N = 0;
  int a[100000];
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

      CheckContiguous(a,N);
  }



    return 0;
}