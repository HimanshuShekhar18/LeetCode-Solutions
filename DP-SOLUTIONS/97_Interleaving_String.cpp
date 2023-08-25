
// <-------------------------------------------SPACE OPTIMIZATION -------------------------------------------------------------->

class Solution {
public:
    int dp[101][101];
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        int n = s2.length();
        vector<int> prev(n+1,0), curr(n+1,0);
        prev[0] = 1;
        curr[0] = 1;
        for(int i = 0; i<=s1.length(); i++){
            for(int j=0; j<=s2.length(); j++){
                    if(i==0&&j==0) continue;
                    else if(i>0 && s1[i-1]==s3[i+j-1] && j>0 &&s2[j-1]==s3[i+j-1]) curr[j] = prev[j] or curr[j-1];
                    else if(i>0 && s1[i-1]==s3[i+j-1]) curr[j]=prev[j];
                    else if(j>0 && s2[j-1]==s3[i+j-1]) curr[j]=curr[j-1];
                    else curr[j]=0;
            }
            prev=curr;
        }
        return prev[s2.length()];
    }
};
