/*
Stock buy and sell 
https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0

The cost of a stock on each day is given in an array, find the max profit that you can make 
by buying and selling in those days. 

Input:
First line contains number of test cases T. Each test case contain the integer value 'N' 
denoting days followed by an array of stock prices in N days.
Output:
The maximum profit is displayed as shown below. And if there is no profit then print "No Profit".


Constraints:
1 <=T<= 100
2 <=N<= 100
1 <=arr[i]<= 10000


Example

Input:
2
7
100 180 260 310 40 535 695
10
23 13 25 29 33 19 34 45 65 67

Output:

(0 3) (4 6) 
(1 4) (5 9) 

Notice: Output format is as follows - (buy_day sell_day) (buy_day sell_day)
For each input, output should be in a single line.


*/

/*

this is problem of looking up  increaseing subarray.
a[i]<a[j] continue
a[i]>a[j] started from a[j] a new subarray.

84
886 2777 6915 7793 8335 5386 492 6649 1421 2362 27 8690 59 7763 3926 540 3426 9172 5736 5211 5368 2567 6429 5782 1530 2862 5123 4067 3135 3929 9802 4022 3058 3069 8167 1393 8456 5011 8042 6229 7373 4421 4919 3784 8537 5198 4324 8315 4370 6413 3526 6091 8980 9956 1873 6862 9170 6996 7281 2305 925 7084 6327 336 6505 846 1729 1313 5857 6124 3895 9582 545 8814 3367 5434 364 4043 3750 1087 6808 7276 7178 5788


*/

#include<iostream>
#include<vector>
using namespace std;

int MaximumValueStockBuyAndSell(int*a, int N)
{
    vector< pair<int,int> > st;
    int i = 0;  //i IS the previous element index which is used to compare
    int s = 0; //s  IS the range start
    int j = 1; // j IS the traversal pointer
    for(j = 1; j<N; ++j)
    {
        if(a[i]<a[j])
        {
            i = j;
        }
        else
        {
            if(i-s>=1)
            {
                st.push_back( std::make_pair(s,i) );
            }
            s = j;
            i = j;
        }
    }

    if(j-s>1)
    {
        st.push_back(std::make_pair(s,j-1));
    }

    if(st.size() == 0)
    {
        cout<<"No Profit"<<endl;
    }
    else
    {
        for(int k = 0; k<st.size(); ++k)
        {
            cout<<"("<<st[k].first<<" "<<st[k].second<<") ";
        }

        cout<<endl;
    }

    return 0;
}


int main()
{
    int t = 0;
    int N = 0;
    int a[200];
    
    cin>>t;

    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        MaximumValueStockBuyAndSell(a,N);
    }

    return 0;
}