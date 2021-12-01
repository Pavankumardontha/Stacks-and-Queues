#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() 
{
	//next greater element to the left
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	cin>>a[i];
	vector<int> ans(n,-1);
	stack<int> s;
	for(int i=n-1;i>=0;i--)
	{
	    if(s.empty())
	    s.push(i);
	    else
	    {
	        if(a[i]<a[s.top()])
	        s.push(i);
	        else
	        {
	            while(!s.empty())
	            {
	                if(a[i]>a[s.top()])
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
	return 0;
}
