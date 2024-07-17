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
    TreeNode* traversal(TreeNode* root,vector<TreeNode*>&mpp,set<int>num,bool nflag){
        if(root == nullptr) return nullptr;
        bool flag = num.find(root->val) != num.end();
        if(!flag && nflag) mpp.push_back(root);
        root->left = traversal(root->left,mpp,num,flag);
        root->right = traversal(root->right,mpp,num,flag);
        return flag ? nullptr : root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        TreeNode* Node = root;
        vector<TreeNode*> ans;
        set<int>st;
        for(auto it:to_delete) st.insert(it);
        traversal(Node,ans,st,true); 
        return ans;
    }
};