
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
DFS Traversal
TC: O(n^2) , as visiting each node once
SC: O(n) , as recursive stack space of each node
*/
string result = "";

    void solve(TreeNode* root, string curr){

        if(root==nullptr) return ;

        // O(n) operation
        curr = char(root->val+'a')+curr;

        if(root->left==nullptr && root->right==nullptr) {

            if(result=="" || result>curr){
                result = curr;
            }

            return;
        }

        solve(root->left,curr);
        solve(root->right,curr);

    }
    string smallestFromLeaf(TreeNode* root) {

        solve(root,"");

        return result;
        
    }
};




// <------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->



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
BFS Traversal
TC: O(n^2) , as visiting each node once
SC: O(n) , as queue takes
*/
string result = "";


    string smallestFromLeaf(TreeNode* root) {

        queue<pair<TreeNode*,string>> q;

        q.push({root, string(1,root->val + 'a')});  

        while(!q.empty()){

            auto [node,curr] = q.front();
            q.pop();

            if(node->left==nullptr && node->right==nullptr) {
                if(result=="" || result>curr) result = curr;
            }

            if(node->left){
                // O(n) operations
                q.push({node->left, string(1,node->left->val + 'a') + curr});
            }

            if(node->right){
                q.push({node->right, string(1,node->right->val + 'a') + curr});
            }
        }

        return result;
        
    }
};














