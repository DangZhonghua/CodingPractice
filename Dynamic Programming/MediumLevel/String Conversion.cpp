/*
String Conversion
https://practice.geeksforgeeks.org/problems/string-conversion/0

Given two strings X and Y (call letters in uppercase). Check if it is possible to convert X to Y by performing following operations.

Make some lowercase letters uppercase.
Delete all the lowercase letters.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string X and Y respectively
The next two lines contain the 2 string X and Y.


Output:
For each test case print the "Yes" if it's  possible to convert X to Y by performing following operations else "No".


Constraints:
1<=T<=200
1<=size(X),size(Y)<=100
'a'<=X[i]<='z'
'A'<=X[i] , Y[i]<='Z'
Example:
Input :

2
5 3
daBcd ABC
4 3
ABcd BCD

Output :
Yes
No
Explanation :

Test Case 1:  daBcd -> dABCd -> ABC Covert a and b at index 1 and 3 to upper case, delete the rest those are lowercase.
We get the string Y so the output is: Yes.

*/


/*

this is a variable of LCS: LCS(X,Y) = |Y| insensitive case.
WOW, DP again!

0 if i = 0 or j = 0
LCS[i-1][j-1] + 1;
LCS[i][j] =
max{LCS[i-1][j], LCS[i][j-1]}

10 8
EDFBccBcBE EDFBCBBE
29 11
AbcDDefgHilklMNnopqrstvuwXXyz ABCDDHMNXXZ

28 17
abAcjcvxhbdDMKLFNvxfhvndKSFL ABACJDMKLFNNDKSFL

*/

// #include<iostream>
// #include<string>
// #include<unordered_set>
// using namespace std;

// int StringConversion(const char* strx, const char* stry, int n, int m)
// {
// 	int LCS[102][102];
// 	int ELCS[102][102];
// 	int nUpperCount = 0;
// 	unordered_set<int> dict;
// 	//Initialize the matrix.
// 	for (int r = 0; r <= n; ++r)
// 	{
// 		if ('A' <= strx[r] && 'Z' >= strx[r])
// 		{
// 			++nUpperCount;
// 		}

// 		for (int c = 0; c <= m; ++c)
// 		{
// 			LCS[r][c] 	= 0;
// 			ELCS[r][c] 	= 0;
// 		}
// 	}
// 	//First, we calculate the LCS using case sensitive. the longest LCS is |Y| then we check the upper char count in X.
// 	for (int r = 1; r <= n; ++r)
// 	{
// 		for (int c = 1; c <= m; ++c)
// 		{
// 			int i = r - 1;
// 			int j = c - 1;
// 			if (strx[i] == stry[j])
// 			{
// 				LCS[r][c] = LCS[r - 1][c - 1] + 1;
// 			}
// 			else
// 			{
// 				LCS[r][c] = LCS[r - 1][c];
// 				if (LCS[r][c]<LCS[r][c - 1])
// 				{
// 					LCS[r][c] = LCS[r][c - 1];
// 				}
// 			}
// 		}
// 	}
// 	if (LCS[n][m] == m)
// 	{
// 		if (nUpperCount == m)
// 		{
// 			cout << "Yes" << endl;
// 		}
// 		else if (nUpperCount > m)
// 		{
// 			cout << "No" << endl;
// 		}
// 		return 0;
// 	}

// 	////////////////////////////////////////
// 	int nlowercount = 0;
// 	for (int r = 1; r <= n; ++r)
// 	{
// 		for (int c = 1; c <= m; ++c)
// 		{
// 			int i = r - 1;
// 			int j = c - 1;
// 			if (strx[i] == stry[j] )
// 			{
// 				ELCS[r][c] = ELCS[r - 1][c - 1] + 1;
// 				if(ELCS[r][c] == c)
// 				{
// 					unordered_set<int>::iterator it = dict.find(j);
// 					if(it != dict.end())
// 					{
// 						dict.erase(it);
// 						--nlowercount;
// 					}
// 				}
// 			}
// 			else
// 			{
// 				if((strx[i] - 32) == stry[j] && (LCS[r - 1][c - 1] + 1)>LCS[r][c] )
// 				{
// 					if(dict.find(j) == dict.end())
// 					{
// 						++nlowercount;
// 						dict.insert(j);	
// 					}
// 					ELCS[r][c] = ELCS[r - 1][c - 1] + 1;
// 				}
// 				else
// 				{
// 					ELCS[r][c] = ELCS[r - 1][c];
// 					if (ELCS[r][c]<ELCS[r][c - 1])
// 					{
// 						ELCS[r][c] = ELCS[r][c - 1];
// 					}
// 				}
// 			}
// 		}
// 	}
// 	if (ELCS[n][m] == m)
// 	{
// 		if (m - nlowercount == nUpperCount)
// 		{
// 			cout << "Yes" << endl;
// 		}
// 		else
// 		{
// 			cout << "No" << endl;
// 		}
// 	}
// 	else
// 	{
// 		cout << "No" << endl;
// 	}

// 	return 0;
// }


#include<iostream>
#include<string>
#include<unordered_set>
#include<stack>
#include<vector>
using namespace std;

