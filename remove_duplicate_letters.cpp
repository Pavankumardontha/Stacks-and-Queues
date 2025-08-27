/* Do 'smallest subsequence of distinct characters' question first before attempting this */
class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        int n = s.length();
        stack<char> st;
        vector<bool> is_pushed_into_stack(26,false);
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++)
        mp[s[i]]++;
        int k,temp;
        int i=0;
        while(i<n)
        {
            k = s[i]-'a';
            if(!is_pushed_into_stack[k])
            {
                /* we need to push our current element into the stack */
                while(!st.empty() and s[i]<st.top())
                {
                    if(mp[st.top()]>=1)
                    {
                        temp = st.top()-'a';
                        is_pushed_into_stack[temp]=false;
                        st.pop();
                    }
                    else
                    break;
                }
                st.push(s[i]);
                is_pushed_into_stack[k]=true;
            }
            mp[s[i]]--;
            i++;
        }
        string ans = "";
        while(!st.empty())
        {
            ans = ans + st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
