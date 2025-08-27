class Solution {
public:
    string smallestSubsequence(string s) 
    {
        /*
        -> get the frequency map of each character 
        -> initialise the is_already_pushed_in_stack = false for all characters

        -> whenever you push an element into the stack , you should make 2 operations
        is_already_pushed_in_stack[s[i]-'a'] = true and 
        decrement map count => mp[s[i]]--;

        -> whenever you remove something from the stack you need to make 1 operation
        is_already_pushed_in_stack[i] = false since its removed. No need to increment the 
        frequency again. since frequency map stores the frequency of all the characters to the 
        right of the current index.

        -> we will store all the distinct elements in the stack in lexicographically smallest order.
        For this to be possible , we need to use monotonic stack.

        Example : s = "bcabc" mp[a]=1 , mp[b]=2 mp[c]=2
        1) i = 0 push b => st = [b] mp[b]-- => mp[b]=1
        2) i = 1 push c since c>b in lexo order => st = [c,b] => mp[c]-- => mp[c]=1
        3) i = 2 now a comes , a<b and a<c , but if we remove b and c now from the stack , 
        do we get them again since we need to return a subsequence with all distinct characters ??
        if we remove the letters 'b' and 'c' from stack now and if are unable to get them again on the 
        right side of the current index while traversing then we cannot have all distinct characters 
        in our subsequence. We need to make sure  
        -> yes its possible since mp[b]=1 and mp[c]=1 so we can remove them now and obtain them in the 
        future while traversing right. We need to make sure that is_pushed['c']=false and 
        is_pushed['b']=false;
        4) i = 3 , st = [a] mp[a]=0 mp[b]=1 mp[c]=1 => push b since b>a and b is not pushed into the stack 
        5) i = 4 st = [b,a] mp[a]=0 mp[b]=0 mp[c]=0 => push c since c>b and c is not pushed into the stack
        not st = [c,b,a] => removing elements from the stack and reverse the order to get the lexographically
        smallest subsequence.
        */
        int n = s.length();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++)
        mp[s[i]]++;
        vector<bool> is_pushed_into_stack(26,false);
        int k;
        int temp;
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            k = s[i]-'a';
            if(is_pushed_into_stack[k]==false)
            {
                // this is the first occurrence of the character in which case we push the element into the stack
                /* before pushing , we will remove all the characters which increase the lexo order and 
                can be obtained to the right again*/
                while(!st.empty() and s[i]<st.top())
                {
                    if(mp[st.top()]>=1)
                    {
                        // this means that there is atleast one st.top() character to the right of current index i.
                        // we can get the top element of the stack to the right again while traversing so we can remove it for now
                        is_pushed_into_stack[st.top()-'a']=false;
                        st.pop();
                    }
                    else
                    break;
                }
                st.push(s[i]);
                is_pushed_into_stack[k]=true;
                mp[s[i]]--;
            }
            else
            mp[s[i]]--;
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
