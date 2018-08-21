/*
https://www.geeksforgeeks.org/duplicates-array-using-o1-extra-space-set-3/
Find duplicate in an array in O(n) and by using O(1) extra space

Given an array arr[] containing n + 1 integers where each integer is between 1 and n (inclusive). 
There is only one duplicate element, find the duplicate element in O(n) time complexity and O(1) space.

Examples :

Input  : arr[] = {1, 4, 3, 4, 2} 
Output : 4

Input  : arr[] = {1, 3, 2, 1}
Output : 1

Recommended: Please try your approach on {IDE} first, before moving on to the solution.

Approach :
Firstly, the constraints of this problem imply that a cycle must exist. 
Because each number in an array arr[] is between 1 and n, 
it will necessarily point to an index that exists. 
Therefore, the list can be traversed infinitely, 
which implies that there is a cycle. 
Additionally, because 0 cannot appear as a value in an array arr[], arr[0] 
cannot be part of the cycle. Therefore, traversing the array in this manner from arr[0] 
is equivalent to traversing a cyclic linked list. The problem can be solved just like linked list cycle.

*/