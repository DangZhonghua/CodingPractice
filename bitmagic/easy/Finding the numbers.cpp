/*
Finding the numbers

https://practice.geeksforgeeks.org/problems/finding-the-numbers/0

You are given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. You need to find the other two numbers and print them in ascending order.
 

Input :
The first line contains a value T, which denotes the number of test cases. Then T test cases follow .The first line of each test case contains a value N. The next line contains 2*N+2 space separated integers.

Output :
Print in a new line the two numbers in ascending order.

Constraints :
1<=T<=100
1<=N<=10^6
1<=A[i]<=5*10^8

Example:
Input :
2
2
1 2 3 2 1 4
1
2 1 3 2

Output :
3 4
1 3

*/


/*

Method 1(Use Sorting)
First sort all the elements. In the sorted array, by comparing adjacent elements 
we can easily get the non-repeating elements. Time complexity of this method is O(nLogn)

Method 2(Use XOR)
Let x and y be the non-repeating elements we are looking for and arr[] be the input array. 
First calculate the XOR of all the array elements.

     xora = arr[0]^arr[1]^arr[2].....arr[n-1]

All the bits that are set in xora will be set in one non-repeating element (x or y) 
and not in other. So if we take any set bit of xora and divide the elements of 
the array in two sets – one set of elements with same bit set and other set with same bit not set. 
By doing so, we will get x in one set and y in another set. 
Now if we do XOR of all the elements in first set, 
we will get first non-repeating element, 
and by doing same in other set we will get the second non-repeating element


*/

#include<iostream>
#include<vector>
using namespace std;

int FindTheNonRepeatNumber(vector<int>& a)
{
    int xora = a[0];
    for(int i = 1; i<a.size(); ++i)
    {
        xora ^=a[i];
    }
    
    int bit_diff = xora &(~(xora-1));
    
    int x = 0;
    int y = 0;
    
    for(int i = 0; i<a.size(); ++i)
    {
        if(bit_diff & a[i])
        {
            x ^=a[i];
        }
        else
        {
            y ^=a[i];
        }
    }
    if(x<y)
    {
        cout<<x<<" "<<y<<endl;
    }
    else
    {
        cout<<y<<" "<<x<<endl;
    }

    return 0;
}


int main()
{
    int t = 0;
    int N = 0;
   

    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int c = 2*N+2;
        vector<int>  a(c,0);
        int i = 0;
        while(i<c)
        {
            int j = 0;
            cin>>j;
            a[i++] = j;
        }
        FindTheNonRepeatNumber(a);
        
    }

    return 0;        
}