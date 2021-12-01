#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++)
    cin>>a[i];
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(s.empty())
        s.push(i);
        else
        {
            if(a[s.top()]<a[i])
            s.push(i);
            else
            {
                while(!s.empty())
                {
                    if(a[s.top()]>a[i])
                    {
                        ans[s.top()]=a[i];
                        s.pop();
                    }
                    else
                    break;
                }
                s.push(i);
            }
        }
    }
    for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";
    cout<<endl;
}
