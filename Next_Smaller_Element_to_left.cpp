// Smallest number on left (gfg)

class Solution{
public:
    vector<int> leftSmaller(int n, int a[])
    {
        vector<int> ans;
        ans.push_back(-1);
        stack<int> s;
        s.push(a[0]);
        for(int i=1;i<n;i++)
        {
            // pop elements from stack till we find an element in stack which is lesser than our current element 
            while(!s.empty() and s.top()>=a[i])
            s.pop();
            
            if(s.empty())
            ans.push_back(-1);
            else
            ans.push_back(s.top());
            s.push(a[i]);
        }
        return ans;
    }
};
