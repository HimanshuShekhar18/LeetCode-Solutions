class Solution {
public:

/*
ROLLING HASH ( REVERSE HASHING )  CONSTANT SPACE
TC: O(n)
SC: O(1) 
*/

    const int P = 31;
    const int MOD = 1e9+7;

    string longestPrefix(string s) {

        int n = s.length();
        int ans = 0;
        long long prefix_hash = 0;
        long long suffix_hash = 0;
        long long p_pow = 1;

        // ROLLING HASH or REVERSE HASHING
        for (int i = 0; i < n-1; i++) {
            prefix_hash = ((prefix_hash*P)%MOD + (s[i] - 'a' + 1)) % MOD;
            suffix_hash = ( suffix_hash + ((s[n-i-1]-'a'+1) * p_pow) % MOD ) % MOD;
            p_pow = (p_pow * P) % MOD;

            if(prefix_hash==suffix_hash){
                ans = i+1;
            }
        }
        if(ans==0) return "";
        return s.substr(0,ans);
    }
};
