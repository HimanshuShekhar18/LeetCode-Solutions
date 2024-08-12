class Solution {
public:

/*

BINARY SEARCH and RABIN KARP DOUBLE HASHING  "set<pair<long long, long long>> st;"
Using "const int MOD = 1e9+7;"  "int P1 = 31;"  "int P2 = 29;"
TC: O( n * log(n) ) 
SC: O(n)

*/
   
    const int MOD = 1000000007;
    int P1 = 31;
    int P2 = 29;
    int n;

    string duplicateStringOfLengthMid(string& s, int mid, vector<long long>& hash1, vector<long long> hash2) {

        int sp = 0;
        int ep = mid - 1;

        set<pair<long long, long long>> st;
        st.insert({hash1[mid],hash2[mid]});

        sp++;
        ep++;

        // sliding window
        while (ep < n) {


            long long curr_hash1 = (hash1[ep + 1] - hash1[sp - 1 + 1] + MOD) % MOD;
            curr_hash1 = (curr_hash1 * p_pow1[sp]) % MOD;
            long long curr_hash2 = (hash2[ep + 1] - hash2[sp - 1 + 1] + MOD) % MOD;
            curr_hash2 = (curr_hash2 * p_pow2[sp]) % MOD;

            

            if (st.find({curr_hash1,curr_hash2}) != st.end())
                return s.substr(sp,mid);

            st.insert({curr_hash1,curr_hash2});
            sp++;
            ep++;
        }

        return "";
    }

    vector<long long> p_pow1;
    void ComputePower1() {
        int N = n;
        p_pow1.resize(N, 1);
        for (int i = 1; i < N; i++)
            p_pow1[i] = (p_pow1[i - 1] * P1) % MOD;
    }

    vector<long long> p_pow2;
    void ComputePower2() {
        int N = n;
        p_pow2.resize(N, 1);
        for (int i = 1; i < N; i++)
            p_pow2[i] = (p_pow2[i - 1] * P2) % MOD;
    }

    string longestDupSubstring(string s) {

        string result = "";
        int left = 0;
        int right = s.length();
        n = s.length();

        ComputePower1();
        ComputePower2();

        vector<long long> hash1(n + 1, 0);
        vector<long long> hash2(n + 1, 0);

        for (int i = 0; i < n; i++) {
            hash1[i + 1] = (hash1[i] + (s[i] - 'a' + 1) * p_pow1[n-i-1]) % MOD;
        }

        for (int i = 0; i < n; i++) {
            hash2[i + 1] = (hash2[i] + (s[i] - 'a' + 1) * p_pow2[n-i-1]) % MOD;
        }

        // Binary Search
        while (left <= right) {
            int mid = right - (right - left) / 2;

            string ans = duplicateStringOfLengthMid(s, mid, hash1, hash2);

            if (ans.length() > 0) {
                result = ans;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};





// <--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

/*

BINARY SEARCH and ROLLING HASH ( REVERSE HASHING )  
Using "const long long MOD = 1e15;"   and  "int P = 173;"  to Avoid Hash Collisions   
TC: O(n * log( n ) )  SC: O(n)

*/


class Solution {
public:
    const long long MOD = 1e15;
    int P = 173ll;
    string duplicateStringOfLengthMid(string& s, int mid) {
        int sp = 0;
        int ep = mid - 1;
        int n = s.length();
        unordered_set<long long> set;
        long long curr_hash = 0;
        long long p_pow = 1;

        // ROLLING HASH or REVERSE HASHING
        for (int i = mid - 1; i >= 0; i--) {
            curr_hash = (curr_hash + ((s[i] - 'a' + 1) * p_pow)) % MOD;
            if (i == 0)
                break;
            p_pow = (p_pow * P) % MOD;
        }

        set.insert(curr_hash);
        sp++;
        ep++;

        // sliding window
        while (ep < n) {
            curr_hash =
                (curr_hash - ((s[sp - 1] - 'a' + 1) * p_pow) % MOD + MOD) % MOD;
            curr_hash = (curr_hash * P) % MOD;
            curr_hash = (curr_hash + (s[ep] - 'a' + 1));

            if (set.find(curr_hash) != set.end())
                return s.substr(sp, mid);
            set.insert(curr_hash);
            sp++;
            ep++;
        }
        return "";
    }
    string longestDupSubstring(string s) {
        string result = "";
        int left = 0;
        int right = s.length();
        // Binary Search
        while (left <= right) {
            int mid = right - (right - left) / 2;
            string ans = duplicateStringOfLengthMid(s, mid);
            if (ans.length() > 0) {
                result = ans;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};



