class Solution {
public:
/* Same Starting Approach without Bitmask as done in Minimum XOR Sum of Two Arrays
--> use map<vector<int>,int>
--> use vis array
COMPLETE GREEDY + RECURSION + MEMOIZATION + NO BITMASKING
TC: O(n*3^numSlots*numSlots)
SC: O(3^numSlots*n)
*/
    vector<int> vis;
    map<vector<int>,int> mp;
    int n;
    int Maximum(vector<int>& nums, int index, int numSlots){
        if(index>=n) return 0;

        if(mp.find(vis)!=mp.end()) return mp[vis];


        int maxi = INT_MIN;
        for(int i = 1; i<= numSlots; i++){
        if(vis[i]<2){
                vis[i]++;
                maxi = max(maxi,(nums[index]&i)+Maximum(nums,index+1,numSlots));
                vis[i]--;
        }
        }

        return mp[vis] = maxi;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        n = nums.size();
        vis.resize(numSlots+1,0);
        mp.clear();
        return Maximum(nums,0,numSlots);
    }
};



// <------------------------------------------------RECURSION + MEMOIZATION + BITMASK(Ternary Digit)--------------------------------------------------------------------------------->



class Solution {
public:
/* 
3-BASED NUMBER SYSTEM
COMPLETE GREEDY + RECURSION + MEMOIZATION + BITMASKING(ternary digit) + BASE-3 NUMBER SYSTEM
TC: O(n*3^numSlots*numSlots)
SC: O(3^numSlots*n)
*/
/*
Wrong Answer
48 / 84 testcases passed

Input nums = [14,7,9,8,2,4,11,1,9]
numSlots = 8
Output
54
Expected
40

Wrong Answer isliye aaya tha kyuki maine bits position ko 0-based indexing mein error tha 


2nd Wrong Answer
75 / 84 testcases passed

Input
nums =
[7,6,13,13,13,6,3,12,6,4,10,3,2]
numSlots =
7

Output
52
Expected
54

*/
    int dp[20][90000];
    int h[13];
    int n;
    int Maximum(vector<int>& nums, int index, int mask, int numSlots){
        if(index>=n) return 0;
        if(dp[index][mask]!=-1) return dp[index][mask];

        int maxi = INT_MIN;
        for(int i = 0; i<numSlots; i++){  // changes done here  0-based indexing
        int a_i = floor((mask%h[i+1])/h[i]);   // changes done here --> give me the value present at the i'th bit position  or it is the status of (i+1)th slot 
        /* 
        i = 0th bit position i.e. 1st Slot
        i = 1st bit position i.e. 2nd Slot
        */
        /*
        for example: mask = (26)10 = (222)3 
        give me what is present at the 2nd bit position i.e. 3rd Slot ka kya status hain (0 or 1 or 2)
        So, 1) humlog ek bit aage se modulo nikalenge i.e. mask ko pow(3,i+1) se modula nikalenge
        2) ab hamare pas ith bit to 0th bit tak ka value present, so upar se obtained modulo ko pow(3,i) se divide karo that will give frontmost value of modulo which we want.
        
        = 2*3^2+2*3^1+2*3^0
        
        I want status at 1st bit position which is = 2
        How i will get ?
        = (2*3^2+2*3^1+2*3^0)%3^(1+1)
        = 2*3^1+2*3^0

        Now Divide by 3^1.
        (2*3^1+2*3^0)/3^1 = 2 
        baki ka to remainder hain(2*3^0)
        */

        /* 
        AND How to Change Status 
        jaise 0-->1-->2 kaise change kare 
        So catch is jis bit position(i) pe change kar rahe ho usme utne power of 3 se addition kardo
        to uss bit position pe 1 increment ho jayega
        
        For Example: (111)3 
        I Want ot change 1st bit position from 1 to 2
        (111)3 = (1*3^2+1*3^1+1*3^0)

        (1*3^2+1*3^1+1*3^0)+3^1 = (1*3^2+2*3^1+1*3^0) = (121)3
        */
        if(a_i<=1) maxi = max(maxi,(nums[index]&(i+1))+Maximum(nums,index+1,mask+h[i],numSlots));  // changes done here
        }
        return dp[index][mask] = maxi;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        h[0]=1;
        for(int i = 1; i<=12; i++) h[i]=h[i-1]*3;   // changes done here
        return Maximum(nums,0,0,numSlots);
    }
};



// <--------------------------------------------------------RECURSION + MEMOIZATION + BITMASK(TIME AND SPACE OPTIMIZED) ------------------------------------------------->



