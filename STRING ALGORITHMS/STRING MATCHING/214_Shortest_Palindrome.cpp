
class Solution {
public:
    string shortestPalindrome(string s) {
        int s_length = s.length();
        string str = s;
        reverse(str.begin(),str.end());
        string s_and_reverse = s+"#"+str;
        int n = s_and_reverse.length();
        vector<int> lps(n,0);
        int i = 1, len = 0;
       
        while(i<n){

                if(s_and_reverse[i]==s_and_reverse[len]){
                    len++;
                    lps[i]=len;
                    i++;
                }
                else{
                    if(len>0){
                        len = lps[len-1];
                    }
                    else{
                        i++;
                    }
                }
        }
        
        // Calculate LPP ( Longest Prefix Palindrome ) i.e. Longest Palindromic Substring starting at 0 using LPS.
        int max = lps[n-1];  

        int remainlength = s_length-max;

        string notpalindrome = s.substr(max,remainlength);

        reverse(notpalindrome.begin(),notpalindrome.end());

        string ans = notpalindrome+s;

        return ans;
    }
};




