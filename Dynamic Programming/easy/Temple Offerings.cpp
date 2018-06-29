/*
Temple Offerings
https://practice.geeksforgeeks.org/problems/temple-offerings/0

Consider a devotee wishing to give offerings to temples along a mountain range. 
The temples are located in a row at different heights. 
Devotee is very religious and wants to offer each temple at least one offering. 
If two adjacent temples are at different altitudes, 
then the temple that is higher up should receive more offerings than the one that is lower down. 
If two adjacent temples are at the same height, then their offerings relative to each other does not matter. 
Find the minimum number of offerings to bring.

Input:
The first line of the input contains an integer T, denoting the number of test cases. 
Then T test cases follow. First line of each test case contains an integer N denoting the total number of temples. 
Next line contains N space seperated integers denoting the height of the respective temple.

Output:
For each test case output a single line denoting the minimum number of offering that the devotee should bring.

Constraints:
1<=T<=10^4
1<=N<=10^6
1<=templeHeight<=10^3

Example:
Input:
2
3
1 2 2
6
1 4 3 6 2 1

Output:
4
10

Explanation:

Test case 1:

All temples must receive at-least one offering. Now, the second temple is at a higher altitude compared to the first one. 
Thus it receives one extra offering. The second temple and third temple are at the same height, 
so we do not need to modify the offerings. Offerings given are therefore: 1, 2, 1 giving a total of 4.

Test case 2:

We can distribute the offerings in the following way, 1, 2, 1, 3, 2, 1. 
The second temple has to receive more offerings than the first due to its height being higher. 
The fourth must receive more than the fifth, which in turn must receive more than the sixth. Thus the total becomes 10.

*/

/*
Sub-problem: the lower altitude offer can be used to calculate higher altitude offer.
this is bottom style
some test case:

2
11
165 647 1117 743 1060 357 1053 816 387 924 281 
2
473 145

*/


#include<iostream>
#include<vector>
using namespace std;

int a[1000000] = { 0 };

int MinTempleOffering(int*a, int N)
{
	vector<int>   vf(N + 1, 0);
	int minimumOffer = 0;

	//Initialize the lowest altitude temple offer
    int minlevel  = 10001;
    int maxlevel  = 0;

    for(int i  = 0; i< N; ++i)
    {
        if(minlevel>a[i])
        {
            minlevel = a[i];
        }
        if(maxlevel<a[i])
        {
            maxlevel = a[i];
        }
    }


	for (int i = 0; i <N; ++i)
	{
		if (minlevel == a[i])
		{
			vf[i] = 1;
			++minimumOffer;
		}
	}

	for (int h = minlevel + 1; h <= maxlevel; ++h)
	{
		for (int i = 0; i < N; ++i)
		{
			if (h != a[i])
			{
				continue;
			}
			//Find the current iteration target.
			vf[i] = 1;
			if (i - 1 >= 0 && a[i] > a[i - 1] && vf[i] < vf[i - 1] + 1)
			{
				vf[i] = vf[i - 1] + 1;
			}
			if (i + 1 < N && a[i] > a[i + 1] && vf[i] < vf[i + 1] + 1)
			{
				vf[i] = vf[i + 1] + 1;
			}
			minimumOffer += vf[i];
		}
	}

	cout << minimumOffer << endl;

	return 0;
}



int main()
{
	int t = 0;
	int N = 0;


	cin >> t;

	while (t--)
	{
		cin >> N;
		int i = 0;
		while (i < N)
		{
			cin >> a[i++];
		}
		MinTempleOffering(a, N);
	}
	return 0;
}