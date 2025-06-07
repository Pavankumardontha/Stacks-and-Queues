class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        /*
        1) To maintain the order of elements in the original string , we need to use some
        data structure. 
        2) We will store the last occurance of each element in an array or map
        3) We will push the elements into stack to main the order. 
        if the incoming character is less than the top character of the string and the 
        top character has the last occurance greater than the current incoming character
        index then we will pop the top character. We will pop untill this condition holds.
        4) If not we just push the characters into the stack
        We should not have duplicates. So we need to keep track of characters that are pushed into the 
        stack and also need to keep track when they are pushed out of the stack. We should not push 
        any character that is already pushed into the stack.

        a) check if the current character is already pushed or not. If its pushed do nothing and continue
        b) if its not pushed, compare the top character in stack with the current character. 
        if the current character is less than the top character and the top character last index is
        more than the current character index , then pop the top character of the stack. Repeat this 
        process.
        */
        int n = s.length();
        unordered_map<char,int> last_index;
        for(int i=0;i<n;i++)
        last_index[s[i]]=i;
        bool is_already_pushed[26]={false}; // used to track if the character is already pushed or not
        stack<char> st;
        int k;
        char temp;
        for(int i=0;i<n;i++)
        {
            k = s[i]-'a';
            if(is_already_pushed[k])
            continue;
            else
            {
                while(!st.empty())
                {
                    temp = st.top();
                    if(s[i]<temp and last_index[temp]>i)
                    {
                        k = temp-'a';
                        is_already_pushed[k]=false;
                        st.pop();
                    }
                    else
                    break;
                }
                k = s[i]-'a';
                is_already_pushed[k]=true;
                st.push(s[i]);
            }
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
