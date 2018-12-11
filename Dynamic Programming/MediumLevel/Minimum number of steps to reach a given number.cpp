/*
Minimum number of steps to reach a given number
https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number/0
https://www.geeksforgeeks.org/minimum-steps-to-reach-a-destination/

Given a number line from -infinity to +infinity. You start at 0 and can go either to the left or to the right.
The condition is that in i’th move, you take i steps. You are given a Destination ,
you have to print the minimum number of steps required to reach that destination.

Input:
The first line of the input contains the number of test cases T,
then T lines follow and each lines contains an integer D specifying the destination.


Output:
Corresponding to each test case print in a new line the minimum number of steps required to reach that destination.

Constraints:
1<=T<=100
0<=D<=1000

Example:
Input:
2
2
10

Output:
3
4
Explanation:
In the first test case we can go from 0 to 1 (1 step) and then from 1 to -1 (2 steps) and
then from -1 to 2 (3 steps). So in 3 steps we have reached our destination by taking i steps in ith turn.

*/


/*
optimal substructure and overlapped sub-problems.

optimal substructure is: based on previous min steps
overlapped: select min steps for every number when do translate.

MR[x]  = INT_MAX
MR[0]  = 0;
MR[-1] = MR[0] + 1
MR[1]  = MR[0] + 1

MR[d] = MR[a] + 1 if a+i == d
MR[d] = MR[b] + 1 if b-j == d
MR[d] = min{MR[a]+1, MR[b]+1};

*/

/*
I think geeksforgeeks give wrong anwser

*/

#include<iostream>
#include<vector>
#include<climits>
#include<unordered_set>
#include <unordered_map>
#include <map>
using namespace std;


int FindAllMinimumSteps(int D, map<int,int>& mv)
{
	int ret = 0;
	int minsteps = 0;
	int cursteps = 1;
	bool bStop = false;

	vector< unordered_set<int> > vd(2, unordered_set<int>());
	mv[0] = 0;
	vd[1].insert(0);

	while (!bStop)
	{
		int base = (cursteps & 1);
		int next = ((cursteps + 1) & 1);
		for (auto it = vd[base].begin(); it != vd[base].end(); ++it)
		{
			if (((*it) + cursteps) == D || ((*it) - cursteps) == D)
			{
				mv[D] = cursteps;
				bStop = true;
				break;
			}
			else
			{
				if (((*it) + cursteps) > 0)
				{
					auto itm = mv.find(((*it) + cursteps));
					if (itm != mv.end() && itm->second >cursteps)
					{
						itm->second = cursteps;
					}
					else if (itm == mv.end())
					{
						mv[((*it) + cursteps)] = cursteps;
						
					}
					
				}
				if ( ((*it) - cursteps)>0 )
				{
					auto itm = mv.find(((*it) - cursteps));
					if (itm != mv.end() && itm->second > cursteps)
					{
						itm->second = cursteps;
					}
					else if ( itm == mv.end())
					{
						mv[((*it) - cursteps)] = cursteps;
					}
				}
				vd[next].insert(((*it) + cursteps));
				vd[next].insert(((*it) - cursteps));
			}
		}
		if (!bStop)
		{
			vd[base].clear();
			++cursteps;
		}
	}


	return ret;
}

int MinimumSteps(int D)
{
	if (0 == D)
	{
		cout << 0 << endl;
		return 0;
	}

	int ret = 0;
	int minsteps = 0;
	int cursteps = 1;
	bool bStop = false;
	vector< unordered_set<int> > vd(2, unordered_set<int>());

	vd[1].insert(0);

	while (!bStop)
	{
		int base = (cursteps & 1);
		int next = ((cursteps + 1) & 1);
		for (auto it = vd[base].begin(); it != vd[base].end(); ++it)
		{
			if (((*it) + cursteps) == D || ((*it) - cursteps) == D)
			{
				bStop = true;
				break;
			}
			else
			{
				vd[next].insert(((*it) + cursteps));
				vd[next].insert(((*it) - cursteps));
			}
		}
		if (!bStop)
		{
			vd[base].clear();
			++cursteps;
		}
	}
	cout << cursteps << endl;
	return ret;
}


int main(int argc, char const *argv[])
{
	int t = 0;

	MinimumSteps(422);
	map<int, int> mv;
	FindAllMinimumSteps(1000,mv);

	cin >> t;

	while (t--)
	{
		int D = 0;
		cin >> D;
		cout << mv[D]<<endl;
	}
	
	for (auto it = mv.begin(); it != mv.end(); ++it)
	{
		cout << it->first << " : "<<it->second<<endl;
	}

	return 0;
}
