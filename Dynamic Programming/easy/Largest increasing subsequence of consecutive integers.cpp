/*
Largest increasing subsequence of consecutive integers

Given an array of n positive integers. We need to find the largest increasing sequence of consecutive positive integers.

Examples:

Input : arr[] = {5, 7, 6, 7, 8} 
Output : Size of LIS = 4
         LIS = 5, 6, 7, 8

Input : arr[] = {5, 7, 8, 7, 5} 
Output : Size of LIS = 2
         LIS = 7, 8

*/

#include<iostream>
#include<vector>

using namespace std;

int LCIS(int*a, int N)
{
    int max = 1;
    vector<int> cis(N+1,1);
    for(int i = 1; i<N;++i)
    {
        for(int j = 0; j<i; ++j)
        {
            if(a[j] + 1==a[i] && cis[i]< cis[j] + 1)
            {
                cis[i] = cis[j] + 1;
            }
        }
        if(max<cis[i])
        {
            max = cis[i];
        }
    }
    cout<<max<<endl;
    return 0;
}

int main()
{
    //int a[] = {5, 7, 6, 7, 8};
    int a[] = {5, 7, 8, 7, 5} ;
    
    LCIS(a,_countof(a));

    return 0;
}


/*

// Function for LIS
int findLIS(int A[], int n)
{
    unordered_map<int, int> hash;
 
    // Initialize result
    int LIS_size = 1;
    int LIS_index = 0;
 
    hash[A[0]] = 1;
 
    // iterate through array and find
    // end index of LIS and its Size
    for (int i = 1; i < n; i++) {
        hash[A[i]] = hash[A[i] - 1] + 1;
        if (LIS_size < hash[A[i]]) {
            LIS_size = hash[A[i]];
            LIS_index = A[i];
        }
    }
 
    // print LIS size
    cout << "LIS_size = " << LIS_size << "\n";
 
    // print LIS after setting start element
    cout << "LIS : ";
    int start = LIS_index - LIS_size + 1;
    while (start <= LIS_index) {
        cout << start << " ";
        start++;
    }
}
 
// driver
int main()
{
    int A[] = { 2, 5, 3, 7, 4, 8, 5, 13, 6 };
    int n = sizeof(A) / sizeof(A[0]);
    findLIS(A, n);
    return 0;
}


*/