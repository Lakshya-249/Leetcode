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
    ListNode* tail = nullptr;
    ListNode* reverseN(ListNode* prev,ListNode* node,int k){
        if(k == 0) {
            tail = node;
            return prev;
        }
        if(node == nullptr) {
            tail = nullptr;
            return nullptr;
        }
        ListNode* temp = node->next;
        node->next = prev;
        return reverseN(node,temp,k-1);
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        ListNode* ans = new ListNode(0);
        ListNode* dummy = ans;
        while(node != nullptr){
            int cnt = 0;
            ListNode* temp = node;
            while (temp && cnt < k) {
                temp = temp->next;
                cnt++;
            }
            temp = node;
            if(cnt == k){
                ListNode* rev = reverseN(nullptr, node, k);
                dummy->next = rev;
                dummy = temp;
                node = tail;
            }else {
                dummy->next = temp;

                node = nullptr;
            }
            
        }
        return ans->next;

    }
};