class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        /*
        a = [1,2,1]
        since its circular we can consider it will have a size of 2*n
        [1,2,1][1,2,1]
        [0,1,2][3,4,5]
        and the index will vary from 0 to 2*n-1
        and then apply the nearest greater element to the right logic
        */
        int n = nums.size();
        vector<int> ans(n,-1);
        int i = 0;
        int ind;
        stack<int> s;
        while(i<2*n)
        {
            ind = i%n;
            while(!s.empty() and nums[ind]>nums[s.top()])
            {
                ans[s.top()]=nums[ind];
                s.pop();
            }
            s.push(ind);
            i++;
        }
        return ans;
    }
};
