/*
Sick Pasha 
https://practice.geeksforgeeks.org/problems/sick-pasha/0/?ref=self

Pasha has been very sick. His platelets went way down. Being a paranoid person, he consulted N doctors about the optimal range in which Platelet Count should lie. The i-th doctor suggested that the Platelet count should be between li and ri, inclusive, to be called normal.
Now, Pasha thinks that a Platelet count is Safe to have if at least Z Doctors recommend it. Pasha now asks Q Queries. In each query- he will give an integer P (the platelet count). Pasha wants to know if the entered Platelet count is safe to have or not.

Input:
The first line contains T-denoting the number of test cases.
The first line of each test case contains an integer N -(Number of Doctors).
The next N Lines each contains two integers li and ri.
The next Line contains two integers -  Z(Number of doctors that should recommend that platelets count is safe; at least) and Q(Number of queries being asked)
The next Q lines each contains an integer P. 
Output:
For each test case-Output -"Yes", if its safe to have, else "No".

Constraints:
1<=T<=100
1<=N,Q<=2e5
1<=Z<=N
1<=Li<=Ri<=2e5
1<=P<=2e5

Explanation:
Sample Input:
1
5
1 10
5 10
7 12
15 25
20 25
3 4
7
5
10
16

Sample Output:
Yes
No
Yes
No
Explanation:
The first query : 7 is in [1,10] , [5,10] , [7,12]- So recommended by 3 Doctors-YES
The second query: 5 is in [1,10] , [5,10] - recommended by 2 doctors- "No"
The third query: 10 is in [1,10] , [5,10] , [7,12] recommended by 3 doctors- "Yes"
The Fourth query: 16 is in [15,25] recommended by 1 doctors- "No"


*/