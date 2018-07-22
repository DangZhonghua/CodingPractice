/*
Find duplicates in an array 
https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1/?ref=self
https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/
https://www.geeksforgeeks.org/duplicates-array-using-o1-extra-space-set-2/

Given an array A[], Your task is to complete the function printDuplicates which prints 
the duplicate elements of the given array. If no duplicate element is found  print -1.

Note: Auxiliary Space must be O(1) and Time complexity must be O(n).

Input:  
The first line of input contains an integer T denoting the no of test cases. 
Then T test cases follow. Each test case contains an integer N 
which denotes number of elements of Array. Second line of each test case contains 
N space separated integers denoting elements of Array A[].

Output:
Print the duplicate elements from the array.The order of the output should be as the element found to be repeated.

Constraints:
1<=T<=100
1<=N<=50
0<=A[]<N

Example:
Input:
2
4
0 3 1 2
5
2 3 1 2 3 
Output:
-1
2 3 

*/

/*

(Use array elements as index)
4
0 3 3 3

5
0 3 1 0 3

*/


#include <iostream>
using namespace std;

 int absv(int a)
{
    return a>0? a:-a;
}

void printDuplicates(int arr[], int n)
{
   //add code here.
   bool bfind = false;
    for(int i = 0; i<n; ++i)
    {
        if( absv(arr[i])<  n)
        {
            if(arr[ absv(arr[i]) ] >= 0)
            {
                arr[ absv(arr[i]) ] = -arr[absv(arr[i])];
            }
            else
            {
                if(arr[absv(arr[i])] != n)
                {
                    bfind = true;
                    cout<<absv(arr[i])<<" ";
                    arr[absv(arr[i])] = n;
                }

            }
        }

    }
    if(!bfind)
    {
        cout<<-1;
    }
    //cout<<endl;


}

int main()
{
    


    return 0;
}