class Solution {
public:

    // don't use vector<vector<int>> --> TLE aata hain
    vector<pair<int,int>> movements = {{-1,0},{1,0},{0,-1},{0,1}};
    int vis[7][7];
    int n, m;
    bool dfs(int i, int j, vector<vector<char>>& board, string word,int index){
        if(index==word.size()-1) return board[i][j]==word[index];
        vis[i][j]=1;
         for(auto movement: movements ){
            int child_x = i+movement.first;
            int child_y = j+movement.second;
            if (child_x<0 || child_x>=n || child_y<0 || child_y>=m) continue;
            if(vis[child_x][child_y]==0 && board[child_x][child_y]==word[index+1]){
                if(dfs(child_x,child_y,board,word,index+1)==true) return true;
               
            }
        }
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        vector<pair<int,int>> vect;
        n = board.size();
        m = board[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j]==word[0]) vect.push_back({i,j});
            }
        }       

        for(int i = 0; i<vect.size(); i++){
            if(dfs(vect[i].first,vect[i].second,board,word,0)) return true;
        }
        return false;
    }
};
