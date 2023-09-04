class Solution {
public:
/*
INTUTION PART: RMSB
USING XOR PROPERTY
3       --> 0 1 1
5       --> 1 0 1
xor     --> 1 1 0
RMSB in xor either came from 3 or 5, that's xor property
~xor    --> 0 0 1
~xor+1 -->  0 1 0 --> i got the rmsb
TO Calculate RMSB just do = x&(-x+1);
After that just clubbed all those number whose rmsb is at this position and take xor of them, from
here we will get our first number
For the second number just do xor^first;

TC: O(n)
SC: O(1)
*/
    vector<int> singleNumber(vector<int>& nums) {
        long long res = 0;
        for(auto num: nums){
            res^=num;
        }
        long long rmsb = res&(~res+1); // got Runtime Error here bcoz --> signed integer overflow: 2147483647 + 1 cannot be represented in type  --< changes done here 'int' to 'long long'  
        long long first = 0;
        for(auto num: nums){
            if(rmsb&num) first^=num;
        }
        return {(int)first,(int)(res^first)};
    }
};



