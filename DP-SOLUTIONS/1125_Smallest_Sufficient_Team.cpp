class Solution {
public:

/*
Implementation Type I
2D-DP + BITMASKING + 0/1 Knapsack ( Pick or Non-Pick ) Approach
dp[index][mask]
TC: O ( 2^m * n )
SC: O ( 2^m + m )
*/

    long long dp[61][1<<16];

    void solve(long long index, int mask_required, int n, int m, vector<int> &people_skill_mask, long long result, long long &final_result){

        if(index==n){
            if(mask_required==0){
                if( final_result == 0 || (__builtin_popcountll(result) < __builtin_popcountll(final_result))){
                    final_result = result;
                }
            }
            return;  
        }

        // pruning
        if((final_result)!=0 && (__builtin_popcountll(final_result) <= __builtin_popcountll(result))) return;
        
        // Important if for mask_required ans is already calculated, we have to check whether the current ans is better than calculated ans
        // If in current ans the number of persons selected are less than in calculated ans, then We will go with current ans else return with calculated ans
        if(dp[index][mask_required]!=-1) {
            if(__builtin_popcountll(dp[index][mask_required]) <= __builtin_popcountll(result)) return;
        }

        // pick this i'th person
        if(people_skill_mask[index]!=0){  // In Case people = [ [],[] ]
    
        solve(index+1, mask_required&(~people_skill_mask[index]), n, m, people_skill_mask, result|(1LL<<index), final_result);
        
        }

        // not pick this i'th person
        solve(index+1, mask_required, n, m, people_skill_mask, result, final_result);

        dp[index][mask_required]=result==0?-1:result;

    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        int m = req_skills.size();
        int n = people.size();
        memset(dp,-1,sizeof(dp));
        unordered_map<string,int> mp;
        for(int i = 0; i<m; i++){
            mp[req_skills[i]]=i;
        }
        vector<int> people_skill_mask(n, 0);
        for(int i = 0; i<people.size(); i++){
            for(int j = 0; j<people[i].size(); j++){
                    people_skill_mask[i] |= (1<<mp[people[i][j]]);
            }
        }
 
        long long result = 0;
        long long final_result = 0;
        solve(0, (1<<m)-1, n, m, people_skill_mask, result, final_result );
        vector<int> final_ans;
        for(int i = 0; i<n; i++){
            if(final_result&(1LL<<i)) final_ans.push_back(i);
        }
        return final_ans;
    }
}; 



// <-------------------------------------------------------------------IMPLEMENTATION TYPE II ------------------------------------------------------------->



class Solution {
public:

/*
Implementation Type II
1D-DP + BITMASKING + 0/1 Knapsack ( Pick or Non-Pick ) Approach
dp[mask]
TC: O ( 2^m * n )
SC: O ( 2^m + m )
*/

    long long dp[1<<16];

    void solve(long long index, int mask_required, int n, int m, vector<int> &people_skill_mask, long long result, long long &final_result){

        if(index==n){
            if(mask_required==0){
                if( final_result == 0 || (__builtin_popcountll(result) < __builtin_popcountll(final_result))){
                    final_result = result;
                }
            }
            return;  
        }

        // pruning
        if((final_result)!=0 && (__builtin_popcountll(final_result) <= __builtin_popcountll(result))) return;
        
        // Important if for mask_required ans is already calculated, we have to check whether the current ans is better than calculated ans
        // If in current ans the number of persons selected are less than in calculated ans, then We will go with current ans else return with calculated ans
        if(dp[mask_required]!=-1) {
            if(__builtin_popcountll(dp[mask_required]) <= __builtin_popcountll(result)) return;
        }

        // pick this i'th person
        if(people_skill_mask[index]!=0){  // In Case people = [ [],[] ]
    
        solve(index+1, mask_required&(~people_skill_mask[index]), n, m, people_skill_mask, result|(1LL<<index), final_result);
        
        }

        // not pick this i'th person
        solve(index+1, mask_required, n, m, people_skill_mask, result, final_result);

        dp[mask_required]=result==0?-1:result;

    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        int m = req_skills.size();
        int n = people.size();
        memset(dp,-1,sizeof(dp));
        unordered_map<string,int> mp;
        for(int i = 0; i<m; i++){
            mp[req_skills[i]]=i;
        }
        vector<int> people_skill_mask(n, 0);
        for(int i = 0; i<people.size(); i++){
            for(int j = 0; j<people[i].size(); j++){
                    people_skill_mask[i] |= (1<<mp[people[i][j]]);
            }
        }
 
        long long result = 0;
        long long final_result = 0;
        solve(0, (1<<m)-1, n, m, people_skill_mask, result, final_result );
        vector<int> final_ans;
        for(int i = 0; i<n; i++){
            if(final_result&(1LL<<i)) final_ans.push_back(i);
        }
        return final_ans;
    }
}; 



