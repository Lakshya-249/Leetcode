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
        // stack<ListNode*>st;
        // ListNode* node = head;
        // while(node != nullptr){
        //     st.push(node);
        //     node = node->next;
        // }
        // ListNode* prev = nullptr;
        // while(!st.empty()){
        //     n--;
        //     if(n==0){
        //         st.pop();
        //         if(st.empty()) head = prev;
        //         else {
        //             ListNode* temp = st.top();
        //             temp->next = prev;
        //         }
        //         break;
        //     }
        //     prev = st.top();
        //     st.pop();
        // }
        // return head;
        ListNode* dnode = new ListNode(0, head);
        ListNode* ans = dnode;
        for (int i=0; i<n; i++) head = head->next;
        while(head != nullptr){
            dnode = dnode->next;
            head = head->next;
        }
        dnode->next = dnode->next->next;
        return ans->next;
    }
};