class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> span(n);
       stack<int> s;
       s.push(0);
       span[0]=1;
       for(int i=1;i<n;i++)
       {
           /*
           we have 2 choices , our current element can be 
           1) greater than the topmost index element of the stack :- In this case we remove elements from stack till we get the element larger than current element.
           Here by doing this we can encounter 2 things 
           a) the stack might become empty : In this case we know that span is current_index + 1 
           b) the stakc might not become empty and element present in the stack top index is greater than our current element : In this case the span is current_index - s.top() 
           2) smaller than the topmost index element of the stack :- In this case , we just push the current element index into stack with span 1
           */
           if(price[i]<price[s.top()])
           span[i] = 1;
           else
           {
               while(!s.empty() and price[i]>=price[s.top()])
               s.pop();
               if(s.empty())
               span[i]=i+1;
               else
               span[i]=i-s.top();
           }
           s.push(i);
       }
       return span;
    }
};


