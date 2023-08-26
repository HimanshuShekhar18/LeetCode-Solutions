class Solution {
public:

// NOTE --> Question is very similar to 733. Flood Fill Algorithm

// DFS --> Flood Fill Algorithm+Backtracking
// TC: O(4^m*n)*O(m*n) ~ O(4^6)*O(6*6) ~ O(603979776) ~ 6 * 10^8
// SC: O(4^m*n)*O(m*n) ~ O(4^6)*O(6*6) ~ O(603979776) ~ 6 * 10^8

    vector<vector<int>> movements = {{-1,0},{1,0},{0,-1},{0,1}};
    int n, m;
    bool dfs(int i, int j, vector<vector<char>>& board, string &word,int index, vector<vector<bool>> &vis){
        if(index==word.length()) return true;
        if (i<0 || i>=n || j<0 || j>=m || vis[i][j] || board[i][j]!=word[index]) return false;
        vis[i][j]=1; 
        if(dfs(i + 1, j, board, word, index+1, vis) || dfs(i - 1, j, board, word, index+1, vis) || dfs(i, j + 1, board, word, index+1, vis) || dfs(i, j - 1, board, word, index+1, vis))
        return true;
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        vector<pair<int,int>> vect;
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> vis(n+1, vector<bool>(m+1, false)); 
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
            if(dfs(i,j,board,word,0,vis)) return true;   
            }
        }        
        return false;
    }
};
