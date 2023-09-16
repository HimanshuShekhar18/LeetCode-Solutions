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







