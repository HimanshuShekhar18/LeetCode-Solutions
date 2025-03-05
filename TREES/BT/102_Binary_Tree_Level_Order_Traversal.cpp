/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root==NULL) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        q.push(root);
        vector<int> currlevel; 
        while(!q.empty()){
              int currsize = q.size();
              for(int i = 0; i<currsize; i++){
                TreeNode* node = q.front();
                currlevel.push_back(node->val);
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
              }
              ans.push_back(currlevel);  
              currlevel.clear();     
        }
        return ans;
    }
};

