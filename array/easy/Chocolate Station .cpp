/*
Chocolate Station 
https://practice.geeksforgeeks.org/problems/chocolate-station/0
https://www.geeksforgeeks.org/minimum-total-cost-incurred-to-reach-the-last-station/


Geek has an array Arr, where Arr[i] (1-based indexing) denotes 
the number of chocolates corresponding to each station. 
When he move from station i to station i+1 he get A[i] – A[i+1] chocolates for free, 
if this number is negative, he looses that many chocolates also.
He can only move from station i to station i+1, if he has non-negative number of chocolates with him.
Given the cost of one chocolate is Rs. P, help geek to find the minimum cost incurred in reaching 
last station from the first station (station 1).
Note: Initially Geek has 0 chocolate.

Input:
The first line of the input contains an integer T, denoting the number of Test cases. 
Then T test case follows. The first line of each test case contains an integer N, 
denoting the total number of stations. Then next line contains N space 
separated integers denoting the elements of the array. 
The next line contains an integer P denoting the cost of a chocolate.

Output:
For each test case output a single line containing an integer 
denoting the total minimum cost ncurred in reaching last station from the first station.

Constraints:
1<=T<=103
1<=N<=105
0<=A[i]<=105
0<=P<=100

Example:
Input:
2
3
1 2 3
10
6
10 6 11 4 7 1
5
Output:
30
55
Explanation:
Test Case 1:
To reach the first station from the starting point, we need to buy 1 chocolate,
To reach station 2 form station 1, we get A[1] – A[2] = -1 chocolates i.e. we lose 1 chocolate. Hence, we need to buy 1 chocolate.
Similarly, we need to buy 1 chocolate to reach station 3 from station 2.
   Hence, total cost incurred = (1+1+1)*10 = 30

Test Case 2:

To reach to the first station from starting point he need to buy 10 chocolates. 

Chocolates Bought = 10 ,  Chocolates balance = 0

On reaching second station he will get (10-6)= 4 chocolates.

Chocolates Bought= 10 , Chocolates balance = 4.

To reach to 3 station , he has to buy (6- 11) = 5 chocolates. But he has 4 chocolates as balance So the chocolates he need to buy is (5 -4 ) =1;

Chocolates Bought= 11 , Chocolates balance = 0.

On reaching station 4 , he will get (11 - 4)= 7 chocolates.

Chocolates Bought= 11 , Chocolates balance = 7.

To reach to 5 station , he has to buy (4- 7) = 3 chocolates. But he has 7 chocolates as balance .

Chocolates Bought= 11 , Chocolates balance = 4.

To reach to 6 station , he will get (7- 1) = 6 chocolates. 

Chocolates Bought= 11 , Chocolates balance = 10.

Therefore , total chocolates he has to buy  is 11.

Hence, Amount=11*5=55.


*/

#include<vector>
#include<iostream>

using namespace std;

int minimumCost2ReachEnd(vector<int>& a, int P)
{
   int ret = 0;
   int balance = 0;
   int bc = 0; // buying count

   for(int i = 0; i<a.size()-1; ++i)
   {
      if( a[i]+balance < a[i+1] )
      {
         bc += (a[i+1]-a[i]-balance);
         balance = 0;
      }
      else
      {
         balance = ((a[i]+balance)-a[i+1]);
      }
   }

   cout<< bc*P<<endl;

   return 0;
}

int main()
{
   int t = 0;
   cin>>t;

   while(t--)
   {
      int N = 0;
      int P = 0;
      cin>>N;
      vector<int> a(N+1,0);
      int i = 1;
      while(i<=N)
      {
         cin>>a[i];
         ++i;
      }
      cin>>P;
      minimumCost2ReachEnd(a,P);
   }
   return 0;
}
