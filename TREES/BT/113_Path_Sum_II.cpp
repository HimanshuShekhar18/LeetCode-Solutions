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

    vector<vector<int>> ans;

    void solve(vector<int> &store, TreeNode* root, int curr, int targetSum){
        if(root->left==nullptr && root->right==nullptr){
            if(curr==targetSum) {
                ans.push_back(store);
            }
            return;
        }

        if(root->left!=nullptr){
            store.push_back(root->left->val);
            solve(store,root->left,curr+root->left->val,targetSum);
            store.pop_back();
        }
        if(root->right!=nullptr){
            store.push_back(root->right->val);
            solve(store,root->right,curr+root->right->val,targetSum);
            store.pop_back();
        }

        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        if(root==nullptr) return {};

        vector<int> store;
        store.push_back(root->val);
    
        solve(store,root,root->val,targetSum);

        return ans;
        
    }
};
