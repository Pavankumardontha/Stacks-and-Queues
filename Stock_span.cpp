class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<int> s;
       vector<int> span(n);
       span[0]=1;
       s.push(0);
       for(int i=1;i<n;i++)
       {
           if(price[i]<price[s.top()])
               span[i]=1;
           else
            {
                while(!s.empty() and price[i]>=price[s.top()])
                s.pop();
                if(!s.empty())
                span[i]=i-s.top();
                else
                span[i]=i+1;
            }
           s.push(i);
       }
       return span;
    }
};
