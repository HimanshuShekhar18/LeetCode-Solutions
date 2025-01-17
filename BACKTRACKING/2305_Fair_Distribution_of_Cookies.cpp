class Solution {
public:

/*

Recursion and Backtracking i.e. enumerating all possibilities
TC: O( k^n * k )
SC: O( k + n ) i.e. unordered_map space and stack space

*/

        void solve(vector<int>&cookies, int k, int index, unordered_map<int,int> &mp, int &ans){
        
        if(index==cookies.size()){
            int maximum = 0;
            for(auto m: mp){
                maximum = max(maximum, m.second);
            }
            ans = min(ans,maximum);
            return;
        }

        for(int i = 0; i<k; i++){
            mp[i]+=cookies[index];  //pick
            solve(cookies,k,index+1,mp,ans);
            mp[i]-=cookies[index]; // not-pick
        }
        return;       
    }

    int distributeCookies(vector<int>& cookies, int k) {
        
        unordered_map<int,int> mp;
        int ans = INT_MAX;
        solve(cookies,k,0,mp, ans);
        return ans;
    }
};


