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
        if (head == nullptr || head->next == nullptr) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        stack<int> st;
        while (fast != nullptr && fast->next != nullptr) {
            st.push(slow->val); 
            slow = slow->next;  
            fast = fast->next->next; 
        }
        if (fast != nullptr) slow = slow->next;
        while (slow != nullptr) {
            if (st.empty() || st.top() != slow->val) {
                return false;
            }
            st.pop();
            slow = slow->next;
        }
        return st.empty();
    }
};