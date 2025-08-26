/*
We’ll maintain these at each step:
s → stack (stores indices of prices)
prices → all stock prices seen so far
span → span values for each price
ans → result of next(price)

Step 1: next(100)
Initially: s = {}, prices = {}, span = {}
ans = 1
Stack empty → push index 0
s = [0]
prices = [100]
span = [1]
return 1

Step 2: next(80)
ans = 1
while loop? → 80 >= prices[0]=100 ❌ (no)
push index 1
s = [0, 1]
prices = [100, 80]
span = [1, 1]
return 1

Step 3: next(60)
ans = 1
while loop? → 60 >= prices[1]=80 ❌
push index 2
s = [0, 1, 2]
prices = [100, 80, 60]
span = [1, 1, 1]
return 1

Step 4: next(70)
ans = 1
while loop:
70 >= prices[2]=60 ✅
→ ans = 1 + span[2] = 1 + 1 = 2
→ pop(2) → s = [0,1]
next check: 70 >= prices[1]=80 ❌ stop
push index 3
s = [0, 1, 3]
prices = [100, 80, 60, 70]
span = [1, 1, 1, 2]
return 2

Step 5: next(60)
ans = 1
while loop: 60 >= prices[3]=70 ❌ stop
push index 4
s = [0, 1, 3, 4]
prices = [100, 80, 60, 70, 60]
span = [1, 1, 1, 2, 1]
return 1

Step 6: next(75)
ans = 1
while loop:
75 >= prices[4]=60 ✅ → ans = 1 + span[4]=1+1=2, pop(4) → s=[0,1,3]
75 >= prices[3]=70 ✅ → ans = 2 + span[3]=2+2=4, pop(3) → s=[0,1]
75 >= prices[1]=80 ❌ stop
push index 5
s = [0, 1, 5]
prices = [100, 80, 60, 70, 60, 75]
span = [1, 1, 1, 2, 1, 4]
return 4

Step 7: next(85)
ans = 1
while loop:
85 >= prices[5]=75 ✅ → ans = 1 + span[5]=1+4=5, pop(5) → s=[0,1]
85 >= prices[1]=80 ✅ → ans = 5 + span[1]=5+1=6, pop(1) → s=[0]
85 >= prices[0]=100 ❌ stop
push index 6
s = [0, 6]
prices = [100, 80, 60, 70, 60, 75, 85]
span = [1, 1, 1, 2, 1, 4, 6]
return 6
*/

class StockSpanner {
stack<int> s;
vector<int> prices; // to store the prices of each day
vector<int> span; // to store the spans of each price
int day;
public:
    StockSpanner() 
    {
        this->day = 0;
    }
    
    int next(int price) 
    {
        int ans = 1;
        while(!s.empty() and price>=prices[s.top()])
        {
            /* 
            VVIMP : If an element comes in a span of another incoming element , it will be 
            poped out from the stack by the incoming element.
            So there will be some elements which will be missed from the stack but will be 
            present in the prices array. Thats the reason , we add spans of the elements.
            */
            
            ans = ans + span[s.top()];
            s.pop();
        }
        s.push(day);
        prices.push_back(price);
        span.push_back(ans);
        day++;
        return ans;
    }
};
