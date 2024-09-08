/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool traverse(ListNode* head,ListNode* cur,TreeNode* root){
        if(cur == nullptr) return true;
        if(root == nullptr) return false;
        if(cur->val == root->val){
            cur = cur->next;
        }else if(head->val == root->val){
            head = head->next;
        }else{
            cur = head;
        }

        return traverse(head,cur,root->left) || traverse(head,cur,root->right);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return traverse(head,head,root);
    }
};