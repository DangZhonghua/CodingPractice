/*
295. Find Median from Data Stream
https://leetcode-cn.com/problems/find-median-from-data-stream/

Median is the middle value in an ordered integer list. If the size of the list is even, 
there is no middle value. So the median is the mean of the two middle value.
For example, 
[2,3,4], the median is 3
[2,3], the median is (2 + 3) / 2 = 2.5
Design a data structure that supports the following two operations:
void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 
Example:
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 
Follow up:
If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?

*/

#include<queue>
#include<iostream>
#include<vector>
using namespace std;

class MedianFinder 
{
public:
    /** initialize your data structure here. */
    MedianFinder() 
    {
        m_nCount = 0;
    }
    
    void addNum(int num) 
    {
        ++m_nCount;
        if(m_nCount&1)
        {
          if(maxHeap.empty())
          {
              maxHeap.push(num);
          }   
          else
          {
              if( !minHeap.empty() && num > minHeap.top() )
              {
                  int t = minHeap.top();
                  minHeap.pop();
                  minHeap.push(num);
                  num = t;
              }
              maxHeap.push(num);
          }
        }
        else
        {
            if(num < maxHeap.top())
            {
                int t = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(num);
                num = t;
            }
            minHeap.push(num);
        }
    }
    
    double findMedian() 
    {
        double m = 0;
        if(m_nCount)
        {
            if(m_nCount%2)
            {
                m = maxHeap.top();
            }
            else
            {
                 m = maxHeap.top();
                m += minHeap.top();
                m /=2;
            }
        }
        return m;
    }
private:
    priority_queue<int, vector<int>, greater<int> > minHeap; // use to store right part
    priority_queue<int, vector<int>, less<int>    > maxHeap; // use to store left part
    int m_nCount{0};
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
