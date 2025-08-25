vector<int> nearestSmallerElementToLeft(vector<int>& heights)
{
    int n = heights.size();
    vector<int> nsl(n,-1);
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(s.empty())
        {
            nsl[i]=-1;
            s.push(i);
            continue;
        }
        if(heights[i]>heights[s.top()])
        {
            nsl[i]=s.top();
            s.push(i);
        }
        else
        {
            while(!s.empty() and heights[i]<=heights[s.top()])
            {
                s.pop();
            }
            if(s.empty())
            nsl[i]=-1;
            else
            nsl[i]=s.top();
            s.push(i);
        }
    }
    return nsl;
}



vector<int> nearestSmallerElementToRight(vector<int>& heights)
{
    // if there is no smaller element to the right for element at index i, we fill it as n where n is the size of the array
    int n = heights.size();
    vector<int> nsr(n,n);
    stack<int> s;
    for(int i=n-1;i>=0;i--)
    {
        if(s.empty())
        {
            s.push(i);
            nsr[i]=n;
            continue;
        }
        if(heights[i]>heights[s.top()])
        {
            nsr[i]=s.top();
            s.push(i);
        }
        else
        {
            while(!s.empty() and heights[i]<=heights[s.top()])
            s.pop();
            if(s.empty())
            nsr[i]=n;
            else
            nsr[i]=s.top();
            s.push(i);
        }
    }
    return nsr;
}

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        /*
        Lets say we want to find the maximum rectangle area that can be formed taking element at index i.
        In a histogram, height[i] is the bar height at position i. So, height[i] defines the maximum height of 
        the rectangle that includes index i. We want to now maximize the width. 
        Now we ask: “How far can we expand left and right while keeping all bars at least as tall as height[i]?”
        NSL[i] (Nearest Smaller to Left) tells us where the first bar shorter than height[i] is, so the 
        rectangle can expand left until just after that.
        NSR[i] (Nearest Smaller to Right) tells us where the first bar shorter than height[i] is, so the rectangle 
        can expand right until just before that.
        So maximum rectangle’s width is: (NSR[𝑖]−NSL[𝑖]−1)
        So the maximum possible rectangle area formed including the ith index = heights[i] * (NSR[i]-NSL[i]-1)
        We will find this for each index and take the maximum of all to get the answer
        */
        int n = heights.size();
        vector<int> nsr = nearestSmallerElementToRight(heights);
        vector<int> nsl = nearestSmallerElementToLeft(heights);
        int max_area = 0;
        int current_area=0; // maximum area formed by taking ith histogram 
        for(int i=0;i<n;i++)
        {
            current_area = heights[i]*(nsr[i]-nsl[i]-1);
            max_area = max(max_area,current_area);
        }
        return max_area;
        
    }
};
