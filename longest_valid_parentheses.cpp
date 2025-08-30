/*
Generic approach 
-> take a stack and if s[i]='(' push its index into the stack
-> if s[i]=')' and stack top is '(' , then we can get the length of the valid parenthesis formed by these
2 characters as i-st.top()+1.

But consider this example : )()())
                            012345 
using i to iterate over the above string 
-> i = 0 , st = []
-> i = 1 , st = [1] since s[1]='('
-> i = 2 , compute length of valid parenthesis i-st.top()+1 = 2-1+1 = 2 (formed by index 1,2) and pop the top
element from the stack
-> i = 3 , st = [3]
-> i = 4 , st = [] -> same as i=2 , we will get the length of valid parenthesis as 2 (formed by index 3,4)

But the longest valid parenthesis is 4 formed by (1,2,3,4) 

-> How to handle this case ?? 
Approach - 2 :- Instead of computing the length of the valid parenthesis using the top of the 
stack which forms the pair with our current ')' bracket , We will first pop the top element which
forms the pair with our current ')' bracket and then calculate its length using the top element. 
first pop and then use the top element to calculate the length of the valid parentheses

example : "))(()))()"
           012345678

Initially stack = [-1] , this is used to calculate the length when the valid parenthesis also contains the character at index 0. (in that case the stack becomes entirely empty and there will be
no top element to calculate the length)
1) if the character is '(' , we just push its index into the stack. 
2) if the character is ')' then 
a) if the top of the stack is '(' . pop the top element,calculate the length using i-st.top() and move forward.
b) if the top of the stack is not present(-1) or if it is ')' , then just push the index of current incoming character 
')' into the stack and move forward.
3) After the scan is done, the stack will only contain the indices of characters which cannot 
be matched. we can use the opposite side - substring between adjacent indices present in the stack after the entire 
string is scanned should be valid parentheses. 
4) If the stack is empty, the whole input string is valid. Otherwise, we can 
scan the stack to get longest valid substring as described in step 3.
*/

class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int n = s.length();
        stack<int> st;
        st.push(-1);
        int max_len = 0;
        int current_len;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            st.push(i);
            else
            {
                if(st.top()==-1)
                {
                    /*
                    there is no '(' character present in the stack to form a valid parentheses with the incoming ')' 
                    character so we just push the current index into the stack which may be used further for length computation
                    */
                    st.push(i);
                }
                else
                {
                    if(s[st.top()]==')') // no '(' character to match
                    st.push(i);
                    else
                    {
                        // the top element of the stack is not '(' which can form valid parentheses with our current incoming character ')'
                        st.pop();
                        current_len = i-st.top();
                        max_len = max(max_len,current_len);
                    }
                }
            }
        }
        return max_len;
    }
};
