class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) 
    {
        /*
        To be a celebrity we have to obey 2 conditions
        1) The person i should be known by all (mat[j][i]=1 for all j's)
        2) The person i should not know anyone (mat[i][j]=0 for all j's)
        
        If a celebrity exists , there can only be one celebrity. Not more than one 
        celebrity is not possible.
        */
        int n = mat.size();
        int m = mat[0].size();
        int start = 0; // starting person
        int end = n-1; // ending person
        
        int celebrity = -1;
        while(start<=end)
        {
            if(start==end)
            {
                // check the entire row and col of start
                for(int i=0;i<n;i++)
                {
                    if(mat[i][start]!=1)
                    return -1;
                }
                
                for(int i=0;i<m;i++)
                {
                    if(start!=i and mat[start][i]!=0)
                    return -1;
                }
                celebrity = start;
                start++;
                end--;
            }
            else
            {
            /*
            We have 2 persons now , start and end and we need to check which person has a 
            possibility of being a celebrity and which person does not have.
            
            We have 4 possibilities
            1) mat[start][end]=1,mat[end][start]=1 => both persons know each other => both cannot be celebrity(start++ and end--)
            2) mat[start][end]=0,mat[end][start]=0 => both dont know each other => both cannot be celebrity (start++ and end--)
            3) mat[start][end]=1,mat[end][start]=0 => start knows end and end does not know start => start cannot be a celebrity => start++
            4) mat[start][end]=0,mat[end][start]=1 => start does not know end and end knows start => end cannot be a celebrity => end--
            */
                if(mat[start][end]==1 and mat[end][start]==1)
                {
                    start++;
                    end--;
                }
                else if(mat[start][end]==0 and mat[end][start]==0)
                {
                    start++;
                    end--;
                }
                else if(mat[start][end]==1 and mat[end][start]==0)
                start++;
                else
                end--;
            }
        }
        return celebrity;
    }
};
