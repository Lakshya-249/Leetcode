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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        // list<ListNode*>lst;
        ListNode* node = head;
        int len = 1;
        while(node->next){
            // lst.push_back(node);
            len++;
            node = node->next;
        }
        node->next = head;
        ListNode* tail = head;
        k = len - (k % len) - 1;
        while(k){
            tail = tail->next;
            k--;
        }
        head = tail->next;
        tail->next = nullptr;
        return head;
    }
};