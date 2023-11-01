
// <-----------------------------------------------------------With Extra Space SC: O(n)------------------------------------------------------------------------------->


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

    unordered_map<int,int> mp;


    void inorder(TreeNode *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // LNR
    inorder(root->left);
    mp[root->val]++;
    inorder(root->right);
}

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        int maxfreq = 0;
        vector<int> ans;
        for(auto it: mp){
            int freq = it.second;
            if(freq>maxfreq){
                maxfreq=freq;
                ans.clear();
                ans.push_back(it.first);
            }
            else if(freq==maxfreq){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};



// <----------------------------------------------------------- Without Using Extra Space SC: O(1) ---------------------------------------------------------------------------->



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

// Without using Auxillary Extra Space 
// SC: O(1)
// TC: O(n)

   vector<int> ans;
   int currNum = 0;
   int freq = 0;
   int maxfreq = 0;


    void inorder(TreeNode *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // LNR
    inorder(root->left);

    if(root->val==currNum){
        freq++;
    }
    else {
        currNum = root->val;
        freq=1;
    }

     if(freq>maxfreq){
                maxfreq=freq;
                ans.clear();
                ans.push_back(currNum);
            }
            else if(freq==maxfreq){
                ans.push_back(currNum);
            }
    inorder(root->right);
}

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
