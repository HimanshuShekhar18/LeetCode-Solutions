/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
// DFS
    // TC: O(2*E)
    // SC: O(n)+O(n) --> map+stack space
    unordered_map<Node*,Node*> mp;
    void dfs(Node* node, Node* clone_node){
        for(Node* n: node->neighbors){
            if(mp.find(n)==mp.end()){
                Node* clone = new Node(n->val);
                mp[n]=clone;
                clone_node->neighbors.push_back(clone);
                dfs(n,clone);
            }
            else {
                clone_node->neighbors.push_back(mp[n]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
            if(node==NULL) return NULL;
            mp.clear();
            // cloned the given node
            Node* clone_node = new Node(node->val);
            mp[node]=clone_node;
            // Now, clone its neighbors and recursively their neighbors
            /*
            But if a node reappears, then we need to access that cloned made
            So, store them in a map <Node*,Node*>
            */
            dfs(node,clone_node);
            return clone_node;
    }
};



// <-------------------------------------------------------------------------BFS---------------------------------------------------------------------------->



/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // BFS
    // TC: O(2*E)
    // SC: O(n)+O(n)
    unordered_map<Node*,Node*> mp;

    Node* cloneGraph(Node* node) {
            if(node==NULL) return NULL;
            mp.clear();
            // cloned the given node
            Node* clone_node = new Node(node->val);
            mp[node]=clone_node;
            // Now, clone its neighbors and recursively their neighbors
            /*
            But if a node reappears, then we need to access that cloned made
            So, store them in a map <Node*,Node*>
            */
            queue<Node*> q;
            q.push(node);
            while(!q.empty()){

            Node* frontnode = q.front();
            Node* frontclonenode = mp[frontnode];
            q.pop();

            for(Node* n: frontnode->neighbors){
            if(mp.find(n)==mp.end()){
                Node* clone = new Node(n->val);
                mp[n]=clone;
                frontclonenode->neighbors.push_back(clone);
                q.push(n);
            }
            else {
                frontclonenode->neighbors.push_back(mp[n]);
            }
        }
    }
            return clone_node;
    }
};



