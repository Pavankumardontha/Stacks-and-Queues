
vector<int> nextGreaterElementToRight(vector<int>& temp)
{
    // ngr[i]=n if there is no element to the right which is greater than the element at index i
    int n = temp.size();
    int i = n-1;
    stack<int> s;
    vector<int> ngr(n,n);
    for(int i=n-1;i>=0;i--)
    {
        if(s.empty())
        s.push(i);
        else
        {
            if(temp[i]<temp[s.top()])
            ngr[i]=s.top();
            else
            {
                while(!s.empty() and temp[i]>=temp[s.top()])
                s.pop();
                if(!s.empty())
                ngr[i]=s.top();
            }
            s.push(i);
        }
    }
    return ngr;
}
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) 
    {
        // finding the next greater element to the right
        int n = temp.size();
        vector<int> ngr = nextGreaterElementToRight(temp);
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            if(ngr[i]!=n)
            ans[i]=ngr[i]-i;
        }
        return ans;
    }
};
