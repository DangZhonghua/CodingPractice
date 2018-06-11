/*
Next greater number set digits 
https://practice.geeksforgeeks.org/problems/next-greater-number-set-digits/0

Given a number n, find the smallest number that has same set of digits as n and is greater than n. If x is the greatest possible number with its set of digits, then print “not possible”.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is n,n is the number.

Output:

Print the greater number than n with same set of digits and if not possible then print "not possible" without double quote.

Constraints:

1 ≤ T ≤ 100
1 ≤ n ≤ 100000

Example:

Input
2
143
431

Output
314
not possible

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


 int SearchNumber(vector<int>&a)
{
    int index  = -1;
    


}




int nextlarger(int N)
{
    bool bFind =false;
    vector<int> vnum;
    vector<int> vsort;   
    int t = N;
    while(t)
    {
        vnum.push_back(t%10);
        t /= 10;
    }
    vsort = vnum;

    std::sort(vsort.begin(), vsort.end());
    
    for(int i = vnum.size()-1; i>=0; --i)
    {
        
    }
    
    

    if(bFind)
    {
        int num = 0;
        int base = 1;
        for(int i = 0; i<vnum.size(); ++i)
        {
            num += base*vnum[i];
            base *=10;
        }
        cout<<num<<endl;
    }
    else
    {
        cout<<"not possible"<<endl;
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
        nextlarger(N);
    }

    
    return 0;
}