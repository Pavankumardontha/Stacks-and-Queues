class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        /*
        The key idea:
        -> The deque (dq) stores indices of elements, not values directly.
        -> The elements inside the deque are always kept in decreasing order of their values (from front → back).
        -> The front of the deque always contains the index of the maximum element of the current window.
        
        Example: nums = [1,3,-1,-3,5,3,6,7], k = 3
        
        Step 1: i=0, nums[0] = 1
        dq = [] → insert 1.
        dq = [0] (we store index 0, value = 1).
        Window size < k → no output yet.
        ans = []
        
        Step 2: i=1, nums[1] = 3
        dq = [0] → nums[0] = 1 < nums[1] = 3 → pop index 0.
        Insert index 1.
        dq = [1] (value = 3).
        Window size < k → no output yet.
        ans = []

        Step 3: i=2, nums[2] = -1
        dq = [1] → nums[1] = 3 > -1 → keep it.
        Insert index 2.
        dq = [1,2] (values [3, -1]).
        Now window size = k → take front element → nums[1] = 3.
        ans = [3]

        Step 4: i=3, nums[3] = -3
        dq = [1,2] → nums[2] = -1 > -3 → keep it.
        Insert index 3.
        dq = [1,2,3] (values [3, -1, -3]).
        Window covers indices [1,2,3].
        Check if dq front is outside window: index 1 is still inside, so keep.
        Max = nums[1] = 3.
        ans = [3,3]

        Step 5: i=4, nums[4] = 5
        dq = [1,2,3]. Now check from the back:
        nums[3] = -3 < 5 → pop index 3.
        nums[2] = -1 < 5 → pop index 2.
        nums[1] = 3 < 5 → pop index 1.
        Insert index 4.
        dq = [4] (value = 5).
        Window = [2,3,4].
        Max = nums[4] = 5.
        ans = [3,3,5]

        Step 6: i=5, nums[5] = 3
        dq = [4] → nums[4] = 5 > 3 → keep.
        Insert index 5.
        dq = [4,5] (values [5,3]).
        Window = [3,4,5].
        Max = nums[4] = 5.
        ans = [3,3,5,5]

        Step 7: i=6, nums[6] = 6
        dq = [4,5].
        nums[5] = 3 < 6 → pop index 5.
        nums[4] = 5 < 6 → pop index 4.
        Insert index 6.
        dq = [6] (value = 6).
        Window = [4,5,6].
        Max = nums[6] = 6.
        ans = [3,3,5,5,6]

        Step 8: i=7, nums[7] = 7
        dq = [6].
        nums[6] = 6 < 7 → pop index 6.
        Insert index 7.
        dq = [7] (value = 7).
        Window = [5,6,7].
        Max = nums[7] = 7.
        ans = [3,3,5,5,6,7]
        ✅ Final Answer: [3,3,5,5,6,7]
        */
        int n = nums.size();
        int start = 0;
        int end = 0;
        int current_window_size;
        deque<int> dq;
        vector<int> ans;
        while(end<n)
        {
            if(dq.empty() or nums[dq.back()]>=nums[end])
            dq.push_back(end);
            else
            {
                while(!dq.empty())
                {
                    if(nums[dq.back()]<nums[end])
                    dq.pop_back();
                    else
                    break;
                }
                dq.push_back(end);
            }
            current_window_size = end-start+1;
            if(current_window_size == k)
            {
                ans.push_back(nums[dq.front()]);
                start++;
                if(dq.front()<start)
                dq.pop_front();
            }
            end++;
        }
        return ans;
    }
};
