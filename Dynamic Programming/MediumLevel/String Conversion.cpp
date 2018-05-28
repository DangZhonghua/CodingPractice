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



#include<iostream>
#include<string>
#include<unordered_set>
#include<stack>
#include<vector>
using namespace std;




int StringConversionLCS(const char* strx, const char* stry, int n, int m)
{
	int sc[102][102];

	for(int r = 0; r<=n; ++r)
	{
		for(int c = 0; c<=m; ++c)
		{
			sc[r][c] = 0;
			if(0 == c && r<n && 'a'<=strx[r] && 'z'>=strx[r])
			{
				sc[r][c] = 1;
			}		
		}
	}		
	sc[0][0] = 1;

	for(int r = 1; r<=n; ++r)
	{
		for(int c = 1; c<=m; ++c)
		{
			int i = r-1;
			int j = c-1;
			if(strx[i] == stry[j] || strx[i]-32 == stry[j])
			{
				sc[r][c] = sc[r-1][c-1];
			}
			else
			{
				if('a'<=strx[i] && 'z'>= strx[i])
				{
					sc[r][c] = sc[r-1][c];
				}
			}
		}
	}

	if(sc[n][m])
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}

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

		StringConversionLCS(szX, szY, n, m);
	}

	return 0;
}

/*
1
28 17
abAcjcvxhbdDMKLFNvxfhvndKSFL ABACJDMKLFNNDKSFL

2
5 3
daBcd ABC 
4 3
ABcd BCD 

//no
20 13
ejBchGhhEjhhHGhahjgb BFAFGHDBGHGCC

//yes
1
29 11
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
A b c D D e f g H i  l  k  l  M  N  n  o  p  q  r  s  t  v  u  w  X  X  y  z 

1 2 3 4 5 6 7 8 9 10 11
A B C D D H M N X X  Z

*/