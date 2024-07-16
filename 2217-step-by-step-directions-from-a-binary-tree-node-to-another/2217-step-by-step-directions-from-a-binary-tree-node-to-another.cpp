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
    bool getLCA(TreeNode* root,int val,string& ans){
        if(root->val == val) return true;
        if(root->left && getLCA(root->left,val,ans)) ans += "L";
        else if(root->right && getLCA(root->right,val,ans)) ans += "R";
        return !ans.empty();
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string lans = "",rans = "";
        getLCA(root,startValue,lans);
        getLCA(root,destValue,rans);
        while(!lans.empty() && !rans.empty() && lans.back()==rans.back()){
            lans.pop_back();
            rans.pop_back();
        }
        reverse(rans.begin(),rans.end());
        return string(lans.size(),'U') + rans;
    }
};