class Solution {
public:
    int n;
    int dp[2010][2010];
    map<int,int> mp;
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]!=1) return false;
        n = stones.size();
        mp.clear();
        memset(dp,0,sizeof(dp));
        for(int i = 0; i<n; i++){
            mp[stones[i]] = i;
        }

        // why prev<=n?
        /*
        let understand with an example
        0 1 3
        starts from (1,1);
        prev-1 --> no
        prev --> 1+1 = 2 nope
        prev+1 --> 1+2 = 3 --> yes
        ans = dp[2][3] is my ans;
        */
        dp[0][0] = 1;
        for(int index = 0; index<n;index++){
            for(int prev = 0; prev<=n;prev++){
                if(dp[index][prev]){
                 if(prev-1>0 && find(stones.begin(), stones.end(), stones[index]+prev-1)!=stones.end())
                dp[mp[stones[index]+prev-1]][prev-1]=1;
                  if(find(stones.begin(), stones.end(), stones[index]+prev)!=stones.end())
                dp[mp[stones[index]+prev]][prev]=1; 
                  if(find(stones.begin(), stones.end(), stones[index]+prev+1)!=stones.end())
                dp[mp[stones[index]+prev+1]][prev+1]=1; 
              }
            }
        }

        // now really is my ans dp[n-1][n] ?
        /*
        the ans is no the prev can be anything 0 or 1 or 2 or 3 ................. or may be n.
        for example: 
        0 1 2
        starts from (1,1);
        prev-1 --> no
        prev --> 1+1 = 2 yes
        prev+1 --> 1+2 = 3 --> no
        ans = dp[2][2] is my ans;
        
        so, now you just check on which prev i'm getting true
        */
        
        for(int prev = 0; prev<=n; prev++){
            if(dp[n-1][prev]) return true;
        }

        return false;
    }
};
