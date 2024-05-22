class Solution {
public:

    vector<vector<string>> ans;

    bool ispalindrome(string s, int left, int right){

        while(left<right){

                if(s[left]!=s[right]) return false;
                left++;
                right--;
        }
        return true;
    }

    void solve(string s, int index, vector<string> &vect){

        if(index>=s.length()){
            ans.push_back(vect);
            return;
        }

        for(int i = index; i<s.length(); i++){
            if(ispalindrome(s,index,i)){
                    cout << index << " " << i<< endl;
                    vect.push_back(s.substr(index,i-index+1));
                    solve(s,i+1,vect);
                    vect.pop_back();
            }
        }

        return;

    }


    vector<vector<string>> partition(string s) {

        vector<string> vect;

        solve(s,0,vect);

        return ans;
        
    }
};



// <--------------------------------------------------------------------------------------------------------------------------------------------------------------------------->


class Solution {
public:

/*

BACKTRACKING AND DYNAMIC PROGRAMMING for Pre-Computation

Make a 2-D palindrome matrixdp for every combination and start from bottom s.size()-1
i) for i>j dp[i][j] --> nothing neglect
ii) for i==j dp[i][j]=1 --> base case
iii) for i<j compute dp[i][j]

    for ag: ababa,
    the corresponding 2-D Matrix

                         0 1 2 3 4
                         a b a b a
                    0  a T _ _ _ _
                    1  b * T _ _ _
                    2  a * * T _ _
                    3  b * * * T _
                    4  a * * * * T

    The Exact Pre-Computation we already did in 647. Palindromic Substrings

*/

int n;
vector<vector<string>> ans;

void precomputedpmatrix(string s, vector<vector<int>> &dp){


        for(int i = n-1; i>=0; i--){
            for(int j = i; j<n; j++){

                    if(i==j) dp[i][j]=1;
                    else if(i+1==j) dp[i][j]=s[i]==s[j]?1:0;
                    else dp[i][j]=s[i]==s[j]?dp[i+1][j-1]:0;
            }
        }
}

    void solve(int index, string s, vector<string> vect,vector<vector<int>>& dp){
        if(index==n){
            ans.push_back(vect);
            return;
        }

        for(int i = index; i<n; i++){
            if(dp[index][i]){
            vect.push_back(s.substr(index,i-index+1));
            solve(i+1,s,vect,dp);
            vect.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {

        n = s.length();

        vector<vector<int>> dp(n, vector<int> (n,-1));

        precomputedpmatrix(s,dp);

        vector<string> vect;

        solve(0,s,vect,dp);

        return ans;        
    }
};


