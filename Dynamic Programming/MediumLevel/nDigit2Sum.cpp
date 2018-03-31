//https://practice.geeksforgeeks.org/problems/count-of-n-digit-numbers-whose-sum-of-digits-equals-to-given-sum/0


#include<iostream>
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

int main()
{
  int t = 0;
  int sum = 0;
  int n = 0;
 

  cin>>t;

  while(t--)
  {
    cin>>n>>sum;
    CalcNoOfNDigitOfSum(n,sum);
  }

}