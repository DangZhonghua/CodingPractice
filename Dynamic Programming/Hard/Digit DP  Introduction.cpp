/*

Digit DP | Introduction

Prerequisite : How to solve a Dynamic Programming Problem ?

There are many types of problems that ask to count the number of integers ‘x‘ between two integers say ‘a‘ and ‘b‘ such that x satisfies a specific property that can be related to its digits.

So, if we say G(x) tells the number of such integers between 1 to x (inclusively), then the number of such integers between a and b can be given by G(b) – G(a-1). This is when Digit DP (Dynamic Programming) comes into action. All such integer counting problems that satisfy the above property can be solved by digit DP approach.

Key Concept

    Let given number x has n digits. The main idea of digit DP is to first represent the digits as 
    an array of digits t[]. Let’s say a we have tntn-1tn-2 … t2t1 as the decimal 
    representation where ti (0 < i <= n) tells the i-th digit from the right. 
    The leftmost digit tn is the most significant digit.
    Now, after representing the given number this way we generate the numbers 
    less than the given number and simultaneously calculate using DP, 
    if the number satisfy the given property. We start generating integers 
    having number of digits = 1 and then till number of digits = n. 
    Integers having less number of digits than n can be analyzed by setting the leftmost digits to be zero.


*/