/*
https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst/0


Given an array, write a program that prints 1 if given array can represent preorder traversal of a BST, else prints 0.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the size of array.
The second line of each test case contains N input A[i].

Output:
Should print 1 if given array can represent preorder traversal of BST. Otherwise 0.

Constraints:
1 <=T<= 55
1 <= N <= 1000
1 <= arr[i] <= 1000

Example:

Input:
3
5
40 30 35 80 100
8
40 30 32 35 80 90 100 120
8
7  9 6 1 4 2 3 40

Output:
1
1
0

*/

/*

This problem main purpose: construct BST from tree pre-order seq. if the BST can be constructed
so its true.

*/

#include<vector>
#include<queue>
#include<iostream>
#include<unordered_map>
using namespace std;

int JudgePreOrderOfBST(int*a, int N)
{
    struct Qitem
    {
        int s;
        int e;
        Qitem(int b, int c)
        {
            s = b;
            e = c;
        }
    };
    vector<Qitem> scanQ;
    vector<char>  branchQ;
    vector<int>   parentQ; 
    Qitem item(0,N-1);


    scanQ.push_back(Qitem(0,0));
    parentQ.push_back(0);
    branchQ.push_back(0);
    
    scanQ .push_back(item);
    parentQ.push_back(0);
    branchQ.push_back(0);

    
    int     index = 1;
    bool    bBst = true;
    while(bBst && index<scanQ.size())
    {
        //First check whether it is BST up to now.
        int current = index;
        int parent  = parentQ[current];
        while(parent && bBst)
        {
            if(branchQ[current] == 'L')
            {
                if(a[scanQ[parent].s] < a[scanQ[index].s])
                {
                    bBst = false;
                    break;
                }
            }
            if(branchQ[current] == 'R')
            {
                if(a[scanQ[parent].s] > a[scanQ[index].s])
                {
                    bBst = false;
                    break;
                }
            }
            current = parent;
            parent = parentQ[current];
        }
        
        if(!bBst)
        {
            break;
        }

        //Find the partiton postion
        if(scanQ[index].s == scanQ[index].e) //There is only one element in the range.
        {
            ++index;
            continue;
        }

        int p = 0;
        for(p = scanQ[index].s+1; p<=scanQ[index].e; ++p )
        {
            if(a[p]>a[scanQ[index].s])
            {
                break;
            }
        }

        if(p>scanQ[index].e) //There is only left sub-tree
        {
            parentQ.push_back(index);
            branchQ.push_back('L');
            scanQ.push_back(Qitem(scanQ[index].s+1,scanQ[index].e) );
        }
        else if(p==scanQ[index].s+1) //There is only right sub-tree
        {
            parentQ.push_back(index);
            branchQ.push_back('R');
            scanQ.push_back(Qitem(scanQ[index].s+1,scanQ[index].e) );
        }
        else
        {
            parentQ.push_back(index);
            branchQ.push_back('L');
            scanQ.push_back(Qitem(scanQ[index].s+1,p-1));
            
            parentQ.push_back(index);
            branchQ.push_back('R');
            scanQ.push_back(Qitem(p,scanQ[index].e));
        }
        ++index;
    }

    cout<<(bBst?1:0)<<endl;
    

    return 0;
}



int main()
{
    int t = 0;
    int N = 0;
    int a[1001];


    cin>>t;

    while(t--)
    {
        cin>>N;
        int i = 0;

        while(i<N)
        {
            cin>>a[i++];
        }
        JudgePreOrderOfBST(a,N);
    }
  
    return 0;
}