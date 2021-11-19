#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    queue<int> q1;
    for(int i=1;i<=10;i++)
    q1.push(i);
    //present queue :- 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    //output queue :- 1 , 6 , 2 , 7 , 3 , 8 , 4 , 9 , 5 , 10 
    // lets say we have one stack s1 and given queue q1 
    stack<int> s1;
    
    // push first n/2 elements of q1 into s1 
    for(int i=0;i<5;i++)
    {
        s1.push(q1.front());
        q1.pop();
    }
    // s1 :- 5 , 4 , 3 , 2 , 1  q1 :- 6, 7, 8, 9, 10 
    
    // push elements of s1 into q1 
    while(!s1.empty())
    {
        q1.push(s1.top());
        s1.pop();
    }
    // s1 :-  q1 :- 6,7,8,9,10,5,4,3,2,1 
    
    //push first n/2 elements of q1 into s1 again 
    for(int i=0;i<5;i++)
    {
        s1.push(q1.front());
        q1.pop();
    }
    //s1 :- 10,9,8,7,6 q1:- 5, 4, 3, 2, 1,
    
    // push elements of s1 into q1 
    while(!s1.empty())
    {
        q1.push(s1.top());
        s1.pop();
    }
    // s1 :-  q1 :- 5,4,3,2,1,10,9,8,7,6 
    
    //push all elements of q1 into s1 
    for(int i=0;i<10;i++)
    {
        s1.push(q1.front());
        q1.pop();
    }
    //s1 :- 6,7,8,9,10,1,2,3,4,5  q1:-
    
    // push n/2 elements from stack to q 
    for(int i=0;i<5;i++)
    {
        q1.push(s1.top());
        s1.pop();
    }
    //s1 :- 1,2,3,4,5  q1 :- 6,7,8,9,10 
    
    while(!s1.empty())
    {
        //pop top element of stack 
        int k = s1.top();
        s1.pop();
        //push top element of stack into q 
        q1.push(k);
        //push front element of queue to the back and pop it from the front.
        q1.push(q1.front());
        q1.pop();
    }
    
    //printing queue
    while(!q1.empty())
    {
        cout<<q1.front()<<" ";
        q1.pop();
    }
}
