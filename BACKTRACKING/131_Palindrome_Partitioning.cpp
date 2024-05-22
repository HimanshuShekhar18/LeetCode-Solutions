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

