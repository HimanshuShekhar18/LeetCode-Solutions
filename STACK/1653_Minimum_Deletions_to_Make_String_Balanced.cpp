class Solution {
public:

/*
PrefixB and SuffixA Pre-Computation
TC: O(n)
SC: O(n)
*/
    int minimumDeletions(string s) {

        int n = s.length();
        int countb = 0;
        int counta = 0;
        vector<int> prefixb(n+1,0);
        vector<int> suffixa(n+1,0);
        for(int i = 1; i<=n; i++){

            if(s[i-1]=='b'){
                countb++;
            }
            prefixb[i] = countb;
        }

        for(int i = n-2; i>=0; i--){

            if(s[i+1]=='a'){
                counta++;
            }
            suffixa[i] = counta;
        }
        int ans = INT_MAX;
        for(int i = 0; i<n; i++){
            ans=min(ans,prefixb[i]+suffixa[i]);            
        }
        return ans;
    }
};  


// <----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->


/*
PrefixB and SuffixA Space Optimized
TC: O(n)
SC: O(1)
*/

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int countb = 0;
        int counta = 0;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {

            if (s[i] == 'a') {
                counta++;
            }
        }

        for (int i = 0; i <= n; i++) {

            if (i - 1 >= 0) {
                if (s[i - 1] == 'b') {
                    countb++;
                }
            }

            if (i < n) {
                if (s[i] == 'a') {
                    counta--;
                }
            }

            ans = min(ans, countb + counta);
        }

        return ans;
    }
};



// <------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

/*
STACK --> just delete 'ba'
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        stack<char> st;
        int delete_ba = 0;
        for (int i = 0; i < n; i++) {

            if (s[i] == 'a') {
                if (!st.empty() && st.top() == 'b') {
                    st.pop();
                    delete_ba++;
                } else {
                    st.push(s[i]);
                }
            } else {
                st.push(s[i]);
            }
        }
        return delete_ba;
    } 
};



