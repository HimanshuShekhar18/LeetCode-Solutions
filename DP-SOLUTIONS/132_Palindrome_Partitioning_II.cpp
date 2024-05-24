class Solution {
public:

/*
Dynamic Programming of Pick and Non-Pick 
TC: O(n*n*n) 
SC: O(n)
*/

int n;

int memo[2010];

bool ispalindrome(int left, int right, string &s){

        while(left<=right){
            if(s[left]!=s[right]) return false;

            left++;
            right--;
        }

        return true;
    }

    int solve(int index, string &s){
        if(index==n){
            
            return 0;
        }

        if(memo[index] != -1) return memo[index];

        int mincut = INT_MAX;

        for(int i = index; i<n; i++){
            if(ispalindrome(index,i,s)){
            
                mincut = min(mincut,1+solve(i+1,s));
           
            }
        }

        return memo[index]=mincut;
    }

    int minCut(string s) {

        n = s.length();

        memset(memo,-1,sizeof(memo));

        // subtracting 1 as it counts partitions, not cuts.
        return solve(0,s)-1;
        
    }
};



// <----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->


/*
Same DP of Pick and Non-Pick with Pre-Computed Palindrome Matrix 
TC: O(n*n)
SC: O(n*n)
*/


class Solution {
public:

int n;

int memo[2010];

void precomputedpmatrix(string &s, vector<vector<int>> &dp){

        for(int i = n-1; i>=0; i--){
            for(int j = i; j<n; j++){
                    if(i==j) dp[i][j]=1;
                    else if(i+1==j) dp[i][j]=s[i]==s[j]?1:0;
                    else dp[i][j]=s[i]==s[j]?dp[i+1][j-1]:0;
            }
        }
    }

    int solve(int index, string &s, vector<vector<int>>& dp){
        if(index==n){
            
            return 0;
        }

        if(memo[index] != -1) return memo[index];

        int mincut = INT_MAX;

        for(int i = index; i<n; i++){
            if(dp[index][i]){
            
                mincut = min(mincut,1+solve(i+1,s,dp));
           
            }
        }

        return memo[index]=mincut;
    }

    int minCut(string s) {

        n = s.length();

        vector<vector<int>> dp(n, vector<int> (n,-1));

        precomputedpmatrix(s,dp);

        

        memset(memo,-1,sizeof(memo));

        // subtracting 1 as it counts partitions, not cuts.
        return solve(0,s,dp)-1;
        
    }
};

