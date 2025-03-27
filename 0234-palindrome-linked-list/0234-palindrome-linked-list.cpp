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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* node = head;
        stack<ListNode*>st;
        while(node != nullptr){
            st.push(node);
            node = node->next;
        }
        node = head;
        while(node != nullptr){
            ListNode* ptr = st.top();
            st.pop();
            if(ptr->val != node->val) return false;
            node = node->next;
        }
        return true;
    }
};