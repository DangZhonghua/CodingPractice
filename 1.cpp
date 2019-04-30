#include<queue>
using namespace std;

class MyStack 
{
public:
    /** Initialize your data structure here. */
    MyStack() 
    {
        m_pInputQ = &m_Q1;
        m_pCacheQ = &m_Q2;
    }
    
    /** Push element x onto stack. */
    void push(int x) 
    {
        m_pInputQ->push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        while(m_pInputQ->size()>1)
        {
            m_pCacheQ->push(m_pInputQ->front());
            m_pInputQ->pop();
        }
        int t =  m_pInputQ->front();
        m_pInputQ->pop();
        
        queue<int>* tp = m_pInputQ;
        m_pInputQ = m_pCacheQ;
        m_pCacheQ = m_pInputQ;
        return t;
    }
    
    /** Get the top element. */
    int top() 
    {
        return m_pInputQ->back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        return m_pInputQ->empty();
    }
private:
    queue<int> m_Q1;
    queue<int> m_Q2;
    queue<int>* m_pInputQ{nullptr};
    queue<int>* m_pCacheQ{nullptr};

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */


class MyStack 
{
public:
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) 
    {
        q2.push(x);
        while (q2.size() > 1) {
            q1.push(q2.front()); q2.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        int x = top(); q2.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() 
    {
        if (q2.empty()) 
        {
            for (int i = 0; i < (int)q1.size() - 1; ++i) 
            {
                q1.push(q1.front()); q1.pop();
            }
            q2.push(q1.front()); q1.pop();
        }
        return q2.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
    
private:
    queue<int> q1, q2;
};