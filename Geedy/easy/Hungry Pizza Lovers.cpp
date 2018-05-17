/*
Hungry Pizza Lovers
https://practice.geeksforgeeks.org/problems/hungry-pizza-lovers/0

Dominos Pizza has hungry customers waiting in queue. Each unique order ,i, is placed by a customer at time x[i], and the order takes y[i] units of time to complete.
You have information of all n orders, Find the order in which all customers will receive their pizza and print it. If two or more orders are completed at same time then sort them by non decreasing order number.

Input:
The first line contains a single integer T, denoting the number of testcases.
The first line of each test case contains a single integer n, denoting the total no orders. 
Each of the  subsequent lines contains two space-separated integers describing the respective values of x[i] and y[i] for order i .

Output:
Print n lines containing order numbers describing the sequence in which the customers receive their pizzas. If two or more customers receive their pizzas at the same time, print the smallest order no first.

Constraints:
1<=T<=10
1<=n<=500
1<=i<=n
1<=x[i],y[i]<=10000

Example:
Input:
1
5
4 1
6 2
7 6
8 1
1 3
Output:
5
1
2
4
3



*/