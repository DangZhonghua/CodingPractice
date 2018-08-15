/*
https://www.geeksforgeeks.org/number-of-circular-tours-that-visit-all-petrol-pumps/
Number of circular tours that visit all petrol pumps


Suppose there is a circular road. There are n petrol pumps on that road.
You are given two array, a[] and b[], and a positive integer c.
where a[i] denote the amount of fuel we get on reaching ith petrol pump,
b[i] denote the amount of fuel used to travel from ith petrol pump to (i + 1)th
petrol pump and c denotes the capacity of the tank in the vehicle.
The task is to calculate the number of petrol pump from where the vehicle
will be able to complete the circle and come back to starting point.
This post is different from Find the first circular tour that visits all petrol pumps.
Examples:

Input : n = 3, c = 3
a[] = { 3, 1, 2 }
b[] = { 2, 2, 2 }
Output : 2
Explanation:
If we starts with 0th petrol pump, we will gain
3 (a[0]) litres of petrol and lose 2 litre (b[0] to travel
to 1st petrol pump.On refueling 1 litre (a[1])
of petrol on 1st petrol pump, we will lose 2
litres (b[0]) of petrol to reach 2nd petrol pump.
Now the tank is empty.On refueling 2 litres (a[2]) of petrol
at 2nd petrol pump, we can travel back 0th
petrol pump.

If we starts from 1st petrol pump, we will gain 1
litre of petrol but to travel to 2nd petrol pump
we need 2 litres of petrol, which we don’t have. So, we cannot
starts from 1st petrol pump.

If we starts from 2nd petrol pump, we will gain 2
litres of petrol and travel to 0th petrol pump by
losing 2 litres of petrol. On refueling 3 litres on 1st
petrol pump, we can travel to 1st petrol
pump by losing 2 litre petrol. On refueling 1 litre of petrol, we
will have 2 litres of petrol left which we can use by traveling to
2nd petrol pump.

Input : n = 3, c = 3
a[] = { 3, 1, 2 }
b[] = { 2, 2, 1 }
Output : 2


*/

/*

p[i] = min{p[i-1]+a[i]-b[i],C}
if( p[i] >=0 ) can go ahead.


m[i][p] = true if p+a[i]-b[i]>=0

*/

#include<iostream>
#include<vector>
using namespace std;

int numberofCircularTours(int*a, int*b, int N, int C)
{
	vector< vector<bool> > ct(N, vector<bool>(C + 1, true));

	for (int i = 0; i<N; ++i)
	{
		//p is the petrol number before passing station i.
		for (int p = 0; p <= C; ++p)
		{
			if (a[i] + p < b[i])
			{
				ct[i][p] = false;
			}
		}
	}

	int ncount = 0;
	vector<int> vs;

	for (int i = 0; i<N; ++i)
	{
		if (!ct[i][0]) //Can't start from the ith statation
		{
			continue;
		}
		int p = (a[i] - b[i] > C - b[i] ? C - b[i] : a[i] - b[i]);
		int j = i + 1;
		if (N == j)
		{
			j = 0;
		}

		while (i != j)
		{
			if (!ct[j][p])
			{
				break;
			}
			p = ((p + a[i] - b[j] > C - b[j]) ? C - b[j] : (p + a[j] - b[j]));
			++j;
			if (N == j)
			{
				j = 0;
			}
		}
		if (i == j)
		{
			++ncount;
			vs.push_back(i);
		}
	}

	cout << ncount << endl;
	for (auto e : vs)
	{
		cout << "Start from: " << e << endl;
	}

	return 0;
}


int main()
{
	int a[] = { 3, 1, 2 };
	int b[] = { 2, 2, 1 };
	int C = 3;
	int N = _countof(a);

	numberofCircularTours(a, b, N, C);

	return 0;
}