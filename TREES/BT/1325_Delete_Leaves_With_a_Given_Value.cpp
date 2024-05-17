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

    void solve(TreeNode* &root, int target){

        if(root->right == NULL && root->left==NULL){
                if(root->val==target){
                    root=NULL;
                    return;
                }
                else return;
        }

        if(root->left!=NULL){
            solve(root->left,target);
        }
 
        if(root->right!=NULL)
            solve(root->right,target);

        if(root->left==NULL && root->right==NULL){
            if(root->val==target) root=NULL;
        }

        return;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {

    solve(root,target);

    return root;

    }
};


// <----------------------------------------------------------------ITERATIVE POST ORDER TRAVERSAL-------------------------------------------------------------------------------------->



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

Iterative Post Order Traversal

*/
    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        stack<TreeNode*> st;

        TreeNode* currnode = root;

        TreeNode* LastRightNode = nullptr;

        while( !st.empty() || currnode!=nullptr ){


                    while(currnode!=nullptr){
                        st.push(currnode);
                        currnode = currnode->left;
                    }

                    currnode = st.top();

                    // to check whether right child exist or not and if exist is not equal to Last Visited Right Child.
                    if(currnode->right && currnode->right!=LastRightNode){
                            
                            currnode = currnode->right;
                            continue;
                    }

                    st.pop();

                    

                    if(currnode->left== nullptr && currnode->right==nullptr && currnode->val == target) {

                            if(st.empty()) return nullptr;

                            TreeNode* parent = st.top();

                         

                            if(parent->left==currnode){
                                parent->left=nullptr;
                            }
                            else{
                                parent->right=nullptr;
                            }
                    }

                    LastRightNode=currnode;

                    currnode = nullptr;
        }

        return root;
    }
};


