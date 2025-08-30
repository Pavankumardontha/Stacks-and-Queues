class Solution {
public:
    bool isValid(string s) 
    {
        int n = s.length();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(st.empty() and (s[i]==')' or s[i]=='}' or s[i]==']'))
            return false;
            if(s[i]=='(' or s[i]=='{' or s[i]=='[')
            st.push(s[i]);
            else
            {
                if((st.top()=='(' and s[i]==')') or (st.top()=='{' and s[i]=='}') or (st.top()=='[' and s[i]==']'))
                st.pop();
                else
                return false;
            }
        }
        return st.empty();
    }
};
