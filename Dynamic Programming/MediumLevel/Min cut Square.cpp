/*
Min cut Square 
https://practice.geeksforgeeks.org/problems/min-cut-square/0/?ref=self
Given a paper of size A x B. Task is to cut the paper into squares of any size. Find the minimum number of squares that can be cut from the paper.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two integer A and B denoting the two size of the paper.

Output:
Print the minimum number of squares that can be cut from the paper.

Constraints:
1<=T<=10^5
1<=A<=10^5
1<=B<=10^5

Example:
Input:
2
13 29
30 35

Output:
9
5

*/

#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int m[301][301];


int CutPaperWithMinSquare(int L, int W);
int CutPaperWithMinSquareMatrix(int L, int W);


int main()
 {
    int t = 0;
    int L = 0;
    int W = 0;
    

    cin>>t;
    while(t)
    {
        --t;
        cin>>L;
        cin>>W;
        CutPaperWithMinSquareMatrix(L,W);
    }


	return 0;
}


int CutPaperWithMinSquareMatrix(int L, int W)
{
	if (L == W)
	{
		cout << 1 << endl;
		return 0;
	}

	//vector <vector<int> > m;
	//ULONGLONG  nStart = GetTickCount64();
//	for (int i = 0; i <= L; ++i)
	//{
	//	vector<int> row;
	//	row.resize(W + 1, 0);
	//	m.push_back(row);
	//	row.clear();
//	}
	//ULONGLONG  nEnd = GetTickCount64();

	//cout << "asdasdsadsada"<<endl;
	//cout<<(nEnd-nStart)/1000<<endl;

	m[1][1] = 1;
	//for (int w = 1; w <= W; ++w)
	{
		for (int l = 1; l <= L; ++l)
		{
			for (int w = 1; w <= W; ++w)
			{
				if (l == w)
				{
					m[l][w] = 1;
				}
				else if (0 == l%w || 0 == w%l)
				{
					m[l][w] = l>w? l/w:w/l;
				}
				else
				{
					m[l][w] = L*W;
					for (int i = 1; i <= l / 2; ++i)
					{
						if (m[l][w] > m[i][w] + m[l - i][w])
						{
							m[l][w] = m[i][w] + m[l - i][w];
						}
					}
					for (int j = 1; j <= w / 2; ++j)
					{
						if (m[l][w] > m[l][j] + m[l][w - j])
						{
							m[l][w] = m[l][j] + m[l][w - j];
						}
					}
				}
			}
		}
	}


	cout << m[L][W] << endl;

	return 0;
}