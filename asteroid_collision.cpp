class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        int n = asteroids.size();
        stack<int> s;
        vector<int> ans;
        int i = 0;
        while(i<n)
        {
            if(s.empty())
            s.push(asteroids[i]);
            else
            {
                while(!s.empty())
                {
                    if(s.top()<0 and asteroids[i]<0)
                    {
                        // both negative
                        s.push(asteroids[i]);
                        break;
                    }
                    else if(s.top()>=0 and asteroids[i]>=0)
                    {
                        // both positive
                        s.push(asteroids[i]);
                        break;
                    }
                    else
                    {
                        // we now for sure that s.top() and incoming element have opposite signs
                        /*
                        collisions only happens when s.top() is postive (moving to right) and incoming element 
                        is negative (moving to left)
                        */
                        if(s.top()>=0 and asteroids[i]<0)
                        {
                            if(s.top()<abs(asteroids[i]))
                            {
                                s.pop();
                                if(s.empty())
                                {
                                    s.push(asteroids[i]);
                                    break;
                                }
                            }
                            else if(s.top()==abs(asteroids[i]))
                            {
                                s.pop();
                                break;
                            }
                            else
                            break;
                        }
                        else
                        {
                            s.push(asteroids[i]);
                            break;
                        }
                    }
                }
            }
            i++;
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
