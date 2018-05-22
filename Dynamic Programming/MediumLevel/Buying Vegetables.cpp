/*
Buying Vegetables 

https://practice.geeksforgeeks.org/problems/buying-vegetables/0


Rahul wanted to purchase vegetables mainly brinjal, carrot and tomato. 
There are N different vegetable sellers in a line. 
Each vegetable seller sells all three vegetable items, 
but at different prices. Rahul, obsessed by his nature to spend optimally, 
decided not to purchase same vegetable from adjacent shops. 
Also, Rahul will purchase exactly one type of vegetable item (only 1 kg) from one shop. 
Rahul wishes to spend minimum money buying vegetables using this strategy. 
Help Rahul determine the minimum money he will spend.

Input:
First line indicates number of test cases T. 
Each test case in its first line contains N denoting the number of vegetable sellers in Vegetable Market. 
Then each of next N lines contains three space separated integers denoting cost of brinjal, carrot and tomato per kg with that particular vegetable seller.

Output:
For each test case, output the minimum cost of shopping taking the mentioned conditions into account in a separate line.

Constraints:
1 <= T <= 10
1 <= N <= 100000
Cost of each vegetable(brinjal/carrot/tomato) per kg does not exceed 10^4

Example
Input:
1
3
1 50 50
50 50 50
1 50 50
Output:
52
Explanation:
There are two ways, each one gives 52 as minimum cost. 
One way is buy brinjals from first shop, carrots from second shop and brinjals from third shop or 
he can buy brinjals from first shop, tomatoes from second shop and brinjals from third shop.
Both ways , cost comes up to 1 + 50 + 1 = 52


*/

/*

Overlapped sub-problem and optimal sub-structure.

*/

#include<iostream>
#include<climits>
using namespace std;

long long sell[100001][3];
long long bv[100001][3];


int BuyVegetable(long long sell[100001][3], long long bv[100001][3], int N)
{
	for (int i = 1; i < N; ++i)
	{
		bv[i][0] = INT_MAX;
		bv[i][1] = INT_MAX;
		bv[i][2] = INT_MAX;
	}
	bv[0][0] = sell[0][0];
	bv[0][1] = sell[0][1];
	bv[0][2] = sell[0][2];


	for (int i = 1; i < N; ++i)
	{
		bv[i][0] = sell[i][0] + (bv[i - 1][1] > bv[i - 1][2] ? bv[i - 1][2] : bv[i - 1][1]);
		bv[i][1] = sell[i][1] + (bv[i - 1][0] > bv[i - 1][2] ? bv[i - 1][2] : bv[i - 1][0]);
		bv[i][2] = sell[i][2] + (bv[i - 1][0] > bv[i - 1][1] ? bv[i - 1][1] : bv[i - 1][0]);

	}

    long long min = bv[N-1][0];
    
    if(min>bv[N-1][1])
    {
        min = bv[N-1][1];
    }
    if(min>bv[N-1][2])
    {
        min = bv[N-1][2];
    }

	cout << min << endl;
	return 0;
}


int main()
{
	int t = 0;
	int N = 0;

	cin >> t;

	while (t > 0)
	{
		--t;
		cin >> N;
		int i = 0;
		while (i < N)
		{
			cin >> sell[i][0];
			cin >> sell[i][1];
			cin >> sell[i][2];
			++i;
		}
		BuyVegetable(sell, bv, N);
	}




}