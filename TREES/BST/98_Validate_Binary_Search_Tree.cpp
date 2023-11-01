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


// TC: O(n)
// SC: O(n) 

      vector<int> ans;
   int currNum = 0;
   int freq = 0;
   int maxfreq = 0;

    void inorder(TreeNode* root){
        if(root==NULL) return;

        inorder(root->left);

        if(root->val==currNum){
        freq++;
    }
    else {
        currNum = root->val;
        freq=1;
    }

     if(freq>=maxfreq){
                maxfreq=freq;
    }
        ans.push_back(root->val);
        inorder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        inorder(root);
        if(is_sorted(ans.begin(),ans.end())){

            if(maxfreq>1) return false;
            return true;
        } 
        else return false;
    }
};





// <---------------------------------------------------------------------------LITTLE SPACE OPTIMIZED--------------------------------------------------------------------------------->




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

// TC: O(n)
// SC: O(depth of tree) 

   bool isBST(TreeNode *root, long long  min = LLONG_MIN, long long  max = LLONG_MAX)
{

    // base case
    if (root == NULL)
    {
        return true;
    }

    if (root->val > min && root->val < max)
    {
        bool left = isBST(root->left, min, root->val);
        bool right = isBST(root->right, root->val, max);
        return left && right;
    }
    else
    {
        return false;
    }
}

    bool isValidBST(TreeNode* root) {
        return isBST(root);
    }
};




