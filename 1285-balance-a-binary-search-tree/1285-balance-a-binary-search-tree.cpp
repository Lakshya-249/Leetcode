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
    void traversal(TreeNode* root,vector<int>&arr){
        if(root == nullptr) return;
        traversal(root->left,arr);
        arr.push_back(root->val);
        traversal(root->right,arr);
    }

    void binaryPartition(TreeNode* &node,int low,int high,vector<int>arr){
        if(low>high) return;
        int mid = (low+high)/2;
        node = new TreeNode(arr[mid]);
        binaryPartition(node->left,low,mid-1,arr);
        binaryPartition(node->right,mid+1,high,arr);
        return;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        traversal(root,arr);
        TreeNode* node = nullptr;
        int h = arr.size() - 1;
        binaryPartition(node,0,h,arr);
        return node;
    }
};