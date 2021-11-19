int celebrity(vector<vector<int> >& m, int n) 
    {
        stack<int> s;
        for(int i=0;i<n;i++)
        s.push(i);
        int ans = -1;
        while(!s.empty())
        {
            int k1 = s.top();
            s.pop();
            if(s.empty())
            {
                ans = k1;
                break;
            }
            int k2 = s.top();
            s.pop();
            if(m[k1][k2])
            {
                //k1 knows k2 
                if(s.empty())
                {
                    ans = k2;
                    break;
                }
                else
                s.push(k2);
            }
            else if(m[k2][k1])
            {
                //k2 knows k1
                if(s.empty())
                {
                    ans = k1;
                    break;
                }
                else
                s.push(k1);
            }
            else
            {
                //both dont any each other so both cannot be a celebrity
                continue;
            }
        }
        if(ans==-1)
        return -1;
        else
        {
            for(int i=0;i<n;i++)
            {
                if(m[i][ans]==0 and i != ans)
                return -1;
                if(m[ans][i] == 1)
                return -1;
            }
            return ans;
        }
    }
