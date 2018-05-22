/*
Pass the semester
https://practice.geeksforgeeks.org/problems/pass-the-semester/0

Satish wants to prepare for tommorow's exam . He knows the distribution of marks for 
the subject along with time to learn the concepts.
You are given remaining time for the exam along with marks for each topic and passing marks for the subject.
Find the max marks Satish can attain by studing max no of topic in max no hours not excedding (p) .

Input:

The first line of input contains the number of testcases t.
The first line of each testcase contains the no of topics(n) , time remaining for exam(h) in hour and passing marks(p).
Each 'n' lines contain u(time to learn topic) and v(weightage of topic in exam) .

Output:

For each test case print "YES" along with time taken or "NO".  


Constraints:

1<=t<=100

1<=n<=300

1<=h<=150

1<=p<=35

1<=u,v<=25


Example:
Sample Input 0
1
5 40 21 
12 10 
16 10 
20 10 
24 10 
8 3 


Sample Output 0 
YES 36

Explaination :

Marks needed to pass the subject  10 +10 + 3 = 23

Time taken to achieve the 23 marks : 12 + 6 + 8 =36


*/