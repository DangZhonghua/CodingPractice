/*
https://practice.geeksforgeeks.org/problems/unique-partitions/0

Given a positive integer n, generate all possible unique ways to represent n as sum of positive integers.
The output should be printed in lexicographically decreasing order partitions.
For example, if given number is 52, then 52 itself should be printed first, then 51 1, then 50 2,  ... 
and at the end partition with all 1s.

Note :  2+1 and 1+2 are considered as duplicates.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.

Output:

Print all possible unique ways to represent n as sum of positive integers.

Constraints:

1 ≤ T ≤ 20
1 ≤ N ≤ 30

Example:

Input
2
3
4

Output
3 2 1 1 1 1
4 3 1 2 2 2 1 1 1 1 1 1


Explanation

For n=4 

4
3 1
2 2
2 1 1
1 1 1 1 

These 5 possible ways are there so that we can get the sum 4 .


*/
/*

    Dynamic Programming: (1)Optimal sub-structure (2) overlapped sub-problems. 
    But it is general description. For practical problem: analyze the charactic of problem target with
    reduce the problem scale, and but whole from small scale.

*/


#include<iostream>
#include<vector>
#include<iterator>
using namespace std;


static const int max_count = 40;

struct sumpartition
{
    vector<int> seg;
};

int UniquePartition(int N)
{
    vector< sumpartition > segarr[max_count];
    
    //This is the base case.
    sumpartition sp;
    sp.seg.push_back(1);
    segarr[1].push_back(sp);

    for(int n = 2; n<=N; ++n)
    {
        //this is which the first for every element.
        sumpartition sp;
        sp.seg.push_back(n);
        segarr[n].push_back(sp);
        sp.seg.clear();
        int preindex = 1;

        int base = n-1;
        while(base>=1)
        {
            if(base>=(n/2+n%2)) //the first part
            {
                sumpartition sp;
                sp.seg.clear();
                sp.seg.push_back(base);
                sp.seg.push_back(n-base);
                segarr[n].push_back(sp);
                //Now lets handle (n-base): assemble them into base:[...] base:[....]
                for(int p = 1; p<segarr[n-base].size(); ++p)
                {
                    sp.seg.clear();
                    sp.seg.push_back(base);
                    std::copy(segarr[n-base][p].seg.begin(), segarr[n-base][p].seg.end(), back_inserter(sp.seg));
                    segarr[n].push_back(sp); 

                }
            }
            else
            {
                int p = 0;
                while(base < segarr[n-base][p].seg[0])
                {
                    ++p;
                }

                sumpartition sp;
                //Now lets handle (n-base): assemble them into base:[...] base:[....]
                for(; p<segarr[n-base].size(); ++p)
                {
                    sp.seg.clear();
                    sp.seg.push_back(base);
                    std::copy(segarr[n-base][p].seg.begin(), segarr[n-base][p].seg.end(), back_inserter(sp.seg));
                    segarr[n].push_back(sp); 
                }
                
            }
            --base;

        }

    }
    
    for(int segindex = 0; segindex<segarr[N].size(); ++segindex)
    {
        for(int e = 0; e<segarr[N][segindex].seg.size(); ++e)
        {
            cout<< segarr[N][segindex].seg[e]<<" ";
        }
        //cout<<endl;
    }
    cout<<endl;
    
    

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
        UniquePartition(N);
    }


    return 0;
}