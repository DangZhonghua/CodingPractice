/*
https://www.geeksforgeeks.org/minimum-number-of-given-operations-required-to-make-two-strings-equal/
Minimum number of given operations required to make two strings equal

Given two strings A and B, both strings contain characters a and b and are of equal lengths. 
There is one _ (empty space) in both the strings. The task is to convert 
first string into second string by doing the minimum number of the following operations:

    If _ is at position i then _ can be swapped with a character at position i+1 or i-1.
    If characters at positions i+1 and i+2 are different then _ can be swapped with a character at position i+1 or i+2.
    Similarly, if characters at positions i-1 and i-2 are different then _ can be swapped with a character at position i-1 or i-2.

Examples:

    Input: A = “aba_a”, B = “_baaa”
    Output: 2
    Move 1 : A = “ab_aa” (Swapped A[2] with A[3])
    Move 2 : A = “_baaa” (Swapped A[0] with A[2])

    Input: A = “a_b”, B = “ab_”
    Output: 1 

*/