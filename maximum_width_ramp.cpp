vector<int> greaterElementToRight(vector<int>& nums)
{
    int n = nums.size();
    int max_val = nums[n-1];
    vector<int> ans(n,0);
    ans[n-1]=nums[n-1];
    for(int i=n-2;i>=0;i--)
    ans[i]=max(nums[i],ans[i+1]);
    return ans;
}

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        /* 
        For each element we need to find the last (as right as possible)
        next greater element to the right.
        here for example : [6,0,8,2,1,5]
        the next greater element of 0 is 8
        the last next greater element of 0 is 5.
        Example: [6,0,8,2,1,5]
        we will create a new array called greater vector
        greater[i] = max(nums[i],nums[i+1]...nums[n-1]) = maximum element to the right in the range 
              nums=[6,0,8,2,1,5] -> iterate using i pointer
        greater[i]=[8,8,8,5,5,5] -> iterate using j pointer

        start with i=0 and j=1 since for i=0 we need to look for greatest element in the range [1,n-1]
        1) i=0 , j=1 => nums[0]<=nums[1] => increment j ans = (1-0)=1
        2) i=0 , j=2 => nums[0]<=nums[2] => increment j ans = (2-0)=2
        3) i=0 , j=3 => nums[0] is not less than or equal to nums[3] so increment i
        4) i=1 , j=3 => nums[1]<=nums[3] => increment j ans = max(ans,j-i) = max(2,3-1)=2
        5) i=1 , j=4 => nums[1]<=nums[4] => increment j ans = max(ans,j-i) = max(2,4-1)=3
        6) i=1, j=5 => nums[1]<=nums[5] => increment j ans = max(ans,j-i) = max(3,5-1) = 4
        end the loop since j==n
        */
        int n = nums.size();
        vector<int> greater = greaterElementToRight(nums);
        int i = 0;
        int j = 1;
        int max_ramp = 0;
        while(i<n and j<n)
        {
            if(nums[i]<=greater[j])
            {
                max_ramp = max(max_ramp,j-i);
                j++;
            }
            else
            i++;
        }
        return max_ramp;
    }
};
