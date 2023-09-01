class Solution {
public:
    // without using any built-in function
    // TC: O(n)
    // SC: O(n)    
    unsigned highestPowerof2(unsigned x)
{
    // check for the set bits
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    // Then we remove all but the top bit by xor'ing the
    // string of 1's with that string of 1's shifted one to
    // the left, and we end up with just the one top bit
    // followed by 0's.
    return x ^ (x >> 1);
}
    vector<int> countBits(int n) {
        vector<int> vect;
        int dp[n+10];
        int pow[n+10];
        for(int i = 3; i<=n; i++){
            pow[i] = highestPowerof2(i);
        }
        if(n==0) return {0};
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i<=n; i++){
            dp[i] = 1+dp[i-pow[i]];
        }
        for(int i = 0; i<=n; i++){
            vect.push_back(dp[i]);
        }
        return vect; 
    }
};

// ---------------------------------------------------------------------------------------

#include<math.h>
class Solution {
public:

    // Built_in function Approach
    // TC: O(n*log(n))
    // SC: O(n)

    int dp[100010];

    vector<int> countBits(int n) {
        vector<int> vect;
        if(n==0) return {0};  // changes done here 
        int k = (int)log2(n);  // as log function is not defined at 0;
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i=1; i<=k; i++){
            int ele = (int)pow(2,i);
            dp[ele] = 1;
        }
        for(int i = 3; i<=n; i++){
            int power2 = (int)pow(2,(int)log2(i));
            dp[i] = 1+dp[i-power2];
        }
        for(int i = 0; i<=n; i++){
            vect.push_back(dp[i]);
        }

        return vect;
        
    }
};
