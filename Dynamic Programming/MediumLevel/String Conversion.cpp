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

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int StringConversionLCS(const char *strx, const char *stry, int n, int m)
{
	vector<int> row(n + 2, -1);
	vector< vector<int> > cursc(n + 2, row);
	vector< vector<int> > nextsc(n + 2, row);
	vector< vector<int> >* next = &nextsc;
	vector< vector<int> >* cur = &cursc;
	int 	uc[102];
	uc[0] = 0;

	if ('A' <= strx[0] && 'Z' >= strx[0])
	{
		uc[0] = 1;
	}

	for (int i = 1; i < n; ++i)
	{
		uc[i] = uc[i - 1];
		if ('A' <= strx[i] && 'Z' >= strx[i])
		{
			uc[i] += 1;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (strx[i] == stry[0] || strx[i] - 32 == stry[0])
		{
			cursc[i][0] = i;
		}
	}


	for (int l = 2; l <= m; ++l)
	{
		int j = l - 1;
		for (int x = 0; x < n; ++x)
		{
			int nm = 0;
			(*next)[x][nm] = -1;
			for (int i = 0; i < n; ++i)
			{
				if ((*cur)[x][i] < 0)
				{
					break;
				}
				for (int k = (*cur)[x][i] + 1; k < n; ++k)
				{
					if (strx[k] == stry[j] || strx[k] - 32 == stry[j])
					{
						(*next)[x][nm] = k;
						++nm;
					}
					else if('A'<= strx[k] && 'Z'>=strx[k]) //since upper case can't be delete
					{
						break;
					}
				}
			}
		}
		vector< vector<int> >* temp = next;
		next = cur;
		cur = temp;
	}

	bool bConvert = false;
	for (int i = 0; i < n && !bConvert; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ((*cur)[i][j]<0)
			{
				break;
			}
			else
			{
				if(i-(*cur)[i][j]+1>=m)
				{
					int nUppcase = 0;
					if(i>0)
					{
						nUppcase += uc[i-1];
					}
					int e = (*cur)[i][j];
					if(e<m)
					{
						nUppcase += (uc[m-1]-uc[e]);
					}
					if(nUppcase == 0)
					{
						bConvert = true;
						break;
					}
				}
			}
		}
	}

	if(bConvert)
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

	while (t > 0)
	{
		--t;
		cin >> n >> m;
		cin >> szX >> szY;
		StringConversionLCS(szX, szY, n, m);
	}

	return 0;
}

/*

#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,k,l,m,n,t;
    string x,y;
    cin>>t;
    while(t--){
        cin>>m>>n;
        cin>>x>>y;
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        bool check=true;
        if(check){
            for(i=1;i<=m;i++){
                if(x[i-1]>='A'&&x[i-1]<='Z')check=false;
                dp[i][0]=check;
            }
        }
        dp[0][0]=true;
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                dp[i][j]=dp[i-1][j];
                if(x[i-1]==y[j-1] || x[i-1]-'a'==y[j-1]-'A'){
                    dp[i][j]=dp[i][j]||dp[i-1][j-1];
                }
                if(x[i-1]>='A'&&x[i-1]<='Z'&&x[i-1]!=y[j-1]){
                    dp[i][j]=false;
                }
            }
        }
        cout<<(dp[m][n]?"Yes":"No");
        cout<<endl;
    }
	return 0;
}


*/

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
1
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