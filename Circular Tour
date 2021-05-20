class Solution {
public:
    int canCompleteCircuit(vector<int>& p, vector<int>& d) 
    {
        /* we cannot have a circular tour if the sum of the distances is greater than the 
        amount of petrol we have */
        int tp=0; //total petrol
        int td=0; //total distance
        for(int i=0;i<p.size();i++)
            tp+=p[i];
        for(int i=0;i<d.size();i++)
            td+=d[i];
        if(td>tp)
            return -1;
            
        /* 
        if td<=tp then we are sure of having a solution. That is there exists atleast one point from where we can start and complete a circular tour. We cannot start at a
        point where d[i]>p[i]. So we have to always start at a point where p[i]>d[i] and then proceed to the next points. So now we also have the solution points bounded.
        We have limited points from where we can start and complete a circular tour.We will start from i=0 and go on checking at each point. !! 
        */
        
        int v = 0; //current petrol value
        int ans=0; 
        
/*we will assume that we can take a circular tour from our initial point and update as and when required.*/

        for(int i=0;i<p.size();i++)
        {
            v = v + p[i]-d[i];
            if(v<0)
            {
                v = 0;
                ans = i+1;
            }
        }
        return ans;
    }
};
