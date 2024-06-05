class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char,int> mp;

        for(int i = 0; i<s.length(); i++){
                    mp[s[i]]++;
        }

        int oddcount = 0;
        int evencount = 0;
        bool oddpresent = false;

        for(int i = 0; i<26; i++){

                if(mp[i+'a']%2==0){
                    evencount+=mp[i+'a'];
                }
                else{
                    oddcount+=mp[i+'a']-1;
                    oddpresent = true;
                }
        }

        for(int i = 0; i<26; i++){

                if(mp[i+'A']%2==0){
                    evencount+=mp[i+'A'];
                }
                else{
                   oddcount+=mp[i+'A']-1;
                   oddpresent = true;
                }
        }

        if(oddpresent) return oddcount + evencount + 1;
        return oddcount+evencount;
    }
};
