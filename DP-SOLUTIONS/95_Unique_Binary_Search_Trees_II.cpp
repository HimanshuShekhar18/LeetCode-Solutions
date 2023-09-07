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

// RECURSION+MEMOIZATION

// G(n) = 4^n/n^1.5
// TC: O(n*(4^n/n^1.5)) = n * Catalan numbers = n * (no. of BST can be constructed having n nodes considering only one node as root) 
// TC = O(4^n/√n)

// SPACE COMPLEXITY: ∑(n−k+1)⋅4^k/√k from k=1 to n;

/* We use some space for the recursion call stack, but the majority of the space used by the algorithm is storing the lists of BSTs in memo. Let's analyze how many nodes are stored in memo.

The number of nodes in a range [start,end] is end-start+1. Let k=end−start+1 represent this formula.

There are n states [start,end] with one node, that is k=1

There are n−1 states []start, end] with two nodes, that is k=2

There are n−2 states start, end with three nodes, that is k=3

This continues until there is only one state with n nodes (the original input). In general, a value of k has n−k+1 states.

For a given state with value k, there are G(k)=4^k/k^1.5 =  BSTs. Each of these BSTs has k nodes, and thus takes up k⋅G(k)= 4^k/√k space in memo.

A given value k has n−k+1 states and thus takes up (n−k+1)⋅4^k/√k space. In our algorithm, k ranges from 1 to n.

The space complexity is the summation for all values of k = ∑(n−k+1)⋅4^k/√k from k=1 to n;
 
*/

class Solution {
public:

    map<pair<int,int>,vector<TreeNode*>> dp;

    vector<TreeNode*> solve(int start, int end){
        if(start>end) {
            return {nullptr};
        }

        if(dp.find({start,end})!=dp.end()){
            return dp[{start,end}];
        }

        if(start==end){
            TreeNode *root = new TreeNode(start);
            return dp[{start,end}]  =  {root};
        }

        vector<TreeNode*> result;
        for(int i = start; i<=end; i++){
            vector<TreeNode*> left_bst =  solve(start,i-1);
            vector<TreeNode*> right_bst = solve(i+1,end);

            
            for(TreeNode* left: left_bst){
                for(TreeNode* right: right_bst){

                        TreeNode* root = new TreeNode(i);

                        root->left = left;
                        root->right = right;

                        result.push_back(root);
                }
             
            }            
        }

        return dp[{start,end}]=result;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};




// <-----------------------------------------------------------------  TABULATION   ------------------------------------------------------------------->

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

// TABULATION

// G(n) = 4^n/n^1.5
// TC: O(n*(4^n/n^1.5)) = n * Catalan numbers = n * (no. of BST can be constructed having n nodes considering only one node as root) 
// TC = O(4^n/√n)

// SPACE COMPLEXITY: ∑(n−k+1)⋅4^k/√k from k=1 to n;

/* We use some space for the recursion call stack, but the majority of the space used by the algorithm is storing the lists of BSTs in memo. Let's analyze how many nodes are stored in memo.

The number of nodes in a range [start,end] is end-start+1. Let k=end−start+1 represent this formula.

There are n states [start,end] with one node, that is k=1

There are n−1 states []start, end] with two nodes, that is k=2

There are n−2 states start, end with three nodes, that is k=3

This continues until there is only one state with n nodes (the original input). In general, a value of k has n−k+1 states.

For a given state with value k, there are G(k)=4^k/k^1.5 =  BSTs. Each of these BSTs has k nodes, and thus takes up k⋅G(k)= 4^k/√k space in memo.

A given value k has n−k+1 states and thus takes up (n−k+1)⋅4^k/√k space. In our algorithm, k ranges from 1 to n.

The space complexity is the summation for all values of k = ∑(n−k+1)⋅4^k/√k from k=1 to n;
 
*/



class Solution {
public:

    vector<TreeNode*> generateTrees(int n) {

vector<vector<vector<TreeNode*>>> dp(10,vector<vector<TreeNode*>>(10));

        for(int i = 1; i<=n; i++){
            dp[i][i].push_back(new TreeNode(i));
        }


        for(int block = 2; block<=n; block++){
            for(int start = 1; start<=n-block+1;start++){
                int end = start+block-1;

                for(int i = start; i<=end; i++){

                   vector<TreeNode*> left_bst = (i-1>=start)? dp[start][i-1] : vector<TreeNode*>{nullptr}; 
                   vector<TreeNode*> right_bst = (i+1<=end)? dp[i+1][end] : vector<TreeNode*>{nullptr};

                   for(TreeNode* left: left_bst){
                      for(TreeNode* right: right_bst){

                        TreeNode* root = new TreeNode(i);

                        root->left = left;
                        root->right = right;

                        dp[start][end].push_back(root);
                    }
                }
            }
        }
     }

     return dp[1][n];
  }
};
