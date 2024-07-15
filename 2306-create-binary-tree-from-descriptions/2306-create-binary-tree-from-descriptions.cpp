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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mpp;
        int n = descriptions.size();
        for(auto it: descriptions){
            if(mpp.find(it[1])==mpp.end()) mpp[it[1]] = new TreeNode(it[1]);
        }
        TreeNode* root;
        for(auto it: descriptions){
            if(mpp.find(it[0])==mpp.end()) {
                mpp[it[0]] = new TreeNode(it[0]);
                root = mpp[it[0]];
            }
            if(it[2]) mpp[it[0]]->left = mpp[it[1]];
            else mpp[it[0]]->right = mpp[it[1]];
        }
        return root;
    }
};