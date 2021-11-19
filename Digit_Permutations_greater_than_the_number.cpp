#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
Count natural numbers whose all permutation are greater than that number.
NOTE :- All the permutations of a number 'x' must be less than or equal to x. We cannot count 10 since its 
permutation 01 is less than 10. We cannot count 120 since its permutation 012 is less than 120.

	test case - 1:-
	say n = 21 then  
	1,2,3,4,5,6,7,8,9,11,12,13,14,15,16,17,18,19 so ans = 18
	
	test case - 2:-
	say n=99 then 
	1,2,3,4,5,6,7,8,9 -----------------9
	11,12,13,14,15,16,17,18,19---------9
	22,23,24,25,26,27,28,29------------8
	33,34,35,36,37,38,39---------------7
	44,45,46,47,48,49------------------6
	55,56,57,58,59---------------------5
	66,67,68,69------------------------4
	77,78,79---------------------------3
	88,89------------------------------2
	99---------------------------------1
	
	total = 54
	
	test case- 3:-
	say n=158
	1,2,3,4,5,6,7,8,9 --------------------------9
	11,12,13,14,15,16,17,18,19------------------9
	22,23,24,25,26,27,28,29---------------------8
	33,34,35,36,37,38,39------------------------7
	44,45,46,47,48,49---------------------------6
	55,56,57,58,59------------------------------5
	66,67,68,69---------------------------------4
	77,78,79------------------------------------3
	88,89---------------------------------------2
	99------------------------------------------1
	111,112,113,114,115,116,117,118,119---------9
	122,123,124,125,126,127,128,129-------------8
	133,134,135,136,137,138,139-----------------7
	144,145,146,147,148,149---------------------6
	155,156,157,158-----------------------------4
	ans = 88
	
Any permutation of a number n is greater than or equal to itself if and only if all the digits in the number n are 
in increasing order. !!!
if(n<=9) then ans = n. 
Lets now see if n happens to be greater than 9.We will loop from 1 to 9. In each loop we will push each element into
a stack. After pushing the element into the stack we will find the top element. Now, pop the top element, say topel 
and try to make number whose digits are in increasing order and the first digit is topel. To make such numbers, 
the second digit can be from topel%10 to 9. If this number is less than n, increment the count and push the number 
in the stack, else ignore.

if n=197, by pushing 1, we will form all the elements like 
1,11,12,13,14,15,16,17,18,19
using 11, we can form 111,112,113,114,115,116,117,118,119
using 12,we can form 122,123,124,125,126,127,128,129
using 13,we can form 133,134,135,136,137,138,139
using 14,we can form 144,145,146,147,148,149 
using 15,we can form 155,156,157,158,159
using 16,we can form 166,167,168,169
using 17,we can form 177,178,179
using 18,we can form 188,189
using 19,we can from 199 but 199<n=>we will not push 199 into the stack. 
So just by pushing 1,we could generate these many numbers whose permutations are less than 
the number itself. We will repeat the same loop from 2 to 9 to generate rest all numbers.
*/
	
	
int f(int n)
{
	if(n<=9)
	return n;
	else
	{
		int ans = 0;
		stack<int> s;
		for(int i=1;i<=9;i++)
		{
			s.push(i);
			ans++;
			
			//we will now count all the numbers forming with i
			while(!s.empty())
			{
				int tp = s.top();
				s.pop();
				for(int j=tp%10;j<=9;j++)
				{
					int x = tp*10 + j ;
					if(x<=n)
					{
						s.push(x);
						ans++;
					}
				}
			}
		}
		return ans;
	}
}
int main()
{
	int n;
	cin>>n;
	int ans = f(n);
	cout<<ans<<endl;
}
