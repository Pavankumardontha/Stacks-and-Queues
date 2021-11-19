/*Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring.
NOTE: Length of smallest the valid substring ( ) is 2.*/

class Solution {
  public:
    int findMaxLen(string s) 
    {
/* here we push the indices into the stack to calculate the max valid length of the 
string.
since we are dealing with stacks, stack can be empty or non-empty .
and string s[i] can be '(' or ')'
initially ans = 0 (this is our maximum length)
So in total we have 4 cases to deal with 
1) stack empty and s[i]= )
2) stack empty and s[i]= (
3) stack not empty and s[i]= ) 
4) stack not empty and s[i]= (

In case-1 we just dont push it into the stack and we move to the next element 
In case-2 we will push the index of '(' into the stack.
In case-3 here we will calculate the temp length = i-s.top()+1. we will also pop out 
the top element. !! We will compare our temporary length with our ans. If our temp 
length is more than the ans,then we will update the answer in this case. !! 
In case-4 we will just put the index of '(' into the stack and move on to the next 
element. !!

Lets apply the above method to this test case )(())((()))

) ( ( ) ) ( ( ( ) ) )
0 1 2 3 4 5 6 7 8 9 10

By the above method the answer is 6 but the correct answer is 10 !!! 
and the longest sequence is :- 

( ( ) ) ( ( ( ) ) ) 
1 2 3 4 5 6 7 8 9 10

CONCLUSION :- The above method fails if we have 2 valid continuous parenthesis which 
make the stack empty. Our answer gives the maximum of the length of the 2 valid 
continuous string but the answer must be the sum of their lengths. !!! 

We will slightly modify the above program to account for this case also. When the 
stack becomes empty while in loop index i, we will calculate the temporary answer 
length using the formula (i+1) and also if string is empty and if s[i]=')' we will 
just push that index into the stack. !! This modification is enough to account for 
this case.!!!


we will push -1 into the stack, Now the stack can never be empty. !!! so now we have 
only 2 possibilities instead of 4 in the previous case.

1) if s[i] = '(' then we will just push it into the stack 
2) if s[i] = ')' and s.top()==-1 then we will just push index into the stack 
else 
if(s[s.top()] == '(') then we will find the temp ans and if not we will just push 
the index and move forward
tempans = i - s.top() + 1;
*/
        stack<int> st;
        int ans = 0; //final ans
        int tans; //temporary ans
        st.push(-1);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            st.push(i);
            else if(s[i]==')' && st.top()==-1)
            st.push(i);
            else
            {
                if(s[st.top()]=='(')
                {
                    st.pop();
                    tans = i - st.top();
                    if(tans>ans)
                    ans = tans;
                }
                else
                st.push(i);
            }
            
        }
        return ans;
    }
};
