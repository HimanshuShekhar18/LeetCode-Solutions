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



// <------------------------------------------------------RECURSION + MEMOIZATION + BITMASK --------------------------------------------------------------------------------->











