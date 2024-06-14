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

    Using unsigned long long as here large range of index in '+ve' is required.

*/
    int widthOfBinaryTree(TreeNode* root) {

        if(root==nullptr) return 0;
        if(root->left==nullptr&&root->right==nullptr) return 1;

        queue<pair<TreeNode*,unsigned long long>> q;

        q.push({root,1});
        int maxi = 1;

        while(!q.empty()){

            int n = q.size();  // size of that individual level
            unsigned long long l = 0;
            unsigned long long r = 0;

            // traversing individual level 
            for(int i = 0; i<n; i++){

                TreeNode* node = q.front().first;
                unsigned long long index = q.front().second;
                q.pop();

                if(i==0) l = index;
                if(i==n-1) r = index;

                if(node->left) q.push({node->left,2*index});
                if(node->right) q.push({node->right,2*index+1});
            }

            // find out width of each individual level and find out maximum;
            maxi = max(maxi, static_cast<int> (r-l+1));
        }
        
        return maxi;
    }
};




// <------------------------------------------------------------------------------------------ONLY int---------------------------------------------------------------------------------------------------------------------------------->


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

    int widthOfBinaryTree(TreeNode* root) {

        if(root==nullptr) return 0;
        if(root->left==nullptr&&root->right==nullptr) return 1;

        queue<pair<TreeNode*,int>> q;

        q.push({root,1});
        int maxi = 1;

        while(!q.empty()){

            int n = q.size();  // size of that individual level
            int  l = 0;
            int  r = 0;

            // traversing individual level 
            for(int i = 0; i<n; i++){

                TreeNode* node = q.front().first;
                int index = q.front().second;
                q.pop();

                if(i==0) l = index;
                if(i==n-1) r = index;

                if(node->left) q.push({node->left,2*1LL*index});
                if(node->right) q.push({node->right,2*1LL*index+1});
            }

            // find out width of each individual level and find out maximum;
            maxi = max(maxi, static_cast<int> ((long long )r-l+1));
        }
        
        return maxi;
    }
};
