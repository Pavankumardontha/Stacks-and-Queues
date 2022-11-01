// First non-repeating character in a stream (GFG) 
class Solution {
	public:
		string FirstNonRepeating(string s)
		{
		    string ans;
		    unordered_map<char,int> mp ;// hashmap to store the frequency of characters
		    queue<char> q;
		    for(int i=0;i<s.length();i++)
		    {
		        mp[s[i]]++;
		        if(mp[s[i]]==1)
		        q.push(s[i]); // we push into the queue only when the character occurs for the first time
		        while(!q.empty() and mp[q.front()]!=1) // we find the first non-repeating character from the queue
		        q.pop();
		        if(q.empty())
		        ans += '#';
		        else
		        ans += q.front();
		    }
		    return ans;
		}
};
