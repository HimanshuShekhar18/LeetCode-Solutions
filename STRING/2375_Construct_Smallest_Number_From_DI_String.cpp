class Solution {
public:
/*
String Implementation and Set
TC: O( n*(log(n) + log(n) ) , log(n) for to_string() and st.erase()
SC: O(10)
*/
    string smallestNumber(string pattern) {
        set<int> st;
        int n = pattern.length();
        int lastInumber = 0;
        string ans = "";
        vector<int> countD(n,0);
        for(int i = n-1; i>=0; i--){
            if(pattern[i]=='D'){
                if(i!=n-1) countD[i]=1+countD[i+1];
                else countD[i]=1;
            }
            else countD[i]=0;
        }

        for(int i = 1; i<10; i++){
            st.insert(i);
        }

        for(int i = 0; i<n; i++){
            if(pattern[i]=='I') {
                ans+= to_string((*st.begin()));
                st.erase(*st.begin());
            }
            else{
                int number = *st.begin()+countD[i];
                st.erase(number);
                ans+=to_string(number);
            }
        }
        ans+=to_string(*st.begin());
        return ans;
    }
};
