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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*>st;
        ListNode* node = head;
        while(node != nullptr){
            st.push(node);
            node = node->next;
        }
        ListNode* prev = nullptr;
        while(!st.empty()){
            n--;
            if(n==0){
                st.pop();
                if(st.empty()) head = prev;
                else {
                    ListNode* temp = st.top();
                    temp->next = prev;
                }
                break;
            }
            prev = st.top();
            st.pop();
        }
        return head;
    }
};