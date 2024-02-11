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



// <-----------------------------------------------------------------MANACHER'S ALGORITHM---------------------------------------------------------------------->


class Solution {
public:

/*
LPS ( Longest Palindromic Substring )
Print LPS ( Longest Palindromic Substring )

Manacher's Algorithm 
TC: O(n)
SC: O(2*n+1)

*/   

struct manacher
{
      vector<int> p;
      string t;
      int start;
      int maxLength;

      // p[i] = defines how many length of palindrome we have at index i.
      // Actual length of palindrome at p[i] is p[i] - 1, as We initially assigned 1 value to every p[i], So '#' characters also got length 1, which is why we have to subtract 1.
      void run_manacher(string s)
      {
            // modified string "s"
            // cout << s << endl;
            int l = 1, r = 1;
            int n = s.length();

            p.assign(n, 1);
            for (int i = 1; i < n; i++)
            {
              if(l+r-i>=0) p[i] = max(0, min(r - i, p[l + r - i]));

                  // expanding outside
                  while (i - p[i] >= 0 && i + p[i] < n && s[i - p[i]] == s[i + p[i]])
                        p[i]++;

                  // new bounding box or new longer palindrome
                  if (i + p[i] > r)
                  {
                        l = i - p[i];
                        r = i + p[i];

                        if(p[i]-1>maxLength){
                              start=l+2;
                              maxLength=p[i]-1;
                        }
                  }
            }

            // for(auto v: p){
            //       cout << v << " ";
            // }
            // cout << endl;
      }

      // Building the manacher
      void build(string s)
      {

            for (auto v : s)
            {
                  t += string("#") + v;
            }
            t += string("#");

            run_manacher(t);
      }


      string longestPalindromicSubstring(){
            int n = t.size();
            string ans = "";
            while(maxLength){
                  ans+=t[start];
                  start+=2;
                  maxLength--;
            }
         return ans;
      }
} m;

    string longestPalindrome(string s) {
      m.build(s);
      return m.longestPalindromicSubstring();
    }
};





     
















