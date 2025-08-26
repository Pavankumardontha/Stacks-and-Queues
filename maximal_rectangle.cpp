/* Do first largest rectangle in histogram. */
//int getMaximalRectangle()

vector<int> nearestSmallerElementToLeft(vector<int>& nums)
{
    // if we do not find smaller element to the left ans[i]=-1
    int n = nums.size();
    vector<int> ans(n,-1);
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(!s.empty())
        {
            if(nums[i]>nums[s.top()])
            ans[i] = s.top();
            else
            {
                while(!s.empty() and nums[i]<=nums[s.top()])
                s.pop();
                if(!s.empty())
                ans[i] = s.top();
            }
        }
        s.push(i);
    }
    return ans;
}

vector<int> nearestSmallerElementToRight(vector<int>& nums)
{
    // if we do not find smaller element to the right ans[i]=n
    int n = nums.size();
    vector<int> ans(n,n);
    stack<int> s;
    for(int i=n-1;i>=0;i--)
    {
        if(!s.empty())
        {
            while(!s.empty() and nums[i]<=nums[s.top()])
            s.pop();
            if(!s.empty())
            ans[i]=s.top();
        }
        s.push(i);
    }
    return ans;
}

int maximalRectangleAreaInHistogram(vector<int>& nums)
{
    int n = nums.size();
    vector<int> nsl = nearestSmallerElementToLeft(nums);
    vector<int> nsr = nearestSmallerElementToRight(nums);
    int current_area;
    int max_area=0;
    for(int i =0;i<n;i++)
    {
        current_area = nums[i]*(nsr[i]-nsl[i]-1);
        max_area = max(max_area,current_area);
    }
    return max_area;
}

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        /*
        Imagine we have our heights array. Each row will represent a 
        seperate height array. We need to find the largest rectangle area
        possible by taking each height configuration (each row). So we consider
        each row values as heights and then calculate the area of the largest 
        rectangle formed in the histogram.

        Lets say the given matrix is as follows
        1 0 1 0 0 
        1 0 1 1 1
        1 1 1 1 1
        1 0 0 1 0

        we will first transform this into height array by adding up all the ones
        above the level till we get any zero.
        heights[i][j] = hieghts[i-1][j] + heights[i-2][j] + . . . heights[0][j]
        But we stop the summation at a point where we get 0. So the height array
        for the above matrix is

        1 0 1 0 0
        2 0 2 1 1
        3 1 3 2 2
        4 0 0 3 0

        For each row , we find the largest possible rectangle area in that histogram.
        We find the maximum of all the areas obtained from all the rows.
        */
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> heights(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0)
                {
                    if(matrix[i][j]=='1')
                    heights[i][j]=1;
                }
                else
                {
                    if(matrix[i][j]=='1')
                    heights[i][j] = 1 + heights[i-1][j];
                }
            }
        }
        int max_area = 0;
        int current_row_max_area;
        vector<int> nums(m);
        for(int i=0;i<n;i++)
        {
            nums = heights[i];
            current_row_max_area = maximalRectangleAreaInHistogram(nums);
            max_area = max(max_area,current_row_max_area);
        }
        return max_area;
    }
};
