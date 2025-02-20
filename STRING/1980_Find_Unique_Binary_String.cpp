class Solution {
public:

/*
String, Set, and Generate all Strings
TC: O(2^n ∗ n)
SC: O(n)
*/
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = nums.size();
        set<int> s;
        for(int i = 0; i<n; i++){
            int num = 0;
            for(int j=0; j<n; j++){
                if(nums[i][j] == '1') num = num | (1<<(n-1-j));
            }
            s.insert(num);
        }

        int ansnum;
        for(int i = 0; i<(1<<n); i++){
            if(s.find(i)==s.end()){
                ansnum = i;
                break;
            } 
        }

        string ansstring = "";
        for(int i = 0; i<n; i++){
            if((ansnum & (1<<i)) == 0) ansstring = '0'+ansstring;
            else ansstring = '1'+ansstring;
        }
        return ansstring;
    }
};

// <----------------------------------------------------------------------------------------------------------------------------------------------->


class Solution {
public:

/*
Same Optimized Approach String, Set, and Generate all Strings
TC: O(n^2)
SC: O(n)
*/
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = nums.size();
        set<int> s;
        for(int i = 0; i<n; i++){
            int num = 0;
            for(int j=0; j<n; j++){
                if(nums[i][j] == '1') num = num | (1<<(n-1-j));
            }
            s.insert(num);
        }

        int ansnum;
        for(int i = 0; i<=n; i++){
            if(s.find(i)==s.end()){
                ansnum = i;
                break;
            } 
        }

        string ansstring = "";
        for(int i = 0; i<n; i++){
            if((ansnum & (1<<i)) == 0) ansstring = '0'+ansstring;
            else ansstring = '1'+ansstring;
        }
        return ansstring;
    }
};

// <--------------------------------------------------------------------------------------------------------------------------------------------------->


class Solution {
public:

/*
 Cantor's Diagonal Argument
 We know that two strings are different, as long as they differ by at least one character.
 ans will differ from every string in at least one position.
 TC: O(n)
 SC: O(1)
*/
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = nums.size();
        string ansstring = "";
        for(int i = 0; i<n; i++){
            if(nums[i][i]=='0') ansstring+='1';
            else ansstring+='0';
        }
             
        return ansstring;
    }
};



