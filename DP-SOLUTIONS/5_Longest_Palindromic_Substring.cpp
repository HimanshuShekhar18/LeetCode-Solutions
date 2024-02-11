class Solution {
public:

/*
LPS ( Longest Palindromic Substring )
Print LPS ( Longest Palindromic Substring )

Generate Substrings Naive Approach: substr() + reverse() --> TLE
TC: O(n^3)
SC: O(n)

*/   

int start = 0, end = 0;
int max = 0;

void solve(int i, int j, string &s){
    
        string str = s.substr(i,j-i+1);
        string strr = str;
        reverse(strr.begin(),strr.end());
        if(str==strr && j-i+1>max) {
                max=j-i+1;
                 start = i;
                 end = j;
        }
    }

    string longestPalindrome(string s) {
        
        for(int i = 0; i<s.size(); i++){
            for(int j = i+1; j<s.size(); j++){
                solve(i,j,s);
            }
        }
        return s.substr(start,end-start+1);
    }
};



// <----------------------------------------------Generate Substrings Naive Approach: substr() + recursion---------------------------------------------------->



class Solution {
public:

/*
LPS ( Longest Palindromic Substring )
Print LPS ( Longest Palindromic Substring )

Naive Approach: substr() and recursion
TC: O(n^3)
SC: O(n)

*/   



bool solve(int i, int j, string &s){
    
       if(i>=j) return true;

       if(s[i]==s[j]) return solve(i+1,j-1,s);

       return false;
    }

    string longestPalindrome(string s) {
        int start = 0;
        int maxLength = INT_MIN;
        for(int i = 0; i<s.size(); i++){
            for(int j = i; j<s.size(); j++){
                if(solve(i,j,s)){
                    if(j-i+1>maxLength){
                        maxLength=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxLength);
    }
};




// <---------------------------------------Generate Substrings DP Approach: substr() and recursion and memoization----------------------------------------------->


class Solution {
public:

/*
LPS ( Longest Palindromic Substring )
Print LPS ( Longest Palindromic Substring )

Naive Approach: substr() and recursion and memoization
TC: O(n^2)
SC: O(n^2)

*/   

int dp[1001][1001];

bool solve(int i, int j, string &s){
    
       if(i>=j) return true;

        if(dp[i][j]!=-1) return dp[i][j];
       if(s[i]==s[j]) return dp[i][j]=solve(i+1,j-1,s);

       return dp[i][j]=false;
    }

    string longestPalindrome(string s) {
        memset(dp,-1,sizeof(dp));
        int start = 0;
        int maxLength = INT_MIN;
        for(int i = 0; i<s.size(); i++){
            for(int j = i; j<s.size(); j++){
                if(solve(i,j,s)){
                    if(j-i+1>maxLength){
                        maxLength=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxLength);
    }
};


