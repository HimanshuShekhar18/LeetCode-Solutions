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
