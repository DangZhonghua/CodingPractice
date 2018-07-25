/*
Count of n digit numbers whose sum of digits equals to given sum 
https://practice.geeksforgeeks.org/problems/count-of-n-digit-numbers-whose-sum-of-digits-equals-to-given-sum/0/?ref=self
Given two integers ‘n’ and ‘sum’, find count of all n digit numbers with sum of digits as ‘sum’. 
Leading 0’s are not counted as digits. Print your output % 10^9+7.

Input:
The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains 2 integers n and sum.

Output:
Print the number of digits. Print -1 if answer is not possible.

Constraints:
1<=T<=30
1<=n<=100
1<=sum<=1000

Example:
Input:
1
2 2

Output:
2

Explaination:  
2 numbers 11 and 20.

*/


#include<iostream>
#include<vector>
using namespace std;

#define num_mode (1000000007)
#define maxsum  1001
#define maxdigit 101


int CalcNoOfNDigitOfSum(int n, int sum)
{
 unsigned long long M[maxsum][maxdigit];

//Initialize the matrix to zero
  for(int s = 0; s<=sum; ++s)
  {
    for(int d = 0; d<=n; ++d)
    {
      M[s][d] = 0;
    }
  }
  for(int s = 1; s<10; ++s)
  {
    M[s][1] = 1;
  }

 for(int d = 2; d<=n;++d) //Digital num
 {
   for(int s = 1;s<=sum; ++s)
   {
     int v = 0;
     if(d == n)
     {
       v = 1;
     }
     for(v; v<10; ++v)
     {
        if(s>v)
       {
          M[s][d] += ((M[s-v][d-1])%num_mode);
       }
       if(s == v)
       {
           M[s][d] +=1;
       }
     }
     M[s][d] %=num_mode;
   }
 }
if(M[sum][n])
{
   cout<<M[sum][n]<<endl; 
}
else
{
    cout<<-1<<endl;
}

  return 0;
}

/*

ND[s][d+1] += ND[s+x][d]

*/

int CalcNoOfNDigitOfSumV2(int n, int sum)
{
  vector< vector<unsigned long long> > ND(sum+1, vector<unsigned long long>(n+1, 0));

  for(int i = 1; i<10; ++i)
  {
      ND[i][1] = 1;   //ND[1][1] = 1 ND[2][1] = 1 
  }
  
  for(int i = 1; i<n; ++i)
  {
      for(int s = 1; s<=i*9; ++i)
      {
          for(int d = 0; d<10; ++d)
          {
              ND[s+d][i+1] += ND[s][i];
              ND[s+d][i+1] %= num_mode;
          }
      } 
  }
  if(ND[sum][n])
  {
      cout<<ND[sum][n]<<endl;
  }
  else
  {
      cout<<-1<<endl;
  }

    return 0;
}


int main()
{
  int t = 0;
  int sum = 0;
  int n = 0;
 

  cin>>t;

  while(t--)
  {
    cin>>n>>sum;
    //CalcNoOfNDigitOfSum(n,sum);
    CalcNoOfNDigitOfSumV2(n,sum);
  }

}