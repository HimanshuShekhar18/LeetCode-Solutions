
class Solution {
public:

/*
SIMPLE RECURSION AND BACKTRACKING
*/
   
    int scores[15] = {0};

    bool possible(string word, unordered_map<char,int>&mp){
        unordered_map<char,int> mp1;
        for(auto id: word){
            mp1[id]++;
        }

        for(auto id: word){
            if(mp1[id]>mp[id]) return false;
        }

        for(auto x : mp1){
            mp[x.first]-=x.second;
        }
        mp1.clear();
        return true;
    }

    int solve(int index, vector<string>& words, unordered_map<char,int> &mp){
        if(index==words.size()) return 0;


        bool s = possible(words[index],mp);
        int pick = 0;
        if(s)
        {
            pick = scores[index]+solve(index+1,words,mp);
        
            for(auto id: words[index]){
                mp[id]++;
            }
        }

        int non_pick = 0+solve(index+1,words,mp);

        return max(pick,non_pick);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
         unordered_map<char,int>mp;
        for(int i = 0; i<words.size(); i++){
            int sum = 0;
            for(auto id: words[i]){
                sum+=score[id-'a'];
            }
            scores[i]=sum;
        }

        for(auto id: letters){
            mp[id]++;
        }

        return solve(0,words,mp);

    }
};




// <----------------------------------------------------------------------BIT MANIPULATION--------------------------------------------------------------------------------------------->


class Solution {
public:
    /*
    Generate all the Subsequences using BIT Manipulation
    Power Set --> Print all Subsequences using BIT MANIPULATION

    TC: O(2^14 * 14 * 15)
    SC: O(26)
    */

    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {

        int n = words.size();

        int maxi = 0;

        vector<int> f(26, 0);

        // store frequency of each letter in letters
        for (int i = 0; i < letters.size(); i++)
            f[letters[i] - 'a']++;

        vector<int> F(26, 0);

        // generate all the subsets of words
        for (int i = 0; i <= (1<<n)-1; i++) {   // changes done here forgot '=' sign  
            
            F.assign(26,0);
            
            for (int j = 0; j < n; j++) {

                if((1<<j)&i){
                // calculating the frequency of letter of each in a subset
                for (int k = 0; k < words[j].size(); k++) {
                    F[words[j][k] - 'a']++;
                }
              }
            }

                // if frequency of any letter in a subset get overflowed 
                bool flag = true;
                for (int i = 0; i < 26; i++) {
                    if (F[i] > f[i]) {
                        flag = false;
                        break;
                    }
                }

                if (flag != false) {
                    int sum = 0;
                    for (int i = 0; i < 26; i++) {
                        sum+=F[i]*score[i];
                    }
                    maxi = max(sum, maxi);
                }
            }
        return maxi;
    }
};





