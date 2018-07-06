/*
Minimum Cost To Make Two Strings Identical
https://practice.geeksforgeeks.org/problems/minimum-cost-to-make-two-strings-identical/0/?ref=self
Given two strings X and Y, and two values costX and costY.
We need to find minimum cost required to make the given two strings identical.
We can delete characters from both the strings.
The cost of deleting a character from string X is costX and from Y is costY.
Cost of removing all characters from a string is same.

Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. The first line of each test case contains integers X and Y
denoting the value of costX and costY.
The second line of the test case contains the two strings X and Y.


Output:
Print the total cost to make the two strings equal for each test case in a new line.

Constraints:

1<= T <=100
1<= length of strings X and Y <=1000
1<= costX, costY <=1000

Example:

Input:

1
10 20
abcd acdb

Output:
30

1
384 887
bbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmcoqhnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcacehchzvfrkmlnozjkpqpxrjxkitzyxacbhhkicqcoendtomfgdwdwfcgpxiqvkuytdlcgdewhtaciohordtqkvwcsgspqoqmsboaguwnnyqxnzlgdgwpbtrwblnsadeuguumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayulyeimuotehzriicfskpggkbbipzzrzucxamludfykgruowzgiooobppleqlwphapjnadqhdcnvwdtxjbmyppphauxnspusgdhiixqmbfjxjcvudjsuyibyebmwsiqyoygyxymzevypzvjegebeocfuftsxdixtigsieehkchzdflilrjqfnxztqrsvbspkyhsenbppkqtpddbuotbbqcwivrfxjujjddntgeiqvdgaijvwcyaubwewpjvygehljxepbpiwuqzdzubdubzvafspqpqwuzifwovyddwyvvburczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlk obmeahkgccnaehhsveymqpxhlrnunyfdzrhbasjeuygafoubutpnimuwfjqsjxvkqdorxxvrwctdsneogvbpkxlpgdirbfcriqifpgynkrrefxsnvucf

Its Correct output is:
294880
*/

/*

this problem is just like LCS. But tricky part is the initialization part

	for (int i = 0; i <= R; ++i) //for the second string is empty
	{
		cost[i][0] = i*cx;
	}
	for (int j = 0; j <= C; ++j)
	{
		cost[0][j] = j*cy;
	}
	cost[0][0] = 0;
    

                cost[i-1][j-1] if x[i] = y[j]
cost[i][j] = 
                min{cost[i-1][j]+costx, cost[i][j-1] + costy} if x[i] != y[j]

*/



#include<iostream>
#include<vector>
#include<string>
using namespace std;


int minCostDelete(const string& x, int cx, const string& y, int cy)
{
	int R = x.length();
	int C = y.length();
	vector< vector<int> > cost(R + 1, vector<int>(C + 1, 0));


    // Initialize part is the important for this kind problem.
	for (int i = 0; i <= R; ++i) //for the second string is empty
	{
		cost[i][0] = i*cx;
	}
	for (int j = 0; j <= C; ++j)
	{
		cost[0][j] = j*cy;
	}
	cost[0][0] = 0;

	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if (x[i - 1] == y[j - 1])
			{
				cost[i][j] = cost[i - 1][j - 1];
			}
			else
			{
				cost[i][j] = cost[i - 1][j] + cx;
				if (cost[i][j] > cost[i][j - 1] + cy)
				{
					cost[i][j] = cost[i][j - 1] + cy;
				}
			}
		}
	}

	cout << cost[R][C] << endl;

	return 0;
}


int main()
{
	int t = 0;
	int costx = 0;
	int costy = 0;
	string x, y;

	cin >> t;

	while (t--)
	{
		cin >> costx >> costy;
		cin >> x >> y;
		minCostDelete(x, costx, y, costy);
	}


	return 0;
}