class Solution {
public:
/* 
TIME OPTIMIZED and SPACE OPTIMIZED --> This Time independent of index;
3-BASED NUMBER SYSTEM
COMPLETE GREEDY + RECURSION + MEMOIZATION + BITMASKING(ternary digit) + BASE-3 NUMBER SYSTEM
TC: O(3^numSlots*numSlots)
SC: O(3^numSlots)
*/
    int dp[20000];
    int h[13];
    int n;
    int Maximum(vector<int>& nums, int index, int mask, int numSlots){
        if(index>=n) return 0;
        if(dp[mask]!=-1) return dp[mask];

        int maxi = INT_MIN;
        for(int i = 0; i<numSlots; i++){  // changes done here  0-based indexing
        int a_i = floor((mask%h[i+1])/h[i]);   // changes done here --> give me the value present at the i'th bit position  or it is the status of (i+1)th slot 
        /* 
        i = 0th bit position i.e. 1st Slot
        i = 1st bit position i.e. 2nd Slot
        */
        /*
        for example: mask = (26)10 = (222)3 
        give me what is present at the 2nd bit position i.e. 3rd Slot ka kya status hain (0 or 1 or 2)
        So, 1) humlog ek bit aage se modulo nikalenge i.e. mask ko pow(3,i+1) se modula nikalenge
        2) ab hamare pas ith bit to 0th bit tak ka value present, so upar se obtained modulo ko pow(3,i) se divide karo that will give frontmost value of modulo which we want.
        
        = 2*3^2+2*3^1+2*3^0
        
        I want status at 1st bit position which is = 2
        How i will get ?
        = (2*3^2+2*3^1+2*3^0)%3^(1+1)
        = 2*3^1+2*3^0

        Now Divide by 3^1.
        (2*3^1+2*3^0)/3^1 = 2 
        baki ka to remainder hain(2*3^0)
        */

        /* 
        AND How to Change Status 
        jaise 0-->1-->2 kaise change kare 
        So catch is jis bit position(i) pe change kar rahe ho usme utne power of 3 se addition kardo
        to uss bit position pe 1 increment ho jayega

        For Example: (111)3 
        I Want ot change 1st bit position from 1 to 2
        (111)3 = (1*3^2+1*3^1+1*3^0)

        (1*3^2+1*3^1+1*3^0)+3^1 = (1*3^2+2*3^1+1*3^0) = (121)3
        */
        if(a_i<=1) maxi = max(maxi,(nums[index]&(i+1))+Maximum(nums,index+1,mask+h[i],numSlots));  // changes done here
        }
        return dp[mask] = maxi;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        h[0]=1;
        for(int i = 1; i<=12; i++) h[i]=h[i-1]*3;   // changes done here
        return Maximum(nums,0,0,numSlots);
    }
};



// <--------------------------------------------------------------------BASE-2 SYSTEM-------------------------------------------------------------------------------------->


class Solution {
public:
/* 
Approach-2 using BITMASKING
What does a mask here represents ?

We need to figure out how to define a bit mask in this question.
I used a mask on base-2, where each slot takes two bits. Basically for each slot from i=1 to i=numSlots a slot is represented by two consecutive bits.
Bitmask holds the information about which slots are filled and which are not.

For eg : Consider the i-th slot , we represent the slot by two consecutive bits _ _ .
01 -> means one slot is occupied.
11 -> means both slots are occupied

TC : O(2*numSlots*n*2^numSlots)
SC : O(n*2^numSlots)
*/
/*
Wrong Answer
49 / 84 testcases passed

Input
nums =
[14,7,9,8,2,4,11,1,9]
numSlots =
8

Output
54
Expected
40


REASON --> Tum chutiye ho (mask&(1<<i))==1 kon karta hai yaar; bit check kar rahe na 0 ya 1
 this is correct --> !(mask&(1<<i))
*/
    

int dp[18][(1<<18)];
    int n;
    int numbers(vector<int>& nums, int numSlots, int index, int mask){
        if(index>=n) return 0;
        if(dp[index][mask]!=-1) return dp[index][mask];               
        int ans = INT_MIN;
        for(int i = 0; i<2*numSlots; i++) {
                if(!(mask&(1<<i))) ans = max(ans,((i/2+1)&nums[index])+numbers(nums,numSlots,index+1,(mask|(1<<i))));
        }
        return dp[index][mask] = ans;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return numbers(nums,numSlots,0,0);
    }
};




// <--------------------------------------------------------------------BASE-2 SYSTEM OPTIMIZED -------------------------------------------------------------------------------------->


class Solution {
public:
/* 
Same as Previous Base-2 System; But this time with Better Time and Space Complexity
So what changes you did this time?
In previous what happening was that a single slot took 2-bits; So what i was doing that i considered both first bit and second bit consecutively but things to keep in mind that ki 
pehle first bit wala to bhar lo pehle ki atleast ek number bhi hain ki nahi ??
jab ek number bhi nahi hain to pehle first bit wale pe fill kiya and state change hua jab dubara uss slot pe aaya to 
check kiya agar ek number hain to now this time to fill second number i.e second bit.

TC : O(numSlots*2^(2*numSlots))
SC : O(2^(2*numSlots))
*/

int dp[(1<<18)];
    int n;
    int numbers(vector<int>& nums, int numSlots, int index, int mask){
        if(index>=n) return 0;
        if(dp[mask]!=-1) return dp[mask];               
        int ans = INT_MIN;
        for(int i = 0; i<numSlots; i++) {
            int z = 2*i;
                if(!(mask&(1<<z))) ans = max(ans,((i+1)&nums[index])+numbers(nums,numSlots,index+1,(mask|(1<<z))));
                else {
                    z++;
                    if(!(mask&(1<<z))) ans = max(ans,((i+1)&nums[index])+numbers(nums,numSlots,index+1,(mask|(1<<z))));
                }
        }
        return dp[mask] = ans;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return numbers(nums,numSlots,0,0);
    }
};


