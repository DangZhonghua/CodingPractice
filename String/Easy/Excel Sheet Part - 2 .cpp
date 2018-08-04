/*
Excel Sheet | Part - 2 
https://practice.geeksforgeeks.org/problems/excel-sheet-part-2/0
https://www.geeksforgeeks.org/find-excel-column-number-column-title/


Find Excel column number from column title

We have discussed Conversion from column number to Excel Column name. In this post, reverse is discussed.

Given a column title as appears in an Excel sheet, return its corresponding column number.

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

Examples:

Input : A
Output : 1

Input : AA
Output : 27


*/

/*
26 进制

*/

#include<iostream>
#include<string>
using namespace std;

int ColumnName2Number(const string& strc)
{
    long long num = 0;
    int  base = 1;
    
    for(int i =strc.length()-1; i>=0; --i)
    {
        num += base*(strc[i]-'A' + 1);
        base *=26;
    }
    cout<<num<<endl;

    return;
}


int main()
{
    int t = 0;
    
    cin>>t;

    while(t--)
    {
        string strc;
        cin>>strc;
        ColumnName2Number(strc);
    }

    return 0;
}