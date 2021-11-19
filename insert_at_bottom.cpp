#include<bits/stdc++.h>
#include<iostream>
using namespace std;

stack<int> s;
void insert_at_bottom(int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    else
    {
        int k = s.top();
        s.pop();
        insert_at_bottom(x);
        s.push(k);
        return;
    }
}
int main()
{
    for(int i=1;i<=5;i++)
    s.push(i);
    insert_at_bottom(6);
    
    cout<<"After inserting element 6 at the bottom of the stack :"<<endl;
    while(!s.empty())
    {
        int k = s.top();
        cout<<k<<" ";
    }
    cout<<endl;
}
