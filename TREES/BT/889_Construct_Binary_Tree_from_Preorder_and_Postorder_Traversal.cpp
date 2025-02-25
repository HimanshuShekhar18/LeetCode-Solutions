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

    /*
     unordered_map, preindexstart and preindexend range, leftsubtree and rightsubtree construction using Recursion
     TC: O(n)
     SC: O(n)
    */

    TreeNode* construct(int preindex, int postindex, vector<int> &preorder, vector<int>& postorder, unordered_map<int,int> mp){

        if(preindex>=preorder.size()) return nullptr;

        if(mp[preorder[preindex]]==postindex) {
            return new TreeNode(preorder[preindex]);
        }

        TreeNode *node = new TreeNode(preorder[preindex]);
        int preindexstart = preindex;
        int preindexend = preindex+mp[preorder[preindex]]-postindex;

        // left subtree
        if(preindex+1<=preindexend)
        node->left = construct(preindex+1, postindex, preorder, postorder, mp);

        // right subtree
        if(preindex+1<preorder.size() && (preindex+1+(mp[preorder[preindex+1]]-postindex+1)) <= preindexend)
        node->right = construct(preindex+1+(mp[preorder[preindex+1]]-postindex+1), mp[preorder[preindex+1]]+1,preorder, postorder, mp);
        
        return node;

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        if(preorder.size()==1) return new TreeNode(preorder[0]);
        unordered_map<int,int> mp;

        for(int i = 0; i<postorder.size(); i++){
            mp[postorder[i]]=i;
        }

        return construct(0,0,preorder,postorder,mp);
    }
};

