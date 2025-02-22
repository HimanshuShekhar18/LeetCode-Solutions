
/*
Khandani Recursion and Backtracking and Set Similar as  46. Permutations and 47. Permutations II  
TC: O(n*n!)  Total Permutation = n! and Operation in each path to reach that final node = n 
SC: O(n*n!)  Stack Space = n  and elements stored in Set
*/

class Solution {
public:

    unordered_set<int> s;
    set<vector<char>> ans;
    void backtracking(int n, string tiles, vector<char> &curr){
        if(curr.size()>0) {
            ans.insert(curr);
        }

        for(int i = 0; i<n; i++){
            if(s.find(i)!=s.end()) continue;
            curr.push_back(tiles[i]);
            s.insert(i);
            backtracking(n,tiles,curr);
            curr.pop_back();
            s.erase(i);
        }
    }

    int numTilePossibilities(string tiles) {
        int n = tiles.length();
        vector<char> curr;
        backtracking(n,tiles,curr);
        return ans.size();
    }
};
