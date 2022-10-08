/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*>mp;
    unordered_set<TreeNode*>vis;
    
    void connectWithParents(TreeNode* root, TreeNode* parent){
        if(root == NULL) return ;
        
        mp[root]= parent;
        connectWithParents(root-> left, root);
        connectWithParents(root-> right, root);
        
    }
    
    void dfs (TreeNode *target, int k, vector<int>&res){
        if(target == NULL) return;
        if(vis.count(target)== true) return;
        vis.insert(target);
        
        if(k==0){
            res.push_back(target->val);
            return;
        }
        
        dfs(target->left, k-1,res);
        dfs(target->right, k-1,res);
        dfs(mp[target],k-1,res);
        
        
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        if(root == NULL) return res;
        connectWithParents(root,NULL);
        dfs(target, k , res);
        return res;
    }
};