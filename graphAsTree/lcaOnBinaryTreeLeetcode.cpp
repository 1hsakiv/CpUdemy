#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
 

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution {
public:
    unordered_map <TreeNode*,int> depth;
    unordered_map <TreeNode*,TreeNode*> parent;

    TreeNode *lca(TreeNode *u , TreeNode *v){
        if(u == v) return u;
        if(depth[u] < depth[v]) swap(u ,v);

        int diff = depth[u] - depth[v];

        while(diff--){
            u = parent[u];
        }

        while(u != v){
            u = parent[u];
            v = parent[v];
        }

        return u;
    }

    void dfs(TreeNode *root , TreeNode *par){
        if(root == NULL) return;
        depth[root] = depth[par] + 1;
        parent[root] = par;

        if(root->left){
            dfs(root->left , root);
        }
        if(root->right){
            dfs(root->right, root);
        }
        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root , NULL);
        return lca(p,q);
    }
};

int main(){

    return 0;
}