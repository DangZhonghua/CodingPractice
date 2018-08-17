/*
Nuts and Bolts Problem 
https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem/0

Given a set of N nuts of different sizes and N bolts of different sizes. 
There is a one-one mapping between nuts and bolts. Match nuts and bolts efficiently.

Comparison of a nut to another nut or a bolt to another bolt is not allowed. 
It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.

Input:

The first line contains 'T' denoting the number of testcases. Then follows description of T testcases:
Each case begins with a single positive integer N denoting the number of nuts/bolts.

Then follows the array of nuts, each element separated by a space.

And finally the bolts array, again, each element is separated by a space here.

Array of Nuts/Bolts can only consist of the following elements:

{'@', '#', '$', '%', '^', '&', '~', '*', '!'}

And no element can be repeated.


Output:

For each test case, output the matched array of nuts and bolts in separate lines, 
where each element in the array is separated by a space. 
Print the elements in the following order ! # $ % & * @ ^ ~ 


Constraints:

1<= T <= 70
1<= N <= 9


Example:

Input:

2
5
@ % $ # ^
% @ # $ ^
9
^ & % @ # * $ ~ !
~ # @ % & * $ ^ ! 

Output:

# $ % @ ^
# $ % @ ^
! # $ % & * @ ^ ~
​! # $ % & * @ ^ ~

*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


int SortNutsBolts(const vector<char>& vn, const vector<char>& vb)
{
   // unordered_map<char,int> mdict{{'!',0}, {'#',1}, {'$',2}, {'%',3}, {'&',4}, {'*',5},{'@',6}, {'^',7}, {'~',8} };
    vector<char> vdict{'!','#','$', '%','&','*','@','^', '~'};
    unordered_map<char, int > chmapCount;
    vector<char> vo;

    for(auto c:vn)
    {
        if(chmapCount.find(c) == chmapCount.end())
        {
            chmapCount[c] = 1;
        }
    }
    for(auto c:vb)
    {
        auto it = chmapCount.find(c);
        if(it != chmapCount.end())
        {
            it->second += 1;
        }
    }
    for(auto c:vdict)
    {
        auto it = chmapCount.find(c);
        if(chmapCount.end() != it && it->second>=2)
        {
            vo.push_back(c);
        }
    }

    //output
    for(auto c:vo)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    for(auto c:vo)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    
    return 0;
}

int main(int argc, char const *argv[])
{
    int t= 0;
    int N = 0;

    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int i = 0;
        vector<char> vn(N,0);
        vector<char> vb(N,0);
        
        while(i<N)
        {
            char c;
            cin>>c;
            vn[i++] = c;
        }
        i = 0;
        while(i<N)
        {
            char c;
            cin>>c;
            vb[i++] = c;
        }
        
        SortNutsBolts(vn,vb);
    }
    
    return 0;
}


