/*
Multiply two polynomals 
https://practice.geeksforgeeks.org/problems/multiply-two-polynomals/0/?ref=self

Given two polynomials represented by two arrays that contains the coefficients of poynomials, print the polynomial in form of array formed after multiplication of given polynomials.

Input:

The first line contains an integer T, depicting total number of test cases. 
First line of each test case contains two integers M and N ,highest degree of the polynomial arr1 and arr2.

Next two line contains M and N integers , decribes the coefficients of polynomials

Output:

Print the coefficients of resultant poynomial.

Constraints:

1<=T<=100
1<=M,N<=100
1<=arr1[i],arr2[i]<=100

Example:

Input:

2
4 3
1 0 3 2
2 0 4
5 4
1 9 3 4 7
4 0 2 5

Output:

2 0 10 4 12 8
4 36 14 39 79 23 34 35

Explanation:
First case:

First polynomial: 
1 + 0x^1 + 3x^2 + 2x^3
Second polynomial: 
2 + 0x^1 + 4x^2
Product polynomial:
2 + 0x^1 + 10x^2 + 4x^3 + 12x^4 + 8x^5

Second case:
First polynomial:
1 + 9x^1 + 3x^2 + 4x^3 + 7x^4
Second polynomial: 
4 + 0x^1 + 2x^2 + 5x^3
Product polynomial: 
4 + 36x^1 + 14x^2 + 39x^3 + 79x^4 + 23x^5 + 34x^6 + 35x^7


*/