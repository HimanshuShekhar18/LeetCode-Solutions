class Solution {
public:

/*
2D DP  and Sorting and unordered_map
Store Endkaro and Maxinversion beforehand
Two States: indexlength and inversioncount 
Easy Visualization using Recursive Tree
TC: O(n^2)
SC: O(n^2)
*/
    long long dp[310][410];
    const int MOD = 1e9+7;

    long long solve(int indexlength, int inversion, unordered_map<int, int>& mp,
                    int endkaro, int maxinversion) {

        if(inversion>maxinversion) return 0;

        if (indexlength==endkaro) {
            if(mp[indexlength] == inversion){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if (indexlength > endkaro)
            return 0;

        if(mp.find(indexlength)!=mp.end() && mp[indexlength]!=inversion) return 0;
    
        if (dp[indexlength][inversion] != -1)
            return dp[indexlength][inversion];

        long long ans = 0;
        for (int i = 0; i <= indexlength+1; i++) {

            if(mp.find(indexlength+1)!=mp.end() && mp[indexlength+1]!=inversion+indexlength+1-i) continue;
            ans += solve(indexlength + 1, inversion+indexlength+1 - i, mp, endkaro,maxinversion)%MOD;
        }

        return dp[indexlength][inversion] = ans%MOD;
    }

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {

        sort(requirements.begin(), requirements.end());

        int end = requirements.size();

        int endkaro = requirements[end - 1][0];

        unordered_map<int, int> mp;
        int maxinversion = 0;

        for (int i = 0; i < requirements.size(); i++) {
            mp[requirements[i][0]] = requirements[i][1];
            maxinversion=max(maxinversion,requirements[i][1]);
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, mp, endkaro,maxinversion);
  
    }
};


