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
    ListNode* reverseL(ListNode* prev, ListNode* node){
        if(node == nullptr){
            return prev;
        }
        ListNode* temp = node->next;
        node->next = prev;
        return reverseL(node, temp);
    }
public:
    ListNode* reverseList(ListNode* head) {
        // ListNode* prev = nullptr;
        // ListNode* curr = head;
        // while(curr != nullptr){
        //     ListNode* temp = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     head = curr;
        //     curr = temp;
        // }
        ListNode* node = reverseL(nullptr, head);
        return node;
    }
};