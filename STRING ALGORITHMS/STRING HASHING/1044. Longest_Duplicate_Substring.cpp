class Solution {
public:
   
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