enum 
{
	REL_INVALID,
	REL_EQUAL,
	REL_INEQUAL
};

struct commchar
{
	int op;
	int i;
	int j;
	int pi;
	int pj;
	commchar()
	{
		op = REL_INVALID;
		i = -1;
		j = -1;
		pi = -1;
		pj = -1;
	}
};


bool CalcLCSWithCaseInSensitive(const char* strx, const char* stry, int n, int m)
{
	bool bConvert = true;
	int  LCS[102][102];
	int  nUpperCount = 0;

	//Initialize the matrix.
	for (int r = 0; r <= n; ++r)
	{
		if ('A' <= strx[r] && 'Z' >= strx[r])
		{
			++nUpperCount;
		}

		for (int c = 0; c <= m; ++c)
		{
			LCS[r][c] 	= 0;
		}
	}
	for(int r = 1; r<n; ++r)
	{
		for(int c = 1; c<m; ++c)
		{
			int  i = r-1;
			int  j = c-1;

			if(strx[i]-32 == stry[j])
			{
				LCS[r][c] = LCS[r-1][c-1]+1;
			}
			else
			{
				LCS[r][c] = LCS[r-1][c];
				if(LCS[r][c]<LCS[r][c-1])
				{
					LCS[r][c] = LCS[r][c-1];
				}
			}
		}
	}

	if(nUpperCount || m != LCS[n][m])
	{
		bConvert = false;
	}

	return bConvert;
}

int StringConversion(const char* strx, const char* stry, int n, int m)
{

	int 	 LCS[102][102];
	commchar ELCS[102][102];
	int nUpperCount = 0;
	unordered_set<int> dict;

	//Initialize the matrix.
	for (int r = 0; r <= n; ++r)
	{
		if ('A' <= strx[r] && 'Z' >= strx[r])
		{
			++nUpperCount;
		}

		for (int c = 0; c <= m; ++c)
		{
			LCS[r][c] 	= 0;
			ELCS[r][c] 	= commchar();
		}
	}

	//First, we calculate the LCS using case sensitive. the longest LCS is |Y| then we check the upper char count in X.
	for (int r = 1; r <= n; ++r)
	{
		for (int c = 1; c <= m; ++c)
		{
			int i = r - 1;
			int j = c - 1;
			if (strx[i] == stry[j])
			{
				LCS[r][c] = LCS[r - 1][c - 1] + 1;
				ELCS[r][c].op = REL_EQUAL;
				ELCS[r][c].i = r;
				ELCS[r][c].j = c;
				ELCS[r][c].pi = i;
				ELCS[r][c].pj = j;
				
			}
			else
			{
				ELCS[r][c].op 	= REL_INEQUAL;
				ELCS[r][c].i 	= r;
				ELCS[r][c].j 	= c;
				ELCS[r][c].pi 	= r-1;
				ELCS[r][c].pj 	= c;

				LCS[r][c] = LCS[r - 1][c];
				
				if (LCS[r][c]<LCS[r][c - 1])
				{
					LCS[r][c] = LCS[r][c - 1];
					ELCS[r][c].pi 	= r;
					ELCS[r][c].pj 	= c-1;
				}
			}
		}
	}


	int i = n;
	int j = m;
	stack<commchar> sLCS;
	vector<commchar> vLCS;
    while(i>=0 && j>=0)
	{
		int a = ELCS[i][j].pi;
		int b = ELCS[i][j].pj;
		if(REL_EQUAL == ELCS[i][j].op)
		{	
			sLCS.push(ELCS[i][j]);
		}

		i = a;
		j = b;
	}


	while(!sLCS.empty())
	{
		vLCS.push_back(sLCS.top());
		sLCS.pop();
	}

	commchar s;
	s.i = s.j = 1;

	for(int i = 0; i<vLCS.size(); ++i)
	{
		if(s.j != vLCS[i].j) //Find the miss segment.
		{
			const char* a = strx+s.i-1;
			const char* b = stry+s.j-1;
			int an = vLCS[i].i-s.i;
			int bm = vLCS[i].j-s.j;
			if(!CalcLCSWithCaseInSensitive(a,b,an,bm))
			{
				cout<<"No"<<endl;
				break;
			}
			s.i = vLCS[i].i+1;
			s.j = vLCS[i].j+1;
		}
		s.i = vLCS[i].i+1;
		s.j = vLCS[i].j+1;
	}




	for(int i = 0; i< vLCS.size(); ++i)
	{
		cout<<stry[vLCS[i].j-1]<<" "<<vLCS[i].j-1<<endl;
	}
	cout<<endl;


	return 0;
}



int main()
{
	int t;
	int n = 0;
	int m = 0;
	char szX[102] = { 0 };
	char szY[102] = { 0 };

	cin >> t;

	while (t>0)
	{
		--t;
		cin >> n >> m;
		cin >> szX >> szY;

		StringConversion(szX, szY, n, m);
	}


	return 0;
}

/*
28 17
abAcjcvxhbdDMKLFNvxfhvndKSFL ABACJDMKLFNNDKSFL
*/