class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) 
    {
        /*
        Since we want the maximum possible size of the resulting array, it is always 
        preferable to replace smaller subarrays whenever possible — because merging fewer
        elements preserves more of the array.
        But when do we need to replace a larger subarray?
        -> If the given array is already non-decreasing, then no operations are needed, 
        and the maximum size is simply n.
        -> Otherwise, whenever a decreasing pattern occurs, we may be forced to merge more than 
        two elements together until the sequence becomes non-decreasing again.
        
        Example 1: nums = [4,2,5]
        1) i = 0 → push 4 (stack = [4]).
        2) i = 1 → 2 < 4, so push 2 (stack = [4,2]).
        3) i = 2 → current element = 5. Pop elements from the stack until we find something > 5 
        in the stack. If we find anything >5 then the stack wont become empty which means 5 is a
        part of the subarray which is already present in the stack for replacement. If we do not 
        find any element > 5 , then 5 is a part of new subarray replacement and thus we increment
        the answer.
        Pop 2, then pop 4. Now the stack is empty.
        This means the subarray [4,2] collapses into its maximum (4).
        Push 5 (stack = [5]).
        Final compressed array = [4,5] → size = 2.
        */
        int i = 0;
        stack<int> s;
        int ans = 0;
        int n = nums.size();
        while(i<n)
        {
            while(!s.empty() and nums[i]>=nums[s.top()])
            s.pop();
            if(s.empty())
            ans++;
            s.push(i);
            i++;
        }
        return ans;
    }
};
