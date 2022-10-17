#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 
/*
Here we use two stacks(s1 and s2) to find the largest element present in the stack on O(1). We have 3 operations 
1) push x : we push into s1. To push x into s2 we have 2 conditions.We compare x with the top element of the stack s2. 
  a) If top element of s2 is less than or equal to x then we push x into the stack s2.
  b) If top element of s2 is greater tha n x we do not push x into the stack s2. 

2) remove : We pop from s1. To pop from s2 we will have 2 conditions. Let the element popped from s1 be x. 
  a) If x is equal to top element of s2 then we pop also from s2.
  b) If x is not equal to top element of s2 then we do not pop from s2. 
  
3) Find max : Top element of s2 will always be the largest of all the elements present in the current configuration of stack s1.

*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int m = 1;
    while(t--)
    {
        cout<<"Case "<<m<<":"<<endl;
        int n;
        cin>>n;
        char c;
        int k;
        stack<int> s1,s2;
        for(int i=0;i<n;i++)
        {
            cin>>c;
            if(c=='A')
            {
                // insert
                cin>>k;
                s1.push(k);
                if(s2.empty())
                s2.push(k);
                else
                {
                    if(s2.top()<=k)
                    s2.push(k);
                }
            }
            else if(c=='R')
            {
                //remove
                if(!s1.empty())
                {
                    int temp = s1.top();
                    s1.pop();
                    if(temp==s2.top())
                    s2.pop();
                }
            }
            else
            {
                // find largest element
                if(s1.empty())
                cout<<"Empty"<<endl;
                else
                cout<<s2.top()<<endl;
                
            }
        }
        
        m++;
    }
    return 0;
} 
