#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    queue<int> q;
    stack<int> s;
    for(int i=1;i<=10;i++)
    q.push(i);
    // q = 1,2,3,4,5,6,7,8,9,10 s = 
    
    int n = q.size();
    
    // step-1: push n/2 elements into the stack 
    for(int i=0;i<n/2;i++)
    {
        s.push(q.front());
        q.pop();
    }
    // q = (front)6,7,8,9,10 s = (top)5,4,3,2,1
    
    // step-2 : push back all elements in stack back to queue 
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    // q = 6,7,8,9,10,5,4,3,2,1 s = {}
    
    // step-3 dequeue the first half of the elements from queue and enqueue them back into the queue
    for(int i=0;i<n/2;i++)
    {
        q.push(q.front());
        q.pop();
    }
    // q = 5,4,3,2,1,6,7,8,9,10 s = {}
    
    // step-4 push n/2 elements into the stack
    for(int i=0;i<n/2;i++)
    {
        s.push(q.front());
        q.pop();
    }
    // q = 6,7,8,9,10 s = 1,2,3,4,5 see the order of elements
    
    //step-5 obtain the interleaving order
    while(!s.empty())
    {
        q.push(s.top()); 
        s.pop();
        q.push(q.front()); // push the first element of queue into queue 
        q.pop(); // pop the front element 
    }
    // q = 1,6,2,7,3,8,4,9,5,10 
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
