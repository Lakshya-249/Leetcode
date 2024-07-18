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
    vector<int> traversal(TreeNode *root,int distance,int &ans){
        if(root == nullptr){
            return {};
        }
        if(root->left==nullptr && root->right==nullptr){
            return {1};
        }
        vector<int> left = traversal(root->left,distance,ans);
        vector<int> right = traversal(root->right,distance,ans);

        for(auto x: left){
            for(auto y: right){
                ans = x+y<=distance ? ++ans : ans; 
            }
        }

        vector<int> vec;
        for(auto it: left){
            if(it+1<=distance) vec.push_back(it+1);
        }
        for(auto it: right){
            if(it+1<=distance) vec.push_back(it+1);
        }

        return vec;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        traversal(root,distance,ans);
        return ans;
    }
};