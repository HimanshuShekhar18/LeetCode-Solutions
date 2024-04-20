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

    bool solve(TreeNode* root, int curr, int targetSum){

        if(root->left==nullptr && root->right == nullptr){
            cout << curr << endl;
            if(curr==targetSum) return true;
            else return false;
        }

        bool left = false;
        if(root->left != nullptr) {
            left = solve(root->left,curr+root->left->val,targetSum);
        }
        bool right = false;
        if(root->right != nullptr) {
            right = solve(root->right,curr+root->right->val,targetSum);
        }

        return right || left;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root==nullptr) return false;

        return solve(root,root->val, targetSum);
        
    }
};
