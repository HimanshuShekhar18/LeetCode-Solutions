class Solution {
public:
    int n;
    int dp[2010][2010];
    map<int,int> mp;
    bool dplagao(int index, int prev, vector<int>&stones){
        if(index==n-1) return true;
        if(dp[index][prev]!=-1) return dp[index][prev];
        bool ans = false;
        if(prev-1>0 && find(stones.begin(), stones.end(), stones[index]+prev-1)!=stones.end())
        ans=ans||dplagao(mp[stones[index]+prev-1],prev-1,stones);
        if(find(stones.begin(), stones.end(), stones[index]+prev)!=stones.end())
        ans=ans||dplagao(mp[stones[index]+prev],prev,stones); 
        if(find(stones.begin(), stones.end(), stones[index]+prev+1)!=stones.end())
        ans=ans||dplagao(mp[stones[index]+prev+1],prev+1,stones); 
        return dp[index][prev] = ans;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]!=1) return false;
        n = stones.size();
        mp.clear();
        for(int i = 0; i<n; i++){
            mp[stones[i]] = i;
        }
        memset(dp,-1,sizeof(dp));
        return dplagao(1,1,stones);
    }
};