// <-----------------------------------------------------------IMPLEMENTATION TYPE III------------------------------------------------------------------------>

/*

Implementation Type III
2D-DP ( dp[index][mask] ) + BITMASKING + 0/1 Knapsack ( Pick or Non-Pick ) Approach
TC: O ( 2^m * n )
SC: O ( 2^m + m )

This Implementation is Different, current standing at "index" with "mask" dp[index][mask] will ask from below indexes and get the best answer with current "mask" from them 
and while going up it will decide whether to "take current index" or "not take current index"

*/

class Solution {
public:
    long long dp[61][1 << 16];
    long long solve(long long index, int mask_required, int n,  vector<int>& people_skill_mask) {
        
        if (index == n) {
            if (mask_required == 0) {
            return 0LL;
            }
            return (1LL<<n)-1LL;
        }
        
        if (dp[index][mask_required] != -1) return dp[index][mask_required];
        long long ans1 = LLONG_MAX;
        if (people_skill_mask[index] != 0) {
            // pick this i'th person
            ans1 = solve(index + 1, mask_required & (~people_skill_mask[index]), n, people_skill_mask);
            ans1 = ans1 | (1LL<<index); 
        }
        // not pick this i'th person
        long long ans2 = solve(index + 1, mask_required, n, people_skill_mask);
        return dp[index][mask_required] = (__builtin_popcountll(ans1) < __builtin_popcountll(ans2))? ans1: ans2;
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int m = req_skills.size();
        int n = people.size();
        memset(dp, -1, sizeof(dp));
        unordered_map<string, int> mp;
        for (int i = 0; i < m; i++) {
            mp[req_skills[i]] = i;
        }
        vector<int> people_skill_mask(n, 0);
        for (int i = 0; i < people.size(); i++) {
            for (int j = 0; j < people[i].size(); j++) {
                people_skill_mask[i] |= (1 << mp[people[i][j]]);
            }
        }
    
        long long result = solve(0, (1 << m) - 1, n, people_skill_mask);
        vector<int> final_ans;
        for (int i = 0; i < n; i++) {
            if (result & (1LL << i))
                final_ans.push_back(i);
        }
        return final_ans;
    }
};



// ----------------------------------------------------TABULATION OF IMPLEMENTATION TYPE III ------------------------------------------------------------>

/*
TABULATION OF Implementation Type III
2D-DP ( dp[index][mask] ) + BITMASKING + 0/1 Knapsack ( Pick or Non-Pick ) Approach
TC: O ( 2^m * n )
SC: O ( 2^m + m )
*/

class Solution {
public:
    

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int m = req_skills.size();
        int n = people.size();
        vector<vector<long long>> dp(n+1, vector<long long> (1<<m, LLONG_MAX));
        unordered_map<string, int> mp;
        for (int i = 0; i < m; i++) {
            mp[req_skills[i]] = i;
        }
        vector<int> people_skill_mask(n, 0);
        for (int i = 0; i < people.size(); i++) {
            for (int j = 0; j < people[i].size(); j++) {
                people_skill_mask[i] |= (1 << mp[people[i][j]]);
            }
        }
    
        dp[0][0] = 0;

        for(int mask = 0; mask<(1<<m); mask++){
            for(int index = 1; index<=n; index++){
                long long ans1 = LLONG_MAX;
                if (people_skill_mask[index-1] != 0) {  // 0 based tha na
                  // pick this i'th personp
                ans1 = dp[index-1][mask & (~people_skill_mask[index-1])]; // 0 based tha na
                ans1 = ans1 | (1LL<<(index-1)); // 0 based tha na
                }
                long long ans2 = dp[index-1][mask];
                dp[index][mask]=min(dp[index][mask], (__builtin_popcountll(ans1) < __builtin_popcountll(ans2))? ans1: ans2);
            }
        }

        long long result = dp[n][(1<<m)-1];
        vector<int> final_ans;
        for (int i = 0; i < n; i++) {
            if (result & (1LL << i))
                final_ans.push_back(i);
        }
        return final_ans;
    }
};







