/* 
Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist, it is -1.

Code Explaination :- 
we have to stack here. The stack can be empty and not empty. The incoming element can be less than the top element on the stack or greater. So we have 4 possibilities.
1) if stack is empty we just push the index of our current element and move forward.
2) if stack is not empty then we have 2 sub-cases.!! 
a) if the incoming element is less than the top element then we just push the index and move forward. 
b) if the incoming element is greater than the top element then we will pop the elements from the stack till the top element is greater than our current element or till the stack 
becomes empty. After that we push the current index of our element.
*/

class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> a, int n)
    {
        vector<long long> ans(n);
        for(int i=0;i<n;i++)
        ans[i]=-1;
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            s.push(i);
            else
            {
                if(a[s.top()]>a[i])
                s.push(i);
                else
                {
                    while(!s.empty())
                    {
                        if(a[s.top()]<a[i])
                        {
                            ans[s.top()] = a[i];
                            s.pop();
                        }
                        else
                        break;
                    }
                    s.push(i);
                }
                
            }
        }
        return ans;
    }
};
