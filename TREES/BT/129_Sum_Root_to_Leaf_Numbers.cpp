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

    int result = 0;

    void solve(TreeNode* root, string curr){
        if(root==nullptr) return;

        curr=curr+to_string(root->val);

        if(root->left==nullptr && root->right==nullptr){
            result+=stoi(curr);
        }

        solve(root->left,curr);
        solve(root->right,curr);
    }

    int sumNumbers(TreeNode* root) {

        solve(root,"");

        return result;
        
    }
};


// <----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->



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

    int result = 0;

    void solve(TreeNode* root, int curr){
        if(root==nullptr) return;

        curr=10*curr+root->val;

        if(root->left==nullptr && root->right==nullptr){
            result+=curr;
            return;
        }

        solve(root->left,curr);
        solve(root->right,curr);
    }

    int sumNumbers(TreeNode* root) {

        solve(root,0);

        return result;
        
    }
};











