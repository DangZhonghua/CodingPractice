/*
Sum of elements of all partitions of number such that no element is less than K
https://www.geeksforgeeks.org/sum-of-elements-of-all-partitions-of-number-such-that-no-element-is-less-than-k/

Given an integer N, the task is to find an aggregate sum of all integer partitions of this number 
such that each partition does not contain any integer less than K.

Examples:

    Input: N = 6 and K = 2
    Output: 24
    In this case, there are 4 valid partitions.
    1) {6}
    2) {4, 2}
    3) {3, 3}
    4) {2, 2, 2}
    Therefore, aggregate sum would be
    6 + 4 + 2 + 3 + 3 + 2 + 2 + 2 = 24

    Input: N = 10 and K = 3
    Output: 50
    Here, 5 valid partitions are:
    1) {10}
    2) {7, 3}
    3) {6, 4}
    4) {5, 5}
    5) {3, 3, 4}
    Aggregate sum in this case would be
    10 + 7 + 3 + 6 + 4 + 5 + 5 + 3 + 3 + 4 = 50

*/

/*
This is actual count ways of combination which fill the number.
This is the complete knapsack problem.

*/



#include<iostream>
#include<vector>
using namespace std;

int SumOfPartition(int N, int K)
{


    return 0;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
