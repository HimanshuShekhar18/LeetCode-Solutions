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

 /*


 The tip to solve is think if you're the current_node and you ask your left_subtree and your right_subtree, how many coins do you guys 
 want from me or I can take from you. Where do you start from to guarantee one coin each? Leaf nodes obviously. So, a post order  
 traversal in hiding. (LRP)

 Then think, what should the root node be returning to it's own parent? I gotta keep only one, right? Rest, it cannot give to it's     
 child, so it pushes it off to it's parent. (i.e. node.val + left + right - 1)


 */
class Solution {
public:

int count = 0;

    int solve(TreeNode* root){

        if(root->left==nullptr && root->right==nullptr){

                return root->val-1;

        }

        int left = 0, right = 0;

        if(root->left!=nullptr){
            left = solve(root->left);
            cout << left << endl;
        }

        if(root->right!=nullptr){
            right=solve(root->right);
        }

        count+=abs(left)+abs(right);


        return root->val+left+right-1;

    }

    int distributeCoins(TreeNode* root) {

        solve(root);

        return count;
        
    }
};